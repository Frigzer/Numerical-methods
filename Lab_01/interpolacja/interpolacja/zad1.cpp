#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//Zadanie 1
	int n;
	fstream dane;
	dane.open("MN-1.txt");
	dane >> n;
	int** M = new int* [n];
	for (int i = 0; i < n; i++)
		M[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		dane >> M[i][0];
		dane >> M[i][1];
	}		
	dane.close();
	double x;
	double y = 0;
	cout << "Podaj punkt w ktorym chcesz obliczyc wartosc wielomianu: ";
	cin >> x;

	for (int i = 0; i < n; i++)
	{
		double temp = 1;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				temp *= (x - M[j][0]) / (M[i][0]-M[j][0]);
			}
		}
		y += (M[i][1] * temp);
	}

	cout << "Liczba wezlow: " << n << endl;
	cout << "Dane: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << M[i][0] << " " << M[i][1];
		cout << endl;
	}
	cout << "Wartosc wielomianu w punkcie " << x << " wynosi: " << y << endl;
}