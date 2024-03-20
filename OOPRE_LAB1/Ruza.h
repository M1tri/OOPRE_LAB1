#pragma once
#include "Polje.h"
class Ruza : public Polje
{
public:
	Ruza(bool vidljivost = false) : Polje(vidljivost) {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	//POLJA sadrzaj() override
	//{
	//	return POLJA::RUZA;
	//}


	void prikazi() override
	{
		if (otkriveno)
			std::cout << std::setw(4) << "r";
		else
			std::cout << std::setw(4) << "i";
	}

	bool operator==(POLJA polje)
	{
		return polje == POLJA::RUZA;
	}

};

