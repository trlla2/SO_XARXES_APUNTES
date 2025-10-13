#include <iostream>
#include <json/json.h>
#include <fstream>

#include "TutorialThreads/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include "3NodeMap/NodeMap.h"
#include "InputSytem/InputSystem.h"

class Player // : Codeable -> Serializable + Desearizable
{
public:
	int life = 0;
	std::string name = "Test Plater";
	unsigned int coins = 0;

	Player(){}
	~Player(){}

	void Decode(Json::Value json) // DesSerialize
	{
		life = json["life"].asInt();
		name = json["name"].asString();
		coins = json["coins"].asUInt();

	}

	Json::Value Encode() // Serialize 
	{
		Json::Value json;

		json["life"] = life;
		json["name"] = name;
		json["coins"] = coins;


		return json;
	}
};


int main()
{
	Player* player = new Player();
	player->coins = 3;
	player->life = 19;
	player->name = "Lmao";

	Json::Value newJson;

	newJson["Player"] = player->Encode();

	std::ostream* jsonFile = new std::ofstream 

	while (true)
	{

	}
}

