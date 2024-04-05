#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n;
	fstream dane;
	dane.open("RURL_dane3.txt");
	dane >> n;
	double** a = new double* [n];
	double* b = new double[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dane >> a[i][j];
		}
		dane >> b[i];
	}
	dane.close();
	std::cout << "Macierz rozszerzona przed obliczeniami: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << b[i] << endl;
	}

	// Obliczenia
	double* m = new double[n];
	double* temp = new double[n];
	double temp2;

	for (int k = 0; k < n; k++)
	{
		double max = a[k][k];
		for (int j = k; j < n; j++)
		{
			if (abs(max) < abs(a[j][k]))
			{
				max = a[j][k];
			}
		}

		for (int j = k; j < n; j++)
		{
			if (a[j][k] == max)
			{
				for (int l = k; l < n; l++)
				{
					temp[l] = a[j][l];
					a[j][l] = a[k][l];
					a[k][l] = temp[l];
				}
				temp2 = b[k];
				b[k] = b[j];
				b[j] = temp2;
				break;
			}
		}

		for (int i = k + 1; i < n; i++)
		{
			m[i] = (a[i][k] / a[k][k]);
			for (int j = 0; j < n; j++)
			{
				a[i][j] -= a[k][j] * m[i];
			}
			b[i] -= b[k] * m[i];
		}
	}



	cout << endl << endl;

	cout << "Macierz rozszerzona po pierwszym etapie obliczen:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << b[i] << endl;
	}


	//Rozwi¹zywanie uk³adu równañ
	double* x = new double[n];
	for (int i = 0; i < n; i++)
		x[i] = 0;
	x[n - 1] += (b[n - 1] / a[n - 1][n - 1]);

	for (int i = n - 1; i >= 0; i--)
	{
		//x[i] = b[i] / a[i][i];
		double temp = 0;
		for (int k = i + 1; k < n; k++)
		{
			temp += a[i][k] * x[k];
		}
		x[i] = (b[i] - temp) / a[i][i];
	}

	cout << endl << endl;

	cout << "Rozwiazanie ukladu rownan:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i << "]: " << x[i] << endl;
	}

}