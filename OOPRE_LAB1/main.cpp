#include <iostream>

#include "Igrica.h"
#include <ctime>
#include <cstdlib>


int main(void)
{
	std::srand((std::time(nullptr)));

	try
	{
		Igrica igra("livada.txt");
		igra.pokreni();
	}
	catch (const char* msg)
	{
		std::cerr << msg;
		return -1;
	}

	return 0;
}