#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#pragma region Functions Declaration Header

void PrintElapsedTime(
	std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName);
void Count(unsigned long long maxCounter, std::string threadName);

void Example01();
void Example02();
void Example03();
void Example04();
void Example05();
void Example06();
void Example07();

#pragma endregion 

#pragma region Global Variables

std::chrono::system_clock::time_point startDate;

#pragma endregion

void ThreadTutorialTest()
{
	startDate = std::chrono::system_clock::now();

	int exampleUsed = 1; // change this variable for use diferents examples

	switch (exampleUsed)
	{
	case 1:
		Example01();
		break;
	case 2:
		Example02();
		break;
	case 3:
		Example03();
		break;
	case 4:
		Example04();
		break;
	case 5:
		Example05();
		break;
	case 6:
		Example06();
		break;
	case 7:
		Example07();
		break;
	default:
		break;
	}

	std::cout << "Example 0" << exampleUsed << " finished" << std::endl;
	std::string text = "";
	std::getline(std::cin, text);
}

void PrintElapsedTime(
	std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName) 
{
	std::chrono::duration<double> elapsedTime = end - start;
	std::cout << "Thread: " << threadName 
		<< " - Elapsed time: " << elapsedTime.count() 
		<< " seconds" << std::endl;
}

void Count(unsigned long long maxCounter, std::string threadName) 
{
	for (unsigned long long i = 0; i < maxCounter; i++) {

	}

	std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
	PrintElapsedTime(startDate, endDate, threadName);
}

void Example01()
{
	unsigned long long totalCount = 1000000000ull;
	

	// Crea todo y se para al acabar la ejecucion del ultimo thread
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");
	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	Counter1->join();
	Counter2->join();
	Counter3->join();

	// Crea y se para al acabar ejecucion del thread, crea y se para al acabar ejecucion del thread...
	/*std::thread* Counter1 = new std::thread(Count, totalCount, "1");
	Counter1->join();
	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	Counter2->join();
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");
	Counter3->join();*/

	Count(totalCount, "0"); // count sin el thread
}

void Example02()
{

}

void Example03()
{

}

void Example04()
{

}

void Example05()
{

}

void Example06()
{

}

void Example07()
{

}
