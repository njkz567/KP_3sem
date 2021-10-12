#include <iostream>
#include <iomanip> // ��� setw()
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������� time()
#include "fun.h"

void print (int *A, const int amount)
{
    for (int j = 0; j < amount; j++)
    {
        std::cout << std::setw(10) << A[j] << " ";
        if ((j + 1)% 5 == 0)
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

// ���������� ��������� ����� ����� ���������� min � max.
// ��������������, ��� ������� srand() ��� ��������
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // ���������� ������������ ��������� ����� � ����� ���������
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void full (int *A, const int amount)
{
    srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
    for (int i = 0; i < amount; i++)
        A[i] = getRandomNumber(-50,50);
}

#define AMOUNT 35

void change_sign ()
{
    int amount = AMOUNT;
    int A[AMOUNT];
    full(A, amount);
    print(A, amount);
    std::cout << '\n';
    std::cout << '\n';
    int max = abs(A[0]);
    for (int i = 1; i < amount; i++)
        if (abs(A[i]) > max)
            max = my_abs(A[i]);
    for (int i = 0; i < amount; i++)
        if (abs(A[i]) == max)
            A[i] = -A[i];
    print(A, amount);
}
