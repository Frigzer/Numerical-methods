#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    fstream dane;

    dane.open("RURL_Jacobi_dane1.txt");
    dane >> n;

    double** a = new double* [n];
    double* b = new double[n];

    double** lu = new double* [n];
    double** d = new double* [n];
    double* y = new double[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
        lu[i] = new double[n];
        d[i] = new double[n];
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dane >> a[i][j];
            lu[i][j] = 0;
            d[i][j] = 0;
        }
        dane >> b[i];
    }
    dane.close();
    /*
    std::cout << "Uklad rownan: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << a[i][j] << "\t";
        }
        std::cout << b[i] << endl;
    }
    */

    double temp;
    bool weak = true;
    bool onlyOnce = false;

    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                temp += abs(a[i][j]);
            }
        }

        if (!(abs(a[i][i])) >= temp)
            weak = false;

        if (abs(a[i][i]) > temp)
        {
            onlyOnce = true;
        }

    }

    /*
    std::cout << endl << endl;

    if (weak && onlyOnce)
        std::cout << "Macierz diagonalnie slabo dominujaca!!!" << endl;
    */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                d[i][j] = a[i][j];
            }
            else
            {
                lu[i][j] = a[i][j];
            }

        }
    }

    /*
    std::cout << endl << endl;

    std::cout << "Macierz L+U:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << lu[i][j] << "\t";
        }
        std::cout << endl;
    }

    std::cout << endl << endl;

    std::cout << "Macierz diagonalna odwrotna:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                std::cout << 1 / d[i][j] << "\t";
            else
                std::cout << d[i][j] << "\t";
        }
        std::cout << endl;
    }
    */

    double epsilon;
    int numOfIterations;
    int iter = 0;

    
    cout << "Podaj wartosc bledu epsilon: ";
    cin >> epsilon;
    cout << "Podaj maksymalna ilosc iteracji: ";
    cin >> numOfIterations;

    double* x = new double[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;

    double* temp2 = new double[n];

    bool continueIteration = true;
    while(continueIteration && iter < numOfIterations)
    {
        continueIteration = false;
        for (int i = 0; i < n; ++i)
        {
            double sum = 0.0;
            if (iter > 0)
            {
                for (int j = 0; j < n; ++j)
                {
                    sum += lu[i][j] * x[j];
                }
            }
            temp2[i] = (b[i] - sum) / d[i][i];
            if (abs(temp2[i] - x[i]) >= epsilon) {
                continueIteration = true;
            }
        }


        for (int i = 0; i < n; i++)
        {
            x[i] = temp2[i];
        }

        iter++;
    }

    cout << endl << endl;

    cout << "Przyjeta wartosc bledu epsilon: " << epsilon << endl;
    cout << "Ilosc wykonanych iteracji: " << iter << endl;
    cout << "Rozwiazanie ukladu rownan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: " << x[i] << endl;
    }

    
    if (iter == numOfIterations && continueIteration) {
        cout << "Nie znaleziono rozwiazania spelniajacego zadana dokladnosc w zadanej liczbie iteracji." << endl;
    }
    return 0;
}
