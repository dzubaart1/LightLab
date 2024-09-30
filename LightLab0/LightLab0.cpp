#include <iostream>

double f(double x);
double monteCarloIntegration(int numPoints);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int numPoints = 1000000; // Количество случайных точек
    double integral = monteCarloIntegration(numPoints);
    std::cout << "Approximate value of the integral: " << integral << std::endl;

    return 0;
}

// Функция, интеграл которой мы хотим вычислить
double f(double x)
{
    return x * x;
}

// Метод Монте-Карло
double monteCarloIntegration(int numPoints)
{
    double sum = 0.0;
    for (int i = 0; i < numPoints; i++)
    {
        double x = static_cast<double>(rand()) / RAND_MAX;
        sum += f(x);
    }

    return sum / numPoints;
}