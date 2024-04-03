#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//Zadanie 2

	int n2;
	fstream dane2;
	dane2.open("dane.txt");
	dane2 >> n2;
	double** M2 = new double* [n2];
	for (int i = 0; i < n2; i++)
		M2[i] = new double[n2];
	for (int i = 0; i < n2; i++)
	{
		dane2 >> M2[i][0];
		dane2 >> M2[i][1];
	}
	dane2.close();

	double x = 50;
	double y = 0;
	for (int i = 0; i < n2; i++)
	{
		double temp = 1;
		for (int j = 0; j < n2; j++)
		{
			if (j != i)
			{
				temp *= (x - M2[j][0]) / (M2[i][0] - M2[j][0]);
			}
		}
		y += (M2[i][1] * temp);
	}
	cout << "Liczba wezlow: " << n2 << endl;
	cout << "Dane: \n";
	for (int i = 0; i < n2; i++)
	{
		cout << "\t" << M2[i][0] << " " << M2[i][1];
		cout << endl;
	}
	cout << "Wartosc pierwiastka trzeciego stopnia z " << x << " wynosi: " << y << endl;
}