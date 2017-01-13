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





int adaugare(string sal1, string sal2)
{
	cout << endl << endl;

	ifstream fin("lista.txt");

	string date;


	string buffer, buf, sir, k, sir1, spatiu = " ";

	int m = 0, n = 0, kill = 0, aux1 = suma(sal1) + bet, aux2 = suma(sal2) - bet;


	while (!fin.eof()) {
		fin >> buffer;

		if (kill == 1) {
			buffer = static_cast<ostringstream*>(&(ostringstream() << aux1))->str();
			kill = 0;
		}
		if (buffer == sal1)
			kill = 1;
		if (kill == 2) {
			buffer = static_cast<ostringstream*>(&(ostringstream() << aux2))->str();
			kill = 0;
		}
		if (buffer == sal2)
			kill = 2;

		if (buf != buffer) {
			buffer += spatiu;
			date += buffer;
		}

		buf = buffer;

	}

	fin.close();
	deleteall();

	ofstream fout("lista.txt");
	for (int x = 0; x < date.length(); x++) {
		k = date.at(x);
		if (k.compare(spatiu) != 0)
			fout << k;
		else {
			m++;
			if (m % 2 == 0)
				fout << endl;
			else
				fout << spatiu;

		}
	}
	fout.close();
	cout << endl << " Modificare completa!!!";
	meniu();
	return 0;
}

int add(int el) {
	if (el == 1) {
		cout << endl << name1 << " Ai castigat " << bet;
		adaugare(name1, name2);
	}
	else {
		if (el == 2) {
			cout << endl << name2 << " Ai castigat " << bet;
			adaugare(name2, name1);
		}
		else
			cout << endl << " Pariu inapoiat";
	}
	again();
	return 0;
}

int pariu() {
	cout << endl << " Tastati numele jucatorului 1 : ";
	cin >> name1;
	cout << " Aveti in cont : " << suma(name1) << " $" << endl;
	cout << endl << " Tasta numele jucatorului 2 : ";
	cin >> name2;
	cout << " Aveti in cont : " << suma(name2) << " $" << endl;
	cout << endl << " Tastati suma pe care doriti sa jucati :" << endl << " Jocul nu se poate desfasura daca ambii jucatori nu au cel putin suma pariata in cont: ";
	cin >> bet;

	if (suma(name1) >= bet && suma(name2) >= bet) {
		cout << endl << " Pariu acceptat!Mult Succes!!! ";
		game2();
	}
	else {
		cout << endl << " Pariul nu poate fi acceptat,unul dintre jucatori nu are suma necesara";
		meniu();
	}
	return 0;

}

//functia de inregistrare a unui jucator nou//
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


//functia care permite modificarea numelui unui jucator si/sau suma de bani pe care o are acesta in cont
int modifica()
{

	afiseaza_lista();
	cout << endl << endl;

	ifstream fin("lista.txt");

	string date;



	string buffer, buf, sir, k, sir1, spatiu = " ";
	int m = 0, n = 0, at, kill = 0;
	cout << endl << " Introduceti numele dumneavoastra: ";
	cin >> name1;
	int aux1 = suma(name1);
	cout << endl << " Daca doriti sa adaugati bani in cont tastati (B) ";
	cout << endl << " Dca doriti sa va schimbati numele tastati(N) |";
	cout << endl << " Tastati alegerea ( B / N ) :";
	cin >> raspuns;
	if (raspuns == 'N') {
		cout << endl << " Introduceti noul nume: ";
		cin >> name2;



		while (!fin.eof())
		{
			fin >> buffer;


			if (buffer == name1)
				buffer = name2;
			if (buf != buffer)
			{
				buffer += spatiu;
				date += buffer;
			}

			buf = buffer;

		}
	}
	else
	{
		cout << endl << " Introduceti suma pe care doriti sa o adaugati: ";
		cin >> at;



		while (!fin.eof()) {
			fin >> buffer;

			if (kill == 1) {
				buffer = static_cast<ostringstream*>(&(ostringstream() << (aux1 + at)))->str();
				kill = 0;
			}
			if (buffer == name1)
				kill = 1;

			if (buf != buffer) {
				buffer += spatiu;
				date += buffer;
			}

			buf = buffer;

		}


	}

	fin.close();
	deleteall();

	ofstream fout("lista.txt");
	for (int x = 0; x < date.length(); x++)
	{
		k = date.at(x);
		if (k.compare(spatiu) != 0)
			fout << k;
		else {
			m++;
			if (m % 2 == 0)
				fout << endl;
			else
				fout << spatiu;

		}
	}
	fout.close();
	cout << endl << " Modificare completa!!! ";
	meniu();
	return 0;
}

