#include "Manzana.h"
Json::Value Manzana::Code()
{
	Json::Value json = Fruta::Code();

	json["manzanidad"] = manzanidad;

	ICodable::CodeSubClassType<Manzana>(json);

	return json;
}

void Manzana::Decode(Json::Value json)
{
	Fruta::Decode(json);
	manzanidad = json["manzanidad"].asInt();
}
