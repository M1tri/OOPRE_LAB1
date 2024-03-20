#pragma once
#include "Polje.h"
class Trojanska_ruza : public Polje
{
public:
	Trojanska_ruza(bool vidljivost = false): Polje(vidljivost) {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	//POLJA sadrzaj() override
	//{
	//	return POLJA::TROJANKSA_RUZA;
	//}

	void prikazi() override
	{
		if (otkriveno)
			std::cout << std::setw(4) << "*";
		else
			std::cout << std::setw(4) << "i";
	}

	bool operator==(POLJA polje)
	{
		return polje == POLJA::TROJANKSA_RUZA;
	}
};

