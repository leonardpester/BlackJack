#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <random>
#include<fstream>
#include <string>
#include <sstream>
#include <cstring>
#include<stdio.h>

using namespace std;
int suma_pl = 0, el, bet1, bet2, bet, sold1, sold2, suma_pc = 0, carte_pl[15], carte_pc[15], i = 0, j = 0, pl = 0, pc = 0, v = 55, aux = 0, carte_pl1[15], carte_pl2[15], suma_pl1, suma_pl2;
string name1, name2;
char raspuns;
int again();
int meniu();
int game2();
int second2();
int secondh();
int deleteall();
int modifica();
int afiseaza_lista();
int scrie();
int detalii();
int pariu();
int suma(string sm);
int adaugare(string sal1, string sal2);
int resetare();
int main();





int scrie()
{

	std::ofstream myfile("lista.txt", std::ios::app);
	char t[50];
	int bani;
	cout << endl << " Alegeti-va un nume de utilizator5!\n Acesta trebuie sa fie fara spatii,doar litere mici fara cifre si fara spatii!\n Exemplu: gheorghevasile\n Introduceti numele jucatorului: ";

	cin >> t;
	cout << endl << " Introduceti suma de bani pe care doriti sa o aveti in contul BLACKJACJK: ";
	cin >> bani;
	myfile << endl << t << " " << bani;
	myfile.close();
	cout << endl << endl;
	meniu();
	return 0;
}



int meniu() {
	char selection;

	cout << endl;
	cout << " __________________________________________________________________\n";
	cout << " |                   |                     |                       |\n";
	cout << " |-------------------|      BLACK-JACK     |-----------------------|\n";
	cout << " |___________________|_____________________|_______________________|\n";
	cout << " |                                                                 |\n";
	cout << " |            1. Inregistrare                                      |\n";
	cout << " |            2. Actualizeaza informatii despre jucatori           |\n";
	cout << " |            3. Player VS Computer                                |\n";
	cout << " |            4. Player VS Player                                  |\n";
	cout << " |            5. Consultare punctaj a unui player                  |\n";
	cout << " |_________________________________________________________________|\n";
	cout << "  Tasteaza alegerea ta: ";
	cin >> selection;
	cout << endl << endl;

	switch (selection)
	{
	case '1':
		scrie();
		cout << "\n"; cout << "\n"; cout << "\n";
		break;

	case '2':
		modifica();
		cout << "\n"; cout << "\n"; cout << "\n";
		break;
	case '3':
		game();
		cout << "\n"; cout << "\n"; cout << "\n";
		break;

	case '4':
		cout << "Doriti sa jucati pe bani (D) sau simplu (N)? ";
		cin >> raspuns;
		if (raspuns == 'D')
			pariu();
		else
			game2();
		break;

	case '5':
		detalii();
		break;

	default: cout << selection << "tasta gresita\n";

		cout << endl;
	}
	return 0;
}


//permite rejucarea sau intoarcerea la meniu
int again() {
	cout << endl << "Mai jucati un joc ? Tastati 'D' pentru 1vs1 ,'P' pentru 1 vs computer sau 'M' pentru a reveni la meniu" << " ";
	char tasta;
	cin >> tasta;
	if (tasta == 'P')
		game();
	if (tasta == 'D')
		pariu();
	if (tasta == 'M')
		main();
	return 0;

}

// player vs player prima-mana
int game2() {
	resetare();

	carte_pl1[i] = random(); suma_pl1 = suma_pl1 + carte_pl1[i]; i++;
	carte_pl1[i] = random(); suma_pl1 = suma_pl1 + carte_pl1[i]; i++;
	carte_pl2[j] = random(); suma_pl2 = suma_pl2 + carte_pl2[j]; j++;
	carte_pl2[j] = random(); suma_pl2 = suma_pl2 + carte_pl2[j]; j++;
	cout << endl << "  Player1  Cartile tale sunt:  " << carte_pl1[i - 2] << "  " << carte_pl1[i - 1] << "  Player1  Suma ta este: " << suma_pl1;
	cout << endl << "  Player2  Cartile tale sunt:  " << carte_pl2[j - 2] << "  " << carte_pl2[j - 1] << "  Player2  Suma ta este: " << suma_pl2;
	cout << endl << endl;
	second2();

	return 0;
}

/
}

// MAIN
int main()

{
	srand(time(0));
	meniu();
}