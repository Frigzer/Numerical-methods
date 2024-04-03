#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n;
	fstream dane;
	dane.open("MN-2-p2.txt");
	dane >> n;
	double** M = new double* [n];
	for (int i = 0; i < n; i++)
		M[i] = new double[2];
	for (int i = 0; i < n; i++)
	{
		dane >> M[i][0];
		dane >> M[i][1];
	}
	dane.close();
	double x;
	double y = 0;
	std::cout << "Liczba wezlow: " << n << endl;
	std::cout << "Dane: \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << "\t" << M[i][0] << " " << M[i][1];
		std::cout << endl;
	}
	std::cout << "\nPodaj punkt w ktorym chcesz obliczyc wartosc wielomianu: ";
	cin >> x;
	std::cout << "\nWspolczynniki wielomianu Newtona: ";


	for (int k = 0; k < n; k++)
	{
		double p = 1;
		double b = 0;

		for (int i = 0; i <= k - 1; i++)
		{
			p *= (x - M[i][0]);
		}
		for (int i = 0; i <= k; i++)
		{
			double temp = 1;
			for (int j = 0; j <= k; j++)
			{
				if (j != i)
				{
					temp *= (M[i][0] - M[j][0]);
				}
			}
			b += (M[i][1] / temp);
		}
		std::cout << b << ", ";
		y += (b * p);
	}
	std::cout << "\n\nWartosc wielomianu w punkcie " << x << " wynosi: " << y << endl;

	// -4.44089e-16 <- wartoœæ bardzo bliska zeru
	// 2.22045e-16 <- wartoœæ bardzo bliska zeru
	// cout << 1 + -4.44089e-16 << endl;
	// cout << 1 + 2.22045e-16 << endl;

}