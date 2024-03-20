#pragma once

#include "Polje.h"
#include "Seme_ruze.h"
#include "Ruza.h"
#include "Trojanska_ruza.h"
#include "Jaje_puza.h"
#include "Puz.h"
#include "Trojanski_puz.h"
#include "Trava.h"
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <math.h>
#include <iomanip>



class Livada
{
private:
	Polje*** polja;
	int velicina;

	int prskaj(int pos_x, int pos_y);
	void posadi_ruze(int pos_x, int pos_y, int semenke);
	void posadi_ruzu_random();
	void pojedi_ruze(int pos_x, int pos_y);

	void postavi_puza();

public:
	Livada(std::string file_name);

	int prskaj();
	void prikazi();
	bool kraj();
	int broj_ruza();
};

