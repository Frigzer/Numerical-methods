#include <iostream>
#include <fstream>

using namespace std;

double* gauss(double** a, double* b, int n)
{
	cout << "Macierz rozszerzona przed obliczeniami: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << b[i] << endl;
	}

	// Obliczenia - eliminacja kolumnami
	double* m = new double[n];
	double* temp = new double[n];
	int* test = new int[n];
	for (int i = 0; i < n; i++)
		test[i] = i;

	double temp2;

	for (int k = 0; k < n - 1; k++)
	{
		double max = a[k][k];
		for (int j = k; j < n; j++)
		{
			if (abs(max) < abs(a[k][j]))
			{
				max = a[k][j];
			}
		}

		for (int j = k; j < n; j++)
		{
			if (a[k][j] == max)
			{
				temp2 = test[k];
				test[k] = test[j];
				test[j] = temp2;
				for (int l = 0; l < n; l++)
				{
					temp[l] = a[l][j];
					a[l][j] = a[l][k];
					a[l][k] = temp[l];
				}
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

	cout << endl;

	cout << "Macierz rozszerzona po pierwszym etapie obliczeń:\n";

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
	x[test[n - 1]] += (b[n - 1] / a[n - 1][n - 1]);


	for (int i = n - 1; i >= 0; i--)
	{
		//x[i] = b[i] / a[i][i];
		double temp = 0;
		for (int k = i + 1; k < n; k++)
		{
			temp += a[i][k] * x[test[k]];
		}
		x[test[i]] = (b[i] - temp) / a[i][i];
	}


	cout << endl;

	return x;
}

int main()
{
	setlocale(LC_ALL, "polish");

	int n;

	int m = 1;

	fstream dane;
	dane.open("points.txt");

	dane >> n;

	double* x = new double[n];
	double* y = new double[n];
	double* w = new double[n];

	for (int i = 0; i < n; i++)
	{
		dane >> x[i];
		dane >> y[i];
		w[i] = 1.0;
	}

	dane.close();

	double** g = new double* [m + 1];
	double* F = new double[m + 1];


	for (int i = 0; i <= m; i++)
	{
		g[i] = new double[m + 1];
		F[i] = 0;
		for (int j = 0; j <= m; j++)
		{
			g[i][j] = 0;
		}
	}

	for (int k = 0; k <= m; k++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int i = 0; i < n; i++)
			{
				g[k][j] += pow(x[i], k) * pow(x[i], j) * w[i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			F[k] += pow(x[i], k) * y[i] * w[i];
		}
	}
	double* a = gauss(g, F, m + 1);

	// Wyświetlenie wyników
	cout << "Liczba węzłów: " << n << endl;
	cout << "Współczynniki wielomianu aproksymującego:" << endl;
	for (int i = 0; i <= m; i++) {
		cout << "a" << i << " = " << a[i] << endl;
	}
	cout << endl;

	cout << "Podane węzły aproksymacji i wartości w węzłach:" << endl;
	for (int i = 0; i < n; i++) {
		double temp = 0;
		for (int j = 0; j <= m; j++) {
			temp += a[j] * pow(x[i], j);
		}
		cout << "x = " << x[i] << ", y = " << y[i] << ", obliczone F(x) = " << temp << endl;
	}

	delete[] x;
	delete[] y;
	delete[] w;
	delete[] g;
	delete[] F;
	delete[] a;
}