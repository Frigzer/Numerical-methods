#include <iostream>

using namespace std;

double f1(double x)
{
	return -x * x * x + 10 * x + 5;
}

double df1(double x)
{
	return -3 * x * x + 10;
}

double f2(double x)
{
	return x * x * x * x * x - 14;
}

double df2(double x)
{
	return 5 * x * x * x * x;
}

double f3(double x)
{
	return 5 * x * x + 3 * x - 4;
}

double df3(double x)
{
	return 10 * x + 3;
}

void metoda_stycznych(double f(double x), double df(double x), double x0, int n)
{
	cout << "Metoda stycznych:" << endl;
	double x = x0;
	for (int i = 0; i < n; ++i)
	{
		if (df(x) == 0) {
			cout << "Dzielenie przez zero!" << endl;
			return;
		}
		double x1 = x - f(x) / df(x);
		cout << "Iteracja " << i + 1 << ": x = " << x1 << ", f(x) = " << f(x1) << endl;
		x = x1;
	}
}

void metoda_siecznych(double f(double x), double df(double x), double x0, int n)
{
	cout << "Metoda siecznych:" << endl;
	double xk = x0;
	double xk_1 = x0 - 0.1;
	for (int i = 0; i < n; ++i)
	{
		if (f(xk) == f(xk_1))
		{
			cout << "Dzielenie przez zero!" << endl;
			return;
		}
		double xk1 = xk - f(xk) * (xk - xk_1) / (f(xk) - f(xk_1));
		cout << "Iteracja " << i + 1 << ": x = " << xk1 << ", f(x) = " << f(xk1) << endl;
		xk_1 = xk;
		xk = xk1;

	}
}

int main()
{
	setlocale(LC_ALL, "polish");
	double x0;
	int n;

	cout << "Podaj punkt x0: ";
	cin >> x0;
	cout << "Podaj liczb? iteracji: ";
	cin >> n;

	cout << endl;

	cout << "Funkcja: -x^3 + 10x + 5" << endl;
	metoda_stycznych(f1, df1, x0, n);
	cout << endl;
	metoda_siecznych(f1, df1, x0, n);

	cout << endl << endl;

	cout << "Funkcja: x^5 - 14" << endl;
	metoda_stycznych(f2, df2, x0, n);
	cout << endl;
	metoda_siecznych(f2, df2, x0, n);

	cout << endl << endl;

	cout << "Funkcja: 5x^2 + 3x - 4" << endl;
	metoda_stycznych(f3, df3, x0, n);
	cout << endl;
	metoda_siecznych(f3, df3, x0, n);
}