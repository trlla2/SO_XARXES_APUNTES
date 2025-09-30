#pragma once
#include "InputsConsts.h"
#include <list>
#include <map>
#include <mutex>
#include <thread>
#include <functional>

class InputSystem
{
public:

	class KeyBinding 
	{
		friend class InputSystem;
	public:
		typedef std::function<void()> OnKeyPress;

	private:
		int _key;
		OnKeyPress _onKeyPress;

		KeyBinding(int key, OnKeyPress onKeyPress);
		~KeyBinding();
	};

	typedef std::list<KeyBinding*> KeyBindingList;
	typedef std::map<int, KeyBindingList> KeyBindingMap;

public:
	InputSystem();
	~InputSystem();

	KeyBinding* AddListener(int key, KeyBinding::OnKeyPress onKeyPress);
	void RemoveAndDeleteListener(KeyBinding* keyBinding);

	void StartListen();
	void StopListen();

private:
	enum State
	{
		Starting = 0,
		Listeing = 1,
		Stopping = 2,
		Stopped = 3
	};

	State _state = Stopped;

	std::mutex _classMutex;
	KeyBindingMap _keyBindingMap;

	void ListenLoop();
};

