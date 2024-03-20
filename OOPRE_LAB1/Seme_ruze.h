#pragma once
#include "Polje.h"

class Seme_ruze : public Polje
{
private:
	int broj;

public:
	Seme_ruze(int broj, bool vidljivost = false) : Polje(vidljivost), broj(broj) { if (broj < 1 || broj > 2) broj = 1; }

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return mlaz + broj;
	}

	//POLJA sadrzaj() override
	//{
	//	return POLJA::SEME_RUZE;
	//}


	void prikazi() override
	{
		if (otkriveno)
			std::cout << std::setw(4) << "o";
		else
			std::cout << std::setw(4) << "i";
	}

	bool operator==(POLJA polje)
	{
		return polje == POLJA::SEME_RUZE;
	}

};

