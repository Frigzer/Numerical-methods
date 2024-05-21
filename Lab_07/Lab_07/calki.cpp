#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void rectangles(double a, double b, double f(double x), int n)
{
	double s = (b - a) / n;
	double temp = 0.0;
	double solution;
	for (int i = 0; i < n; i++)
	{
		double x = a + s * i + s / 2.0;
		temp += f(x);
	}
	solution = s * temp;
	cout << "Metoda prostokatow: " << solution << endl;
}

void trapeze(double a, double b, double f(double x), int n)
{
	double s = (b - a) / n;
	double temp = 0.0;
	for (int i = 0; i < n; i++)
	{
		double x = a + s * i;
		temp += (x + s - x) / 2.0 * (f(x) + f(x+s));
	}
	double solution = temp;

	cout << "Metoda trapezow: " << solution << endl;

}


void simpson(double a, double b, double f(double x), int n) {
	double s = (b - a) / n;
	double temp = 0.0;

	for (int i = 0; i < n; i++) {
		double x = a + s * i;
		temp += (s / 6.0) * (f(x) + 4.0 * f(x + s / 2.0) + f(x + s));
	}

	double solution = temp;
	cout << "Metoda Simpsona: " << solution << endl;
}

double f1(double x)
{
	return sin(x);
}

double f2(double x)
{
	return (x * x + 2 * x + 5);
}

double f3(double x)
{
	return exp(x);
}

int main()
{
	//sin(x)
	double a, b;
	int n;
	a = 0.5;
	b = 2.5;
	n = 20;
	cout << "Wzor calkowanej funkcji: sin(x)" << endl;
	cout << "Przedzial calkowania: < " << a << ", " << b << " >" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	//Metoda prostokatow
	rectangles(a, b, f1, n);

	//Metoda trapezów
	trapeze(a, b, f1, n);

	//Metoda Simpsona
	simpson(a, b, f1, n);

	cout << endl << endl;
	//(x^2 + 2x + 5)

	b = 5;

	cout << "Wzor calkowanej funkcji: x^2 + 2x + 5" << endl;
	cout << "Przedzial calkowania: < " << a << ", " << b << " >" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	//Metoda prostokatow
	rectangles(a, b, f2, n);

	//Metoda trapezów
	trapeze(a, b, f2, n);

	//Metoda Simpsona
	simpson(a, b, f2, n);

	cout << endl << endl;
	//exp(x)

	cout << "Wzor calkowanej funkcji: exp(x)" << endl;
	cout << "Przedzial calkowania: < " << a << ", " << b << " >" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	//Metoda prostokatow
	rectangles(a, b, f3, n);

	//Metoda trapezów
	trapeze(a, b, f3, n);

	//Metoda Simpsona
	simpson(a, b, f3, n);
}