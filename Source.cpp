//Lab 6.2 rec
//Кулик Олег ІК-11
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i] << ",";
    if (i < size - 1)
        Print(a, size, i + 1);
}

void Naoborot(int* a, const int n, int i)
{
    int tmp = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = tmp;

    if (i < n / 2 - 1)
        Naoborot(a, n, i + 1);
}
int main()
{
    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    int Low;
    int High;
    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;

    Create(a, n, Low, High, 0);
    cout << "a[" << n << "] = {";
    Print(a, n, 0);
    cout << "}"; cout << endl;

    cout << "a[" << n << "] = {";
    Naoborot(a, n, 0);
    Print(a, n, 0);
    cout << "}"; cout << endl;


    return 0;
}
