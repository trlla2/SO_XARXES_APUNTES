#pragma once
#include <string>
#include <list>

struct Question {
	std::string question;

	std::list<std::string> responses;

	unsigned short int correctResponse;
};


