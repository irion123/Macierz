// Wyznacznik wg rekurencyjnego rozwini�cia Laplace'a
// Data   : 8.02.2011
// (C)2012 mgr Jerzy Wa�aszek
//----------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// Rekurencyjna funkcja obliczaj�ca rozwini�cie Laplace'a
//-------------------------------------------------------
double det(int n, int w, int * WK, double ** A)
{
	int    i, j, k, m, *KK;
	double s;

	if (n == 1)                                    // sprawdzamy warunek zako�czenia rekurencji

		return A[w][WK[0]];                         // macierz 1 x 1, wyznacznik r�wny elementowi

	else
	{

		KK = new int[n - 1];                        // tworzymy dynamiczny wektor kolumn

		s = 0;                                      // zerujemy warto�� rozwini�cia
		m = 1;                                      // pocz�tkowy mno�nik

		for (i = 0; i < n; i++)                      // p�tla obliczaj�ca rozwini�cie
		{

			k = 0;                                    // tworzymy wektor kolumn dla rekurencji

			for (j = 0; j < n - 1; j++)                // ma on o 1 kolumn� mniej ni� WK
			{
				if (k == i) k++;                         // pomijamy bie��c� kolumn�
				KK[j] = WK[k++];                        // pozosta�e kolumny przenosimy do KK
			}

			s += m * A[w][WK[i]] * det(n - 1, w + 1, KK, A);

			m = -m;                                   // kolejny mno�nik

		}

		delete[] KK;                               // usuwamy zb�dn� ju� tablic� dynamiczn�

		return s;                                   // ustalamy warto�� funkcji

	}
}

//*** PROGRAM G��WNY ***
//----------------------

int main()
{
	int       n, i, j;                              // stopie� macierzy
	int     * WK;                                 // wektor kolumn
	double ** A;                                  // macierz

	cout << fixed << setprecision(4);

	cin >> n;                                     // odczytujemy stopie� macierzy

	A = new double *[n];                         // tworzymy macierz wska�nik�w

	for (i = 0; i < n; i++)
	{

		A[i] = new double[n];                       // tworzymy wiersz

		for (j = 0; j < n; j++) cin >> A[i][j];      // czytamy wiersz macierzy

	}

	WK = new int[n];                              // tworzymy wiersz kolumn

	for (i = 0; i < n; i++)                        // wype�niamy go numerami kolumn
		WK[i] = i;

	cout << endl;

	cout << det(n, 0, WK, A) << endl; // obliczamy i wy�wietlamy wyznacznik

	system("pause");
}