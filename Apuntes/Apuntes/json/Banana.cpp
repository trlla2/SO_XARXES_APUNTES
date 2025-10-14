#include "Banana.h"

Json::Value Banana::Code()
{
	Json::Value json = Fruta::Code();

	json["bananidad"] = bananidad;
	//json[DeceodeKey()] = typeid(Banana).name();

	ICodable::CodeSubClassType<Banana>(json);

	return json;
}

void Banana::Decode(Json::Value json)
{
	Fruta::Decode(json);
	bananidad = json["bananidad"].asInt();
}
