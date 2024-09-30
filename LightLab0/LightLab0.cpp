#include <iostream>

double f(double x);
double monteCarloIntegration(int numPoints);
double stratifiedSamplingIntegration(int numStrata, int pointsPerStratum);

int main()
{
    // Для простого монте-карло
    //srand(static_cast<unsigned int>(time(0)));

    //int numPoints = 1000000; // Количество случайных точек
    //double integral = monteCarloIntegration(numPoints);
    //std::cout << "Approximate value of the integral: " << integral << std::endl;

    // Для стратификации
    //srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    //int numStrata = 10; // Количество страт
    //int pointsPerStratum = 100000; // Количество случайных точек в каждой страте
    //double integral = stratifiedSamplingIntegration(numStrata, pointsPerStratum);
    //std::cout << "Approximate value of the integral: " << integral << std::endl;

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

double stratifiedSamplingIntegration(int numStrata, int pointsPerStratum)
{
    double sum = 0.0;
    double stratumWidth = 1.0 / numStrata;

    // Генерация случайных точек в каждой страте
    for (int i = 0; i < numStrata; i++) {
        double stratumStart = i * stratumWidth; // Начало текущей страты
        double stratumEnd = (i + 1) * stratumWidth; // Конец текущей страты

        for (int j = 0; j < pointsPerStratum; j++) {
            // Генерация случайной точки внутри текущей страты
            double randomPoint = stratumStart + (static_cast<double>(rand()) / RAND_MAX) * stratumWidth;
            sum += f(randomPoint);
        }
    }

    return (sum / (numStrata * pointsPerStratum)); // Среднее значение по всем выбранным точкам
}