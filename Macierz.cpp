//
// Created by Tomasz Kozub on 2018-12-18.
//

#include "Macierz.h"

#include <iomanip>

using namespace std;

Macierz::Macierz() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->macierz[i][j] = i;
		}
	}
	this->wyznacznik = 0;
}

Macierz::~Macierz() = default;

void Macierz::stworz_macierz() {
	cout << "Wprowadz liczby do macierzy 3x3" << endl;
	double x;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x;
			this->macierz[i][j] = x;
		}
	}
}

void Macierz::wyswietl_macierz() {
	cout << "Podana macierz:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setprecision(2) << this->macierz[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Macierz::wyswietl_macierz_odwrotna() {
	cout << "Macierz odwrotna:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << this->macierz_odwrotna[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Macierz::licz_wyznacznik() {
	double wyznacznik = (this->macierz[0][0] * this->macierz[1][1] * this->macierz[2][2] +
		this->macierz[0][1] * this->macierz[1][2] * this->macierz[2][0] +
		this->macierz[0][2] * this->macierz[1][0] * this->macierz[2][1]);

	wyznacznik -= (this->macierz[0][2] * this->macierz[1][1] * this->macierz[2][0] +
		this->macierz[0][0] * this->macierz[1][2] * this->macierz[2][1] +
		this->macierz[0][1] * this->macierz[1][0] * this->macierz[2][2]);

	cout << "Wyznacznik detA = " << wyznacznik<< endl;

	if (wyznacznik != 0) {
		this->wyznacznik = wyznacznik;
	}
	else {
		this->wyznacznik = 0;
		cout << "Nie istnieje macierz odwrotna, poniewarz wyznacznik jest rowny 0" << endl;
		system("pause");
		exit(true);
	}
}

void Macierz::licz_odwrotna() {
	vector<double> tmp;
	tmp.push_back(pow(-1, 2) * (this->macierz[1][1] * this->macierz[2][2] - this->macierz[1][2] * this->macierz[2][1]));
	tmp.push_back(pow(-1, 3) * (this->macierz[1][0] * this->macierz[2][2] - this->macierz[1][2] * this->macierz[2][0]));
	tmp.push_back(pow(-1, 4) * (this->macierz[1][0] * this->macierz[2][1] - this->macierz[1][1] * this->macierz[2][0]));
	tmp.push_back(pow(-1, 3) * (this->macierz[0][1] * this->macierz[2][2] - this->macierz[0][2] * this->macierz[2][1]));
	tmp.push_back(pow(-1, 4) * (this->macierz[0][0] * this->macierz[2][2] - this->macierz[0][2] * this->macierz[2][0]));
	tmp.push_back(pow(-1, 5) * (this->macierz[0][0] * this->macierz[2][1] - this->macierz[0][1] * this->macierz[2][0]));
	tmp.push_back(pow(-1, 4) * (this->macierz[0][1] * this->macierz[1][2] - this->macierz[0][2] * this->macierz[1][1]));
	tmp.push_back(pow(-1, 5) * (this->macierz[0][0] * this->macierz[1][2] - this->macierz[0][2] * this->macierz[1][0]));
	tmp.push_back(pow(-1, 6) * (this->macierz[0][0] * this->macierz[1][1] - this->macierz[0][1] * this->macierz[1][0]));

	int c = -3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->macierz_odwrotna[i][j] = tmp[c += 3] / this->wyznacznik;
		}
		if (c == 6) c = -2;
		else c = -1;
	}
}

int main(){
	Macierz macierz1;                       //Tworzenie obiektu klasy macierz
	macierz1.stworz_macierz();              //wype³nianie macierzy przez uzytkownika
	macierz1.wyswietl_macierz();            //wyœwietlanie podanej macierzy
	macierz1.licz_wyznacznik();             //liczenie wyznacznika
	macierz1.licz_odwrotna();               //licznie odwrotnej macierzy
	macierz1.wyswietl_macierz_odwrotna();   //wyswietlanie macierzy odwrotnej

	system("pause");
}