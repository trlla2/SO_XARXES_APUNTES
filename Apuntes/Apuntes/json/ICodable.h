#pragma once
#include <json/json.h>
#include <functional>
#include <string>


class ICodable
{
public:
	typedef std::function<ICodable* ()> SubClassDecode;
	typedef std::map<std::string, SubClassDecode> DecodeMap;
public:

	static std::string DeceodeKey();
	static void SaveDecodeProcces(std::string className, SubClassDecode decodeProcces);

	template <typename T,
		typename = typename std::enable_if<
		std::is_base_of<
		ICodable, T
		>::value
		>::type
	>
	static void SaveDecodeProcces() 
	{
		SaveDecodeProcces(typeid(T).name(), []() {
			return new T();
		});
	}

	virtual Json::Value Code() = 0;
	virtual void Decode(Json::Value json) = 0;

	template <typename T,
		typename = typename std::enable_if<
		std::is_base_of<
		ICodable, T
		>::value
		>::type
	>
	static T* FromJson(Json::Value json)
	{
		std::string className = json[DeceodeKey()].asString();

		DecodeMap* decodeMap = GetDecodeMap();
		SubClassDecode decodeLamba = (*decodeMap)[className];
		ICodable* codable = decodeLamba();

		T* codableCasted = dynamic_cast<T*>(codable);

		codableCasted->Decode(json);

		return codableCasted;
	}

protected:

	template <typename T,
		typename = typename std::enable_if<
		std::is_base_of<
		ICodable, T
		>::value
		>::type
	>
	void CodeSubClassType(Json::Value& json) 
	{
		json[DeceodeKey()] = typeid(T).name();
	}

private:

	static DecodeMap* GetDecodeMap();
};

