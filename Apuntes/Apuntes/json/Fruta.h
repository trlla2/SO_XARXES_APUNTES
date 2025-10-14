#pragma once
#include <string>
#include "ICodable.h"
class Fruta : public ICodable
{
public:

	unsigned int semillas = 0;
	std::string hexDelColor = "";

	Json::Value Code() override;

	virtual void Decode(Json::Value json) override;
};

