#pragma once
#include "Polje.h"
class Jaje_puza : public Polje
{
private:
	int broj = 1;

public:
	Jaje_puza(bool vidljivost = false) : Polje(vidljivost) {};

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return mlaz + broj;
	}

	//POLJA sadrzaj() override
	//{
	//	return POLJA::JAJE_PUZA;
	//}


	void prikazi() override
	{
		if (otkriveno)
			std::cout << std::setw(4) << "0";
		else
			std::cout << std::setw(4) << "i";
	}

	bool operator==(POLJA polje)
	{
		return polje == POLJA::JAJE_PUZA;
	}
};




