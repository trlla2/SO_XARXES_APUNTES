#include "ICodable.h"

std::string ICodable::DeceodeKey()
{
	return std::string();
}

void ICodable::SaveDecodeProcces(std::string className, SubClassDecode decodeProcces)
{
	ICodable::GetDecodeMap()->emplace(className, decodeProcces);
}

ICodable::DecodeMap* ICodable::GetDecodeMap()
{
	static DecodeMap* map = new DecodeMap();
	return map;
}