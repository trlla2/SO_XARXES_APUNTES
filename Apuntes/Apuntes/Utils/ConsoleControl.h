#pragma once
#include <mutex>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <conio.h>


static class ConsoleControl
{
public: // declarations
	
	enum ConsoleColor {
		BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA,
		DARGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
	};

private:

	HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);

	std::mutex* _consoleMutex = new std::mutex;

	static ConsoleControl GetInstance();

	static HANDLE GetConsole();

public:

	static void SetColor(ConsoleColor textColor = WHITE, ConsoleColor backgroundColor = BLACK);
	
	static void SetPosition(short int x, short int y);
	
	static void Clear();

	static void FillWithCharacter(char character, ConsoleColor textColor, ConsoleColor backgroundColor);
	
	static void ClearKeyBuffer();

	static int ReadNextKey();

	static int WaitForReadNextKey();

	static char WaitForReadNextChar();

	static void Lock();

	static void Unlock();
};



using CC = ConsoleControl; // alias for ConsoleControl