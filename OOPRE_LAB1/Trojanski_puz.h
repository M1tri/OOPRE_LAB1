#pragma once
#include "Polje.h"
class Trojanski_puz : public Polje
{
public:

	Trojanski_puz(bool vidljivost = false): Polje(vidljivost) {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	//POLJA sadrzaj() override
	//{
	//	return POLJA::TROJANSKI_PUZ;
	//}

	void prikazi() override
	{
		if (otkriveno)
			std::cout << std::setw(4) << "$";
		else
			std::cout << std::setw(4) << "i";
	}

	bool operator==(POLJA polje)
	{
		return polje == POLJA::TROJANSKI_PUZ;
	}
};

