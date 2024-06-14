#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPSILON = 0.01;

double f1(double x)
{
	return cos(x * x * x - 2 * x);
}

double f2(double x)
{
	return sin(-x * x * x * x + 2 * x * x + 6 * x);
}

void metoda_bisekcji(double a, double b, double f(double x))
{
	if (f(a) * f(b) >= 0) {
		cout << "Niepoprawny przedzia³ [a, b]" << endl;
		return;
	}

	double og_a = a;
	double og_b = b;

	cout << "Metoda bisekcji: " << endl;
	cout << "iter\ta\tb\tf(a)\t\tf(b)\t\tx0\tf(x0)\t\tf(a)*f(x0)" << endl;
	double x0 = (a + b) / 2;
	int i = 0;
	while (fabs(f(x0)) > EPSILON)
	{
		x0 = (a + b) / 2;

		if (f(x0) == 0.0)
			break;

		if (f(x0) * f(a) < 0)
			b = x0;
		else
			a = x0;

		cout << i << "\t" << a << "\t" << b << "\t" << f(a) << "\t" << f(b) << "\t" << x0 << "\t" << f(x0) << "\t" << f(a) * f(x0) << endl;

		++i;
	}

	cout << "x0: " << x0 << " dla epsilon: " << EPSILON << ", na przedziale: [" << og_a << ", " << og_b << "]";
}

void metoda_falszywej_linii(double a, double b, double f(double x))
{
	if (f(a) * f(b) >= 0) {
		cout << "Niepoprawny przedzia³ [a, b]" << endl;
		return;
	}

	double og_a = a;
	double og_b = b;

	cout << "Metoda fa³szywej linii: " << endl;
	cout << "iter\ta\tb\tf(a)\t\tf(b)\t\tx1\tf(x1)\t\tf(a)*f(x1)" << endl;

	double x1 = a - (f(a) * (b - a)) / (f(b) - f(a));
	int i = 0;
	while (fabs(f(x1)) > EPSILON) {
		x1 = a - (f(a) * (b - a)) / (f(b) - f(a));

		if (f(x1) == 0.0)
			break;

		if (f(x1) * f(a) < 0)
			b = x1;
		else
			a = x1;

		cout << i << "\t" << a << "\t" << b << "\t" << f(a) << "\t" << f(b) << "\t" << x1 << "\t" << f(x1) << "\t" << f(a) * f(x1) << endl;

		++i;
	}
	cout << "x1: " << x1 << " dla epsilon: " << EPSILON << ", na przedziale: [" << og_a << ", " << og_b << "]";
}

int main()
{
	setlocale(LC_ALL, "polish");
	//cout << fixed << setprecision(5);

	cout << "Funkcja: cos(x^3 - 2x)" << endl << endl;
	metoda_bisekcji(0, 2, f1);

	cout << endl << endl;

	metoda_falszywej_linii(0, 2, f1);

	cout << endl << endl;

	cout << "Funkcja: sin(-x^4 + 2x^2 + 6*x)" << endl << endl;
	metoda_bisekcji(1, 2, f2);

	cout << endl << endl;

	metoda_falszywej_linii(1, 2, f2);

}