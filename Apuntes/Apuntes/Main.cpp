#include <iostream>
#include <json/json.h>
#include <fstream>

#include "TutorialThreads/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include "3NodeMap/NodeMap.h"
#include "InputSytem/InputSystem.h"
#include "json/ICodable.h"
#include "json/Banana.h"
#include "json/Manzana.h"

int main()
{
	ICodable::SaveDecodeProcces<Banana>();
	ICodable::SaveDecodeProcces<Manzana>();

	std::vector<Fruta*> frutas
	{
		new Banana(),
		new Banana(),
		new Manzana(),
		new Manzana()
	};

	frutas[1]->semillas = 10000;

	Json::Value jsonArray = Json::Value(Json::arrayValue);

	for(Fruta* fruta : frutas)
	{
		jsonArray.append(fruta->Code());
	}

	std::ofstream jsonWriterFile = std::ofstream("FrutasTest.json", std::ifstream::binary);

	if (!jsonWriterFile.fail()) 
	{
		jsonWriterFile << jsonArray;
		jsonWriterFile.close();
	}

	std::ifstream jsonReadFile = std::ifstream("FrutasTest.json", std::ifstream::binary);
	std::vector<Fruta*> readFrutas;

	if (!jsonReadFile.fail()) 
	{
		Json::Value readedJson;

		jsonReadFile >> readedJson;

		for (Json::Value value : readedJson)
		{
			Fruta* f = ICodable::FromJson<Fruta>(value);
			readFrutas.push_back(f);
		}
	}

	while (true)
	{

	}
}

