#include "Livada.h"

Livada::Livada(std::string file_name)
{
	std::ifstream file;

	file.open("livada.txt");
	if (!file.is_open())
	{
		std::cout << "File can't be opened\n";
		throw "Griska pri otvaranju fajla\n";
	}

	char* buffer = new char[100]();
	file.getline(buffer, 99);
	try
	{
		velicina = std::stoi(buffer);
	}
	catch (const std::exception&)
	{
		throw "Lose navedena dimenzija livade u fajlu\n";
	}
	
	polja = new Polje * *[velicina]();
	for (int i = 0; i < velicina; i++)
	{
		polja[i] = new Polje * [velicina]();
	}

	for (int i = 0; i < velicina; i++)
	{
		if (!file.good())
		{
			throw "Greska pri citanju iz fajla\n";
		}

		file.getline(buffer, 99);
		for (int j = 0; j < velicina; j++)
		{
			if (buffer[j] == 's')
			{
				polja[i][j] = new Seme_ruze(abs(rand()) % 2 + 1);
				continue;
			}
			else if (buffer[j] == 'j')
			{
				polja[i][j] = new Jaje_puza();
			}
			else if (buffer[j] == '*')
			{
				polja[i][j] = new Trava();
			}
			else
			{
				file.close();
				throw "Greska pri citanju iz fajla\n";
			}


		}
	}
};

Livada::~Livada()
{
	for (int i = 0; i < velicina; i++)
	{
		for (int j = 0; j < velicina; j++)
		{
			delete polja[i][j];
		}
		delete[] polja[i];
	}
	delete[] polja;
}

void Livada::posadi_ruze(int pos_x, int pos_y, int semenke)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			bool gadjaj_opet = false;
			if (i == 0 && j == 0)
				continue;
			if (pos_x + i < 0 || pos_x + i >= velicina)
				continue;
			if (pos_y + j < 0 || pos_y + j >= velicina)
				continue;

			if (*polja[pos_x + i][pos_y + j] == POLJA::TRAVA)
			{
				if (polja[pos_x + i][pos_y + j]->vidljivo())
					gadjaj_opet = true;

				delete polja[pos_x + i][pos_y + j];
				polja[pos_x + i][pos_y + j] = new Seme_ruze(semenke, true);
					
				if (gadjaj_opet)
					prskaj(pos_x + i, pos_y + j);
			}
		}
	}
}

void Livada::posadi_ruzu_random()
{
	int x = abs(rand()) % velicina;
	int y = abs(rand()) % velicina;
	
	delete polja[x][y];
	polja[x][y] = new Ruza(true);
}

void Livada::pojedi_ruze(int pos_x, int pos_y)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (pos_x + i < 0 || pos_x + i >= velicina)
				continue;
			if (pos_y + j < 0 || pos_y + j >= velicina)
				continue;

			if (*polja[pos_x + i][pos_y + j] == POLJA::RUZA)
			{
				delete polja[pos_x + i][pos_y + j];
				polja[pos_x + i][pos_y + j] = new Trava(true);
			}
		}
	}
}

void Livada::postavi_puza()
{
	int x = abs(rand()) % velicina;
	int y = abs(rand()) % velicina;

	delete polja[x][y];
	polja[x][y] = new Puz(true);
	pojedi_ruze(x, y);
}

int Livada::prskaj(int pos_x, int pos_y)
{
	if (pos_x >= velicina || pos_x < 0 || pos_y >= velicina || pos_y < 0)
		throw "Pristup nevalidnom polju\n";

	int mlaz = abs(rand()) % 2 + 1;
	int jacina = polja[pos_x][pos_y]->poprskaj(mlaz);

	if (*polja[pos_x][pos_y] == POLJA::SEME_RUZE)
	{
		if (jacina == 2)
		{
			delete polja[pos_x][pos_y];
			polja[pos_x][pos_y] = new Ruza(true);
		}
		else if (jacina == 3)
		{
			delete polja[pos_x][pos_y];
			polja[pos_x][pos_y] = new Trava(true);
			posadi_ruze(pos_x, pos_y, jacina - mlaz);
		}
		else if (jacina == 4)
		{
			delete polja[pos_x][pos_y];
			polja[pos_x][pos_y] = new Trojanska_ruza(true);
			posadi_ruzu_random();
			posadi_ruzu_random();
			posadi_ruzu_random();
		}
	}
	else if (*polja[pos_x][pos_y] == POLJA::JAJE_PUZA)
	{
		if (jacina == 2)
		{
			delete polja[pos_x][pos_y];
			polja[pos_x][pos_y] = new Puz(true);
			pojedi_ruze(pos_x, pos_y);
		}
		if (jacina == 3)
		{
			delete polja[pos_x][pos_y];
			polja[pos_x][pos_y] = new Trojanski_puz(true);
			postavi_puza();
			postavi_puza();
			postavi_puza();
		}
	}

	std::cout << "Poprskano je polje: " << pos_x << " " << pos_y << std::endl;
	prikazi();
}

int Livada::prskaj()
{
	int pos_x = abs(rand()) % velicina;
	int pos_y = abs(rand()) % velicina;

	return prskaj(pos_x, pos_y);
}

bool Livada::kraj()
{
	for (int i = 0; i < velicina; i++)
	{
		for (int j = 0; j < velicina; j++)
		{
			if (*polja[i][j] == POLJA::SEME_RUZE ||
				*polja[i][j] == POLJA::JAJE_PUZA && !polja[i][j]->vidljivo())
			{
				return false;
			}
		}
	}

	return true;
}

int Livada::broj_ruza()
{
	int poeni = 0;

	for (int i = 0; i < velicina; i++)
	{
		for (int j = 0; j < velicina; j++)
		{
			if (*polja[i][j] == POLJA::RUZA)
				poeni++;
		}
	}

	return poeni;
}

void Livada::prikazi()
{
	for (int i = 0; i < velicina; i++)
	{
		for (int j = 0; j < velicina; j++)
		{
			polja[i][j]->prikazi();
		}
		std::cout << '\n';
	}
	//std::cout << std::setw(1);
}