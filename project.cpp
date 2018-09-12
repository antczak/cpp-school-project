// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>  
#include <cstdlib>
#include <ctime>
using namespace std;
int potega(int a, int b) {
	int c;
	if (b == 0)
		return 1;
	if (b % 2 != 0)
		return a * potega(a, b - 1);
	else
		c = potega(a, b / 2);
	return c * c;


}
bool porownaj(char* a, char* b) {
	do {
		if (*a != *b)
			return false;
		*b++;
	} while (*a++);
	return true;
}
int charToInt(char* a) {
	int wynik = 0;
	char* b = a;
	int len = 0;
	while (*b++){
		len++;
	}
	*b--;
	*b--;
	for (int i = 1; i <= len; i++)
	{
		int c;
		c = (*b - '0') * potega(10, i);
		wynik = wynik + c;
		*b--;
	}
	return wynik/10;
}
char inputData[100];
enum RMocy {
	StrzelaniePradem,
	KontrolaElektrycznosci,
	OstreKly,
	OstrePazury,
	Latanie,
	Hipnoza,
	ProjekcjaGazu,
	Regeneracja,
	StrzelanieOgniem,
	Elastycznosc,
	KontrolaRoslin,
	Niewidzialnosc,
	Niematerialnosc,
	AtakiSoniczne,
	Radioaktywnosc,
	Pyrokineza,
	Elektrokineza,
	Omnipotencja

};
RMocy TablicaMocy[18] = { StrzelaniePradem, KontrolaElektrycznosci, OstreKly, OstrePazury, Latanie, Hipnoza, ProjekcjaGazu, Regeneracja, StrzelanieOgniem, Elastycznosc, KontrolaRoslin, Niewidzialnosc, Niematerialnosc, AtakiSoniczne, Radioaktywnosc, Pyrokineza, Elektrokineza, Omnipotencja };
class Postac
{
public:
	char* nazwa;
	int sila, wytrzymalosc, szybkosc, zrecznosc;
	Postac(char* a, int s, int w, int sz, int z) : sila(s), wytrzymalosc(w), szybkosc(sz), zrecznosc(z){
		nazwa = new char[strlen(a) + 1];
		memcpy(nazwa, a, strlen(a) + 1);
	}
	Postac(char* a) {
		nazwa = new char[strlen(a) + 1];
		memcpy(nazwa, a, strlen(a) + 1);
			sila = rand() % 100 + 1;
			wytrzymalosc = rand() % 100 + 1;
			szybkosc = rand() % 100 + 1;
			zrecznosc = rand() % 100 + 1;
	}

		Postac(Postac& ref)  {
			nazwa = new char[strlen(ref.nazwa) + 1];
			memcpy(nazwa, ref.nazwa, strlen(ref.nazwa) + 1);
			sila = ref.sila;
			wytrzymalosc = ref.wytrzymalosc;
			szybkosc = ref.szybkosc;
			zrecznosc = ref.zrecznosc;
		}

		void virtual Show()
		{

			cout << "Nazwa = " << nazwa << endl
				<< "Sila = " << sila << endl
				<< "Wytrzymalosc = " << wytrzymalosc << endl
				<< "Szybkosc = " << szybkosc << endl
				<< "Zrecznosc = " << zrecznosc << endl;
		}

};
class Obcy : public Postac {
public:

	class Moce{
	public:
		RMocy posiadaneMoce[20];
		int n;
		Moce() : n(0) {

		}
		bool dodajMoc (RMocy a){
			bool brakTakiejMocy = true;
			for (int i = 0; i <= n - 1; i++)
			{
				if (posiadaneMoce[i] == a)
					brakTakiejMocy = false;
			}
			if (brakTakiejMocy == true){
				posiadaneMoce[n] = a;
				n++;
				return true;
			}
			return false;
		}
		static char* nazwaMocy(RMocy a)
		{
			switch(a) {
			case StrzelaniePradem:
				return "Strzelanie pradem";
				break;
			case KontrolaElektrycznosci:
				return "Kontrola Elektrycznosci";
				break;
			case OstreKly:
				return "Ostre Kly";
				break;
			case OstrePazury:
				return "Ostre Pazury";
				break;
			case Latanie:
				return "Latanie";
				break;
			case Hipnoza:
				return "Hipnoza";
				break;
			case ProjekcjaGazu:
				return "Projekcja gazu";
				break;
			case Regeneracja:
				return "Regeneracja";
				break;
			case StrzelanieOgniem:
				return "Strzelanie ogniem";
				break;
			case Elastycznosc:
				return "Elastycznosc";
				break;
			case KontrolaRoslin:
				return "Kontrola roslin";
				break;
			case Niewidzialnosc:
				return "Niewidzialnosc";
				break;
			case Niematerialnosc:
				return "Niematerialnosc";
				break;
			case AtakiSoniczne:
				return "Ataki soniczne";
				break;
			case Radioaktywnosc:
				return "Radioaktywnosc";
				break;
			case Pyrokineza:
				return "Pyrokineza";
				break;
			case Elektrokineza:
				return "Elektrokineza";
				break;
			case Omnipotencja:
				return "Omnipotencja";
				break;
			default:
				return "Brak takiej mocy";
				break;
			}


		}
		void losoweMoce(int k)
		{
			int random;
			int d = n;
			for (int i = d; i <= d + k - 1; i++)
			{
				do {
					random = rand() % 19;
				} while (dodajMoc(TablicaMocy[random]) == false );
			}

		}
		void show()
		{
			for (int i = 0; i <= n - 1; i++)
			{
				cout << "Moc nr " << i + 1 << ": " << nazwaMocy(posiadaneMoce[i]) << "\n";
			}

		}

	};
	Moce* moce;
	Obcy(char* a, int s, int w, int sz, int z) : Postac(a, s, w, sz, z){
		moce = new Moce();
	}

	Obcy(char* a) : Postac(a) {
		moce = new Moce();
	}

	Obcy(Obcy& ref): Postac(ref) {
		moce = ref.moce;
	}
	void operator + (Obcy& a)
	{
		this->sila = floor( (this->sila + a.sila) / 2);
		this->wytrzymalosc = floor( (this->wytrzymalosc + a.wytrzymalosc) / 2);
		this->szybkosc = floor( (this->szybkosc + a.szybkosc) / 2);
		this->zrecznosc = floor( (this->zrecznosc + a.zrecznosc) / 2);
		for (int i = 0; i <= a.moce->n - 1; i++)
		{
			moce->dodajMoc(a.moce->posiadaneMoce[i]);
		}

	}

	void virtual Show()
	{

		cout << "Nazwa = " << nazwa << "\n" << endl
			<< "Sila = " << sila << endl
			<< "Wytrzymalosc = " << wytrzymalosc << endl
			<< "Szybkosc = " << szybkosc << endl
			<< "Zrecznosc = " << zrecznosc << "\n" << endl
		    << "Moce:\n" << endl;
		moce->show();
	}

	~Obcy() {
		delete[] moce;
	}

};


template<typename Obiekt>
class Baza {
public:
	Obiekt* obiekty[20];
	int n;
	Baza() : n(0) { }
	void Dodaj(Obiekt* o)
	{
		obiekty[n] = o;
		n++;
	}
	void show() {
		for (int i = 0; i <= n - 1; i++) {
			cout << "---Obcy nr " << i+1 << "--- \n\n";
			obiekty[i]->Show();
			cout << "\n\n";
		}

	}
	~Baza(){
		delete[] obiekty;
	}
};

class interfejs {
public:
	Baza<Obcy>* db;
	interfejs(Baza<Obcy>* a): db(a) {
		cout << "Witaj w bazie danych Obcych, dostepne sa nastepujace polecenia: \n-new (wprowadzenie nowego obcego) \n-show (wyswietlenie wszystkich obcych z bazy)\n-newfrom (stworzenie nowego obcego z polaczenie dwoch istniejacych)\n-exit (wyjscie)\n";
	}
	void getInput() {

		while (true)
		{
		cout << "Wpisz polecenie: ";
		cin >> inputData;
		char* ptr = inputData;
		int ilosc = 0;
		while (*ptr++)
		{
			ilosc++;
		}
		char* tab = new char[ilosc];
		tab = inputData;
		akcja(tab);
		}

	}
	void akcja(char* a)
	{
		char* ret;
		char** ret2 = new char*[17];
		for (int i = 0; i <= 17; i++) {
			ret = Obcy::Moce::nazwaMocy(TablicaMocy[i]);
			ret2[i] = ret;
		}
		cout << "Wybrano polecenie " << a << "\n\n";
		if (porownaj(a, "show") )
		{
			db->show();
		}
		else if (porownaj(a, "new") )
		{
			Obcy* nowyObcy;
			cout << "Podaj nazwe: ";
			cin >> inputData;
			char* nazwa = new char[strlen(inputData) + 1];
			memcpy(nazwa, inputData, strlen(inputData) + 1);
			cout << "Dobrac losowe statystyki(t/n)?: ";
			cin >> inputData;
			char* czyLosowe = new char[strlen(inputData) + 1];
			memcpy(czyLosowe, inputData, strlen(inputData) + 1);
			if ( porownaj(czyLosowe, "n")) {
				cout << "Sila: ";
				cin >> inputData;
				char* sila = new char[strlen(inputData) + 1];
				memcpy(sila, inputData, strlen(inputData) + 1);

				cout << "Wytrzymalosc: ";
				cin >> inputData;
				char* wytrzymalosc = new char[strlen(inputData) + 1];
				memcpy(wytrzymalosc, inputData, strlen(inputData) + 1);

				cout << "Szybkosc: ";
				cin >> inputData;
				char* szybkosc = new char[strlen(inputData) + 1];
				memcpy(szybkosc, inputData, strlen(inputData) + 1);

				cout << "Zrecznosc: ";
				cin >> inputData;
				char* zrecznosc = new char[strlen(inputData) + 1];
				memcpy(zrecznosc, inputData, strlen(inputData) + 1);

				int s = charToInt(sila);
				int w = charToInt(wytrzymalosc);
				int sz = charToInt(szybkosc);
				int z = charToInt(zrecznosc);
				nowyObcy = new Obcy(nazwa, s, w, sz, z);
			}
			else
			{
				nowyObcy = new Obcy(nazwa);
			}
			cout << "Dobrac losowe moce(t/n)?: ";
			cin >> inputData;
			char* czyLosoweMoce = new char[strlen(inputData) + 1];
			memcpy(czyLosoweMoce, inputData, strlen(inputData) + 1);
			if (porownaj(czyLosoweMoce, "n"))
			{
				cout << "Wybierz moce: \n";
				for (int i = 0; i <= 17; i++) {
					cout << i + 1 << " - " << ret2[i] << "\n";

				}
				while (true) {
					cout << "Wpisz numer mocy lub 0 aby zakonczyc: ";
					cin >> inputData;
					char* nrMocy = new char[strlen(inputData) + 1];
					memcpy(nrMocy, inputData, strlen(inputData) + 1);
					int nr = charToInt(nrMocy);
					if (nr == 0)
						break;
					nowyObcy->moce->dodajMoc(TablicaMocy[nr-1]);

				}

			}
			else
			{
				int r = rand() % 5;
				nowyObcy->moce->losoweMoce(r);

			}
			 
			db->Dodaj(nowyObcy);
			cout << "\nDodano " << nazwa << " do bazy\n\n";

		
		}

		else if (porownaj(a, "newfrom")) {
			cout << "Podaj nazwe: ";
			cin >> inputData;
			char* nazwa = new char[strlen(inputData) + 1];
			memcpy(nazwa, inputData, strlen(inputData) + 1);
			cout << "Podaj nr pierwszego obiektu: ";
			cin >> inputData;
			char* dane = new char[strlen(inputData) + 1];
			memcpy(dane, inputData, strlen(inputData) + 1);
			cout << "Podaj nr drugiego obiektu: ";
			cin >> inputData;
			char* dane2 = new char[strlen(inputData) + 1];
			memcpy(dane2, inputData, strlen(inputData) + 1);
			int nr1 = charToInt(dane) - 1;
			int nr2 = charToInt(dane2) - 1;
			Obcy &ref = *db->obiekty[nr1];
			Obcy* nowyObcy = new Obcy(ref);
			nowyObcy->nazwa = nazwa;
			(*nowyObcy) + (*db->obiekty[nr2]);
			db->Dodaj(nowyObcy);
			cout << "Dodano nowego obcego do bazy \n\n";

		}

		else if (porownaj(a, "exit")) {
			exit(0);
		}
		else {
			cout << "To nie jest poprawne polecenie \n\n";
		}
	}

	~interfejs() {
		delete db;
	}


};

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	Obcy* postac1 = new Obcy("Acorc", 22, 17, 55, 24);
	Obcy* postac2 = new Obcy("Hweig", 90, 31, 45, 60);
	Obcy* postac3 = new Obcy("Ox-Ho");
	Obcy* postac4 = new Obcy("Qebsfeuf");
	Obcy* postac5 = new Obcy("Ran Kar");
	Obcy* postac6 = new Obcy("Lax");
	Obcy* postac7 = new Obcy("Cryxton");
	Obcy* postac8 = new Obcy("Orenox");
	postac1->moce->dodajMoc(Elastycznosc);
	postac1->moce->dodajMoc(Elastycznosc);
	postac1->moce->dodajMoc(Niewidzialnosc);
	postac2->moce->losoweMoce(2);
	postac3->moce->losoweMoce(2);
	postac4->moce->losoweMoce(3);
	postac5->moce->losoweMoce(3);
	postac6->moce->losoweMoce(2);
	postac7->moce->losoweMoce(3);
	postac8->moce->losoweMoce(2);
	Baza<Obcy>* BazaObcych = new Baza<Obcy>();
	BazaObcych->Dodaj(postac1);
	BazaObcych->Dodaj(postac2);
	BazaObcych->Dodaj(postac3);
	BazaObcych->Dodaj(postac4);
	BazaObcych->Dodaj(postac5);
	BazaObcych->Dodaj(postac6);
	BazaObcych->Dodaj(postac7);
	BazaObcych->Dodaj(postac8);
	interfejs* omnitrix = new interfejs(BazaObcych);
	omnitrix->getInput();
	return 0;
}

