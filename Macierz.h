//
// Created by Tomasz Kozub on 2018-12-18.
//

#ifndef MACIERZ_PROJECT_MACIERZ_H
#define MACIERZ_PROJECT_MACIERZ_H


#include<iostream>
#include<math.h>
#include <vector>

using namespace std;

class Macierz {
private:
	double macierz[3][3];
	double macierz_odwrotna[3][3];
	double wyznacznik;

public:
	Macierz();

	virtual ~Macierz();

	double getWyznacznik();

	void stworz_macierz();

	void wyswietl_macierz();

	void wyswietl_macierz_odwrotna();

	void licz_wyznacznik();

	void licz_odwrotna();
};

#endif //MACIERZ_PROJECT_MACIERZ_H
