#include <iostream>
#include <iomanip> // для setw()
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include "fun.h"

void print (int **A, const int collumns, const int string)
{
    for (int i = 0; i < collumns; i++)
    {
        for (int j = 0; j < string; j++)
            std::cout << std::setw(10) << A[i][j] << " ";
        std::cout << '\n';
    }
}

int my_abs (const int a)
{
    if (a >= 0)
        return a;
    else
        return -a;
}

// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void full (int **A, const int collumns, const int string)
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    for (int i = 0; i < collumns; i++)
        for (int j = 0; j < string; j++)
            A[j][i] = getRandomNumber(-50,50);
}

#define COLLUMNS 9
#define STRING 8

void change_sign ()
{
    int collumns = COLLUMNS, string = STRING;
    int **A = new int*[COLLUMNS];
    for (int i = 0; i < COLLUMNS; i++)
        A[i] = new int[STRING];
    full(A, collumns, string);
    print(A, collumns, string);
    std::cout << '\n';
    for (int j = 0; j < collumns; j++)
    {
        int max = abs(A[j][0]);
        for (int i = 1; i < string; i++)
            if (abs(A[j][i]) > max)
                max = my_abs(A[j][i]);
        for (int i = 0; i < string; i++)
            if (abs(A[j][i]) == max)
                A[j][i] = -A[j][i];
    }

    print(A, collumns, string);

    for (int i = COLLUMNS - 1; i >= 0 ; i--)
        delete A[i];
    delete A;
}
