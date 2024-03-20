#pragma once
#include "Polje.h"
class Ruza : public Polje
{
public:
	Ruza() : Polje() {}

	int poprskaj(int mlaz) override
	{
		otkriveno = false;

		return 0;
	}

	POLJA sadrzaj() override
	{
		return POLJA::RUZA;
	}


	void prikazi() override
	{
		if (otkriveno)
			std::cout << "r";
		else
			std::cout << "i";
	}

};

