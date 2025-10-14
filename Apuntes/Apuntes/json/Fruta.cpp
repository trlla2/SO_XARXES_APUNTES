#include "Fruta.h"

Json::Value Fruta::Code()
{
	Json::Value json;

	json["semillas"] = semillas;
	json["hexDelColor"] = hexDelColor;

	return json;
}


void Fruta::Decode(Json::Value json) 
{
	semillas = json["semillas"].asInt();
	hexDelColor = json["hexDelColor"].asString();
}