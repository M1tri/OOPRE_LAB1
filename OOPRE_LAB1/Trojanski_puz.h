#pragma once
#include "Polje.h"
class Trojanski_puz : public Polje
{
public:

	Trojanski_puz(): Polje() {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	POLJA sadrzaj() override
	{
		return POLJA::TROJANSKI_PUZ;
	}

	void prikazi() override
	{
		if (otkriveno)
			std::cout << "$";
		else
			std::cout << "i";
	}
};

