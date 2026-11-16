#pragma once

template <typename T>
class MergeSort
{
private:
    T* tablica;
    int rozmiar;

    // Funkcja dzielaca tablice na mniejsze czesci
    void mergeSort(int lewy, int prawy)
    {
        if (lewy < prawy)
        {
            int srodek = (lewy + prawy) / 2;

            mergeSort(lewy, srodek);
            mergeSort(srodek + 1, prawy);

            merge(lewy, srodek, prawy);
        }
    }

    // Funkcja scalajaca dwie posortowane czesci
    void merge(int lewy, int srodek, int prawy)
    {
        int rozmiarPomocniczy = prawy - lewy + 1;

        T* pomocnicza = new T[rozmiarPomocniczy];

        int i = lewy;
        int j = srodek + 1;
        int k = 0;

        while (i <= srodek && j <= prawy)
        {
            if (tablica[i] <= tablica[j])
            {
                pomocnicza[k] = tablica[i];
                i++;
            }
            else
            {
                pomocnicza[k] = tablica[j];
                j++;
            }

            k++;
        }

        while (i <= srodek)
        {
            pomocnicza[k] = tablica[i];
            i++;
            k++;
        }

        while (j <= prawy)
        {
            pomocnicza[k] = tablica[j];
            j++;
            k++;
        }

        for (int i = 0; i < rozmiarPomocniczy; i++)
        {
            tablica[lewy + i] = pomocnicza[i];
        }

        delete[] pomocnicza;
    }

public:
    // Konstruktor
    MergeSort(T* tab, int n)
    {
        tablica = tab;
        rozmiar = n;
    }

    // Funkcja uruchamiajaca sortowanie
    void sort()
    {
        mergeSort(0, rozmiar - 1);
    }
};