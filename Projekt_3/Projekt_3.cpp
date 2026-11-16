#include <iostream>
#include "MergeSort.h"

using namespace std;

int main()
{
    int tablicaInt[] = { 8, 3, 5, 1, 9, 2 };
    int rozmiarInt = 6;

    double tablicaDouble[] = { 4.5, 1.2, 8.7, 3.1, 2.6 };
    int rozmiarDouble = 5;

    MergeSort<int> sortowanieInt(tablicaInt, rozmiarInt);
    MergeSort<double> sortowanieDouble(tablicaDouble, rozmiarDouble);

    sortowanieInt.sort();
    sortowanieDouble.sort();

    cout << "Tablica int po sortowaniu:" << endl;

    for (int i = 0; i < rozmiarInt; i++)
    {
        cout << tablicaInt[i] << " ";
    }

    cout << endl;

    cout << "Tablica double po sortowaniu:" << endl;

    for (int i = 0; i < rozmiarDouble; i++)
    {
        cout << tablicaDouble[i] << " ";
    }

    cout << endl;

    return 0;
}