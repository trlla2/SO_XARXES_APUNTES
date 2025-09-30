#include "InputSystem.h"
#include "../Utils/ConsoleControl.h"

InputSystem::KeyBinding::KeyBinding(int key, OnKeyPress onKeyPress)
{
	_key = key;
	_onKeyPress = onKeyPress;
}

InputSystem::KeyBinding::~KeyBinding()
{

}

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
	for (std::pair<int, KeyBindingList> pair : _keyBindingMap)
	{
		KeyBindingList bindingList = pair.second;
		for (KeyBinding* binding : bindingList)
		{
			delete binding;
		}

		bindingList.clear();
	}
	_keyBindingMap.clear();
}

InputSystem::KeyBinding* InputSystem::AddListener(int key, KeyBinding::OnKeyPress onKeyPress)
{
	_classMutex.lock();

	if (_keyBindingMap.find(key) == _keyBindingMap.end())
	{
		_keyBindingMap[key] = KeyBindingList();
	}

	KeyBinding* keyBinding = new KeyBinding(key, onKeyPress);
	_keyBindingMap[key].push_back(keyBinding);

	_classMutex.unlock();

	return keyBinding;
}

void InputSystem::RemoveAndDeleteListener(KeyBinding* keyBinding)
{
	int key = keyBinding->_key;
	_classMutex.lock();
	
	if (_keyBindingMap.find(key) != _keyBindingMap.end())
	{
		KeyBindingList list = _keyBindingMap[key];
		list.remove(keyBinding);
		delete keyBinding;

		if (list.size() == 0)
		{
			_keyBindingMap.erase(key);
		}
	}

	_classMutex.unlock();
}

void InputSystem::StartListen()
{
	_classMutex.lock();

	if (_state != Stopped) {
		_classMutex.unlock();
		return;
	}

	_state = Starting;

	std::thread* listenLoopThread = new std::thread(&InputSystem::ListenLoop, this);
	listenLoopThread->detach();

	_classMutex.unlock();
}

void InputSystem::StopListen()
{
	_classMutex.lock();

	if (_state != Listeing)
	{
		_classMutex.unlock();
	}

	_state = Stopping;

	_classMutex.unlock();
}

void InputSystem::ListenLoop()
{
	_classMutex.lock();

	_state = Listeing;
	State currentState = _state;
	CC::ClearKeyBuffer();

	_classMutex.unlock();

	while (currentState == Listeing) // Mira el state guardado para ser thread safe
	{
		int key = CC::ReadNextKey();

		if (key != 0) 
		{
			_classMutex.lock();

			if (_keyBindingMap.find(key) != _keyBindingMap.end())
			{

				KeyBindingList list = _keyBindingMap[key];

				for (KeyBinding* binding : list)
				{
					std::thread* onKeyPressedThread = new std::thread(binding->_onKeyPress);
					onKeyPressedThread->detach(); // Se envia a otro thread para evitar deadlock(tener un lock dentro de ontro lock)
				}
			}

			_classMutex.unlock();
		}

		_classMutex.lock();
		currentState = _state; // Update state
		_classMutex.unlock();
	}

	_classMutex.lock();

	if (_state == Stopping)
	{
		_state = Stopped;
	}

	_classMutex.unlock();
}
