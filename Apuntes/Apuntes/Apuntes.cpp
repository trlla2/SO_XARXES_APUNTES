#include <iostream>

#include "Utils/ConsoleControl.h"

#include <functional>

void TestLambasMolonas(std::function<int(int, int)> funcionMolona)
{
	std::cout << "Voy a ejecutar una funciion aaaaaaaaaaa" << std::endl;
	
	int number = funcionMolona(5 , 7);
	
	std::cout << "ya e ejecutado la function" << std::endl;
}

int main()
{
	std::function<int(int,int)> funcionKHaceCosasPeroS1Variable = []( int a, int b) {

		std::cout << "Esto no se como pero funca" << std::endl;
		return a + b;
		};

	TestLambasMolonas(funcionKHaceCosasPeroS1Variable);
}