//afiseaza toata lista cu jucatori 
int afiseaza_lista() {
	ifstream fin("lista.txt");
	string date;
	string buffer, buf, k, spatiu = " ";
	int m = 0;


	while (!fin.eof()) {
		fin >> buffer;
		if (buf != buffer) {
			buffer += spatiu;
			date += buffer;
		}
		buf = buffer;
	}

	fin.close();


	for (int x = 0; x < date.length(); x++) {
		k = date.at(x);
		if (k.compare(spatiu) != 0)
			cout << k;
		else {
			m++;
			if (m % 2 == 0)
				cout << endl;
			else
				cout << spatiu;

		}
	}

	return 0;

}

//afiseaza detaliile despre un anume jucator
int detalii() {
	ifstream fin("lista.txt");
	string date;
	string buffer, sir, buf, k, spatiu = " ";
	cout << endl << " Introduceti numele pentru a afla detalii: ";
	cin >> sir;
	int m = 0; i = 0;


	while (!fin.eof()) {
		fin >> buffer;
		if (sir == buffer) {
			buffer += spatiu;
			date += buffer;
			fin >> buffer;
			date += buffer;
		}

	}

	fin.close();


	for (int x = 0; x < date.length(); x++) {
		k = date.at(x);
		if (k.compare(spatiu) != 0)
			cout << k;
		else {
			m++;
			if (m % 2 == 0)
				cout << endl;
			else
				cout << spatiu;

		}
	}
	cout << endl;

	return 0;

}

int suma(string sm) {
	ifstream fin("lista.txt");
	string date;
	string buffer, sir, buf, k, spatiu = " ";


	while (!fin.eof()) {
		fin >> buffer;
		if (sm == buffer) {
			fin >> buffer;
			date += buffer;
		}

	}

	fin.close();
	int value = atoi(date.c_str());

	return value;
}



//sterge tot din fisier

