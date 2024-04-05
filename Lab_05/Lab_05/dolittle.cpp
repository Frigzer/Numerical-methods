#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n;
	fstream dane;
	dane.open("RURL_dane2.txt");
	dane >> n;
	double** a = new double* [n];
	double* b = new double[n];


	double** l = new double* [n];
	double** u = new double* [n];
	double* y = new double[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		l[i] = new double[n];
		u[i] = new double[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dane >> a[i][j];
			l[i][j] = 0;
			u[i][j] = 0;
			if (i == j)
				l[i][j] = 1;
		}
		dane >> b[i];
	}
	dane.close();
	std::cout << "Macierz rozszerzona przed obliczeniami: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << b[i] << endl;
	}

	double temp;
	double temp2;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp = 0;
			temp2 = 0;
			if (i <= j)
			{
				for (int k = 0; k < i; k++)
				{
					temp += l[i][k] * u[k][j];
				}
				u[i][j] = a[i][j] - temp;
			}
			else
			{
				for (int k = 0; k < j; k++)
				{
					temp2 += l[i][k] * u[k][j];
				}
				l[i][j] = (a[i][j] - temp2) / u[j][j];
			}

		}
	}

	std::cout << endl << endl;

	std::cout << "Macierz U:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << u[i][j] << "\t";
		}
		std::cout << endl;
	}

	std::cout << endl << endl;

	std::cout << "Macierz L:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << l[i][j] << "\t";
		}
		std::cout << endl;
	}

	double temp3 = 0;
	for (int i = 0; i < n; i++)
	{
		temp3 = 0;
		if (i == 0)
			y[i] = b[i];
		else
		{
			for (int j = 0; j < i; j++)
			{
				temp3 += l[i][j] * y[j];
			}
			y[i] = b[i] - temp3;
		}

	}

	std::cout << endl << endl;

	std::cout << "Wektor Y:\n";

	for (int i = 0; i < n; i++)
	{
		std::cout << "y[" << i << "]: " << y[i] << endl;
	}

	//Rozwi¹zywanie uk³adu równañ
	double* x = new double[n];
	for (int i = 0; i < n; i++)
		x[i] = 0;
	x[n - 1] += (y[n - 1] / u[n - 1][n - 1]);

	for (int i = n - 1; i >= 0; i--)
	{
		//x[i] = b[i] / a[i][i];
		double temp = 0;
		for (int j = i + 1; j < n; j++)
		{
			temp += u[i][j] * x[j];
		}
		x[i] = (y[i] - temp) / u[i][i];
	}

	std::cout << endl << endl;

	std::cout << "Rozwiazanie ukladu rownan:\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << "x[" << i << "]: " << x[i] << endl;
	}

}