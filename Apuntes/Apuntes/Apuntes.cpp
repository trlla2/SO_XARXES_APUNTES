#include <iostream>

#include "Utils/ConsoleControl.h"

#include <functional>
#include <list>

typedef std::function<int(int, int)> SumaFunction;
typedef std::list<std::list<int>> ListDeList; // alias del tipo de variable/function

void TestLambasMolonas(SumaFunction funcionMolona)
{
	std::cout << "Voy a ejecutar una funciion aaaaaaaaaaa" << std::endl;
	
	int number = funcionMolona(5 , 7);
	
	std::cout << "ya e ejecutado la function y devuelve: " << number << std::endl;
}

int main()
{
	int c = 30;

	ListDeList listDeList;

	std::function<int(int,int)> funcionKHaceCosasPeroS1Variable = [c]( int a, int b) {

		std::cout << "Esto no se como pero funca" << std::endl;
		return a + b + c;
		};

	TestLambasMolonas(funcionKHaceCosasPeroS1Variable);
}