int deleteall()
{
	std::ofstream ofs;
	ofs.open("lista.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return 0;
}


//numere random
int random() {
	int carte;
	//var = rand() % 9999999;
	//(time(NULL));
	carte = rand() % 11 + 1;
	return carte;
}


//reseteaza niste variabile utile la unele functii
int resetare() {
	int k;
	suma_pl = NULL, suma_pc = NULL, pl = NULL, pc = NULL; aux = 0;
	raspuns = NULL; carte_pl1[15], carte_pl2[15], suma_pl1 = NULL, suma_pl2 = NULL;

	for (k = i; k >= 0; k--)
		carte_pl[k] = NULL;
	for (k = j; k >= 0; k--)
		carte_pc[k] = NULL;
	for (k = i; k >= 0; k--)
		carte_pl1[k] = NULL;
	for (k = i; k >= 0; k--)
		carte_pl2[k] = NULL;
	i = NULL, j = NULL;
	return 0;


}

// player vs computer


int secondh() {
	while (aux == 0) {
		if (pl != 1) {
			if (suma_pl >= 21)
				pl = 1;
			else {
				cout << endl << " Inca o carte? D/N" << "  ";
				cin >> raspuns;
				if (raspuns == 'D') {
					carte_pl[i] = random(); suma_pl = suma_pl + carte_pl[i]; i++;
					cout << endl << " Cartea ta este:  " << carte_pl[i - 1] << " Suma este: " << suma_pl;
				}
				else {
					pl = 1;
					cout << endl << " " << " Suma ta finala este: " << suma_pl;
				}
			}
			if (suma_pl > 21) {
				pc = 1;
				pl = 1;
			}
		}
		if (pc != 1) {
			if (suma_pc < 17) {
				carte_pc[j] = random(); suma_pc = suma_pc + carte_pc[j]; j++;
				cout << endl << "  Carte dealer-ului este: " << "  " << carte_pc[j - 1] << "     " << " Suma dealarului:  " << suma_pc;

			}
			if (suma_pc >= 21) {
				pc = 1;
				pl = 1;

			}
			if (suma_pc >= 17 && suma_pc <= 21)
				pc = 1;


		}
		if (pl == 1 && pc == 1)
			aux = 1;
	}
	cout << endl << pl << pc;

	if (pl == 1 && pc == 1) {
		cout << endl << "Suma jucator: " << suma_pl << endl;
		cout << "Suma dealer: " << suma_pc << endl;

		if (suma_pl > suma_pc && suma_pl <= 21)
			cout << endl << " Castigator Player ";

		if (suma_pc>suma_pl && suma_pc <= 21)
			cout << endl << " Castigator Dealer ";

		if (suma_pl>21 && suma_pc <= 21)
			cout << endl << " Castigator Dealer ";
		if (suma_pl == suma_pc)
			cout << endl << "   EGALITATE  ";
		if (suma_pc > 21 && suma_pl < 21)
			cout << endl << " Castigator Player ";
		cout << endl << endl << endl << endl;
		again();
	}

	return 0;
}


// afiseza prima mana , primele doua carti pentru player si computer
int game() {
	resetare();

	carte_pl[i] = random(); suma_pl = suma_pl + carte_pl[i]; i++;
	carte_pl[i] = random(); suma_pl = suma_pl + carte_pl[i]; i++;
	carte_pc[j] = random(); suma_pc = suma_pc + carte_pc[j]; j++;
	carte_pc[j] = random(); suma_pc = suma_pc + carte_pc[j]; j++;
	cout << endl << " Cartile tale sunt: " << carte_pl[i - 2] << "  " << carte_pl[i - 1] << "  Suma ta este: " << suma_pl;
	cout << endl << " Cartile Dealerului: " << "  " << "(INTOARSA)" << "  " << carte_pc[j - 1] << "  Suma dealer este: " << suma_pc;
	secondh();

	return 0;

}


//meniul principal


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

// player vs player
int second2() {
	while (aux == 0) {
		if (pl != 1) {
			if (suma_pl1 >= 21)
				pl = 1;
			else {
				cout << endl << " Player1: inca o carte? D/N  " << "  ";
				cin >> raspuns;
				if (raspuns == 'D') {
					carte_pl1[i] = random(); suma_pl1 = suma_pl1 + carte_pl1[i]; i++;
					cout << " Player1: cartea ta este:  " << carte_pl1[i - 1] << "\n Player1:  suma este:   " << suma_pl1 << endl;
				}
				else {
					pl = 1;
					cout << endl << " " << " Player1: suma ta finala este: " << suma_pl1;
				}
			}
			if (suma_pl1 > 21) {
				pc = 1;
				pl = 1;

			}
			raspuns = NULL;
		}
		if (pc != 1) {
			if (suma_pl2 >= 21)
				pc = 1;
			else {
				cout << endl << " Player2:Inca o carte? D/N" << "  ";
				cin >> raspuns;
				if (raspuns == 'D') {
					carte_pl2[j] = random(); suma_pl2 = suma_pl2 + carte_pl2[j]; j++;
					cout << " Player2: Cartea ta este:  " << carte_pl2[j - 1] << " \n Player2-Suma este:   " << suma_pl2 << endl;
				}
				else {
					pc = 1;
					cout << endl << " " << " Player2: Suma ta finala este: " << suma_pl2;
				}
			}

			if (suma_pl2 >= 21) {
				pc = 1;
				pl = 1;
			}
		}
		raspuns = NULL;

		if (pl == 1 && pc == 1)
			aux = 1;
	}
	cout << endl;
	if (pl == 1 && pc == 1) {
		cout << endl << " Suma player1: " << suma_pl1 << endl;
		cout << " Suma player2: " << suma_pl2 << endl;

		if (suma_pl1 > suma_pl2 && suma_pl1 <= 21) {
			cout << endl << " Castigator Player1";
			el = 1;
		}
		if (suma_pl2 > suma_pl1 && suma_pl2 <= 21) {
			cout << endl << " Castigator Player2";
			el = 2;
		}
		if (suma_pl1 > 21 && suma_pl2 <= 21) {
			cout << endl << " Castigator Player2";
			el = 2;
		}
		if (suma_pl1 == suma_pl2) {
			cout << endl << "   EGALITATE";
			el = 0;
		}
		if (suma_pl2 > 21 && suma_pl1 < 21) {
			el = 1;
			cout << endl << "Castigator Player1";
		}
		cout << endl << endl << endl << endl;
		add(el);
	}
	return 0;
}

// MAIN
int main()

{
	srand(time(0));
	meniu();
}