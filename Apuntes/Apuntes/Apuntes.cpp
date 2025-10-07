#include <iostream>

#include "TutorialThreads/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include "3NodeMap/NodeMap.h"
#include "InputSytem/InputSystem.h"

class Tree : public INodeContent
{
	void Draw(Vector2 offset) override
	{
		CC::Lock();
		CC::SetColor(CC::DARKGREEN, CC::BLACK);
		CC::SetPosition(offset.X, offset.Y);
		std::cout << "T";

		CC::Unlock();
	}
};

int main()
{
	/*InputSystem* iS = new InputSystem();

	InputSystem::KeyBinding* kb = iS->AddListener(K_1, []() {
		CC::Lock();
		std::cout << "Pressed 1" << std::endl;
		CC::Unlock();
		});

	iS->StartListen();

	while (true)
	{

	}*/

	NodeMap* myMap = new NodeMap(Vector2(20, 20), Vector2(2, 2));

	Tree* t1 = new Tree();
	Tree* t2 = new Tree();
	Tree* t3 = new Tree();
	Tree* t4 = new Tree();
	Tree* t5 = new Tree();
	
	myMap->SafePickNode(Vector2(0, 0), [t1](Node* node) {
		node->SetContent(t1);
		});
	myMap->SafePickNode(Vector2(0, 19), [t2](Node* node) {
		node->SetContent(t2);
		});
	myMap->SafePickNode(Vector2(19, 0), [t3](Node* node) {
		node->SetContent(t3);
		});
	myMap->SafePickNode(Vector2(19, 19), [t4](Node* node) {
		node->SetContent(t4);
		});
	myMap->SafePickNode(Vector2(10, 10), [t5](Node* node) {
		node->SetContent(t5);
		});

	myMap->UnSafeDraw();

	InputSystem* iS = new InputSystem();

	iS->AddListener(K_UP, [myMap]() {
			
		std::list<Vector2> positions;
		positions.push_back(Vector2(10, 10));
		positions.push_back(Vector2(10, 9));
		myMap->SafeMultiPickNode(positions, [](std::list<Node*> nodes) {
			std::list<Node*>::iterator it = nodes.begin();
			
			Node* n1 = *it;
			it++;
			Node* n2 = *it;
			
			n2->SetContent(n1->GetContent());
			n1->SetContent(nullptr);

			n1->DrawContent(Vector2(2, 2));
			n2->DrawContent(Vector2(2, 2));
			});
		});
	iS->StartListen();

	while (true)
	{

	}
}

