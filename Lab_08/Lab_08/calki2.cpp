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
		temp += (x + s - x) / 2.0 * (f(x) + f(x + s));
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

void gauss_legendere(double a, double b, double f(double x), int n) {
	double* x = new double[n];
	double* A = new double[n];

	if (n == 2) {
		x[0] = -sqrt(3.0) / 3.0;
		x[1] = sqrt(3.0) / 3.0;

		A[0] = 1.0;
		A[1] = 1.0;
	}
	else if (n == 3) {
		x[0] = -sqrt(3.0 / 5.0);
		x[1] = 0.0;
		x[2] = sqrt(3.0 / 5.0);

		A[0] = 5.0 / 9.0;
		A[1] = 8.0 / 9.0;
		A[2] = 5.0 / 9.0;
	}
	else if (n == 4) {
		
		x[0] = -1.0 / 35.0 * sqrt(525.0 + 70.0 * sqrt(30.0));
		x[1] = -1.0 / 35.0 * sqrt(525.0 - 70.0 * sqrt(30.0));
		x[2] = 1.0 / 35.0 * sqrt(525.0 - 70.0 * sqrt(30.0));
		x[3] = 1.0 / 35.0 * sqrt(525.0 + 70.0 * sqrt(30.0));

		A[0] = (18.0 - sqrt(30.0)) / 36.0;
		A[1] = (18.0 + sqrt(30.0)) / 36.0;
		A[2] = (18.0 + sqrt(30.0)) / 36.0;
		A[3] = (18.0 - sqrt(30.0)) / 36.0;

		/*
		A[0] = (1.0 / 36.0) * (18.0 - sqrt(30.0));
		A[1] = (1.0 / 36.0) * (18.0 + sqrt(30.0));
		A[2] = (1.0 / 36.0) * (18.0 + sqrt(30.0));
		A[3] = (1.0 / 36.0) * (18.0 - sqrt(30.0));
		*/
		

	}
	else {
		cout << "Nieobs逝giwana liczba wez這w" << endl;
		delete[] x;
		delete[] A;
		return;
	}

	double s = (b - a) / 2.0;
	double temp = 0.0;
	for (int i = 0; i < n; i++)
	{
		double t = (a + b) / 2.0 + (b - a) / 2.0 * x[i];
		temp += A[i] * f(t);
	}
	double solution = s * temp;
	cout << "Metoda Gaussa-Legender'a dla kwadratury " << n << "-wezlowej: " << solution << endl;

	delete[] x;
	delete[] A;
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

	//Metoda trapez闚
	trapeze(a, b, f1, n);

	//Metoda Simpsona
	simpson(a, b, f1, n);

	//Metoda Gaussa-Legendre'a dla kwadratury dwu-w瞛這wej
	gauss_legendere(a, b, f1, 2);

	//Metoda Gaussa-Legendre'a dla kwadratury trzy-w瞛這wej
	gauss_legendere(a, b, f1, 3);

	//Metoda Gaussa-Legendre'a dla kwadratury cztero-w瞛這wej
	gauss_legendere(a, b, f1, 4);

	cout << endl << endl;
	//(x^2 + 2x + 5)

	b = 5;

	cout << "Wzor calkowanej funkcji: x^2 + 2x + 5" << endl;
	cout << "Przedzial calkowania: < " << a << ", " << b << " >" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	//Metoda prostokatow
	rectangles(a, b, f2, n);

	//Metoda trapez闚
	trapeze(a, b, f2, n);

	//Metoda Simpsona
	simpson(a, b, f2, n);

	//Metoda Gaussa-Legendre'a dla kwadratury dwu-w瞛這wej
	gauss_legendere(a, b, f2, 2);

	//Metoda Gaussa-Legendre'a dla kwadratury trzy-w瞛這wej
	gauss_legendere(a, b, f2, 3);

	//Metoda Gaussa-Legendre'a dla kwadratury cztero-w瞛這wej
	gauss_legendere(a, b, f2, 4);

	cout << endl << endl;
	//exp(x)

	cout << "Wzor calkowanej funkcji: exp(x)" << endl;
	cout << "Przedzial calkowania: < " << a << ", " << b << " >" << endl;
	cout << "Liczba przedzialow: " << n << endl;
	//Metoda prostokatow
	rectangles(a, b, f3, n);

	//Metoda trapez闚
	trapeze(a, b, f3, n);

	//Metoda Simpsona
	simpson(a, b, f3, n);

	//Metoda Gaussa-Legendre'a dla kwadratury dwu-w瞛這wej
	gauss_legendere(a, b, f3, 2);

	//Metoda Gaussa-Legendre'a dla kwadratury trzy-w瞛這wej
	gauss_legendere(a, b, f3, 3);

	//Metoda Gaussa-Legendre'a dla kwadratury cztero-w瞛這wej
	gauss_legendere(a, b, f3, 4);
}