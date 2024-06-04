#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

double newton(int n, int k)
{
	return tgamma(n + 1) / (tgamma(k + 1) * tgamma(n - k + 1));
}

double wielomian(double x, double n)
{
	if (n == 0)
		return 1;
	double result = 1;
	for (int j = 0; j < n; ++j)
	{
		result *= (x - j);
	}
	return result;
}

double gram(int k, int n, double q)
{
	n--;
	if (q == 0)
		return 1;
	double result = 0;
	for (int s = 0; s <= k; ++s)
	{
		result += pow(-1, s) * newton(k, s) * newton(k + s, s) * (wielomian(q, s) / wielomian(n, s));
	}
	return result;
}

double aproksymacja(double* ck, double* sk, double m, int n, double q)
{
	double result = 0;
	for (int k = 0; k <= m; ++k)
	{
		double Fk = gram(k, n, q);
		result += ck[k] / sk[k] * Fk;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "polish");

	int n;

	int m = 1;

	fstream dane;
	dane.open("punkty.txt");

	if (!dane.is_open())
	{
		cout << "Nie mo¿na otworzyæ pliku";
		return 1;
	}

	dane >> n;

	double* x = new double[n];
	double* y = new double[n];
	double* ym = new double[n];

	for (int i = 0; i < n; i++)
	{
		dane >> x[i];
		dane >> y[i];
		ym[0] = 0;
	}

	dane.close();

	double h = x[1] - x[0];


	double* sk = new double[m + 1];
	double* ck = new double[m + 1];


	for (int i = 0; i <= m; i++)
	{
		sk[i] = 0;
		ck[i] = 0;
	}

	for (int k = 0; k <= m; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			double q = (x[i] - x[0]) / h;
			double Fk = gram(k, n, q);
			sk[k] += pow(Fk, 2);
			ck[k] += y[i] * Fk;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		double q = (x[i] - x[0]) / h;
		ym[i] = aproksymacja(ck, sk, m, n, q);
	}

	cout << "Stopieñ wielomianu: " << m << endl;
	cout << "Liczba wêz³ów aproksymacji: " << n << endl;

	cout << endl;

	cout << "Wspó³czynniki Ck: ";
	for (int i = 0; i <= m; ++i) {
		cout << "c" << i << " = " << ck[i] << " ";
	}
	cout << endl;

	cout << "Wspó³czynniki Sk: ";
	for (int i = 0; i <= m; ++i) {
		cout << "s" << i << " = " << sk[i] << " ";
	}
	cout << endl;

	cout << endl;
	cout << "Podane wêz³y aproksymacji, wartoci w wêz³ach oraz obliczone wartoci funkcji aproksymuj¹cej:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "x[" << i << "]: " << x[i] << ",\ty[" << i << "]: " << y[i] << ",\tym[" << i << "]: " << ym[i] << endl;
	}

	cout << endl;
	vector<double> points = { 2.5, 6.5 };
	for (double xp : points)
	{
		double q = (xp - x[0]) / h;
		double ymp = aproksymacja(ck, sk, m, n, q);
		cout << "Wartoæ funkcji aproksymuj¹cej w x: " << xp << " wynosi: " << ymp << endl;
	}

	delete[] x;
	delete[] y;
	delete[] ym;
	delete[] sk;
	delete[] ck;
}