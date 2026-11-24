#pragma once

/**
 * @file MergeSort.h
 * @brief Definicja szablonowej klasy realizujacej algorytm sortowania przez scalanie.
 */

 /**
  * @brief Szablonowa klasa sortujaca tablice metoda dziel i zwyciezaj (Merge Sort).
  *
  * Klasa pozwala na sortowanie tablic dowolnego typu liczbowego (np. int, long int,
  * float, double), o ile typ ten wspiera operatory porownania (<=) oraz przypisania (=).
  *
  * @tparam T Typ elementow przechowywanych w sortowanej tablicy.
  */
template <typename T>
class MergeSort
{
private:
    /** @brief Wskaznik na sortowana tablice elementow. */
    T* tablica;

    /** @brief Liczba elementow w sortowanej tablicy. */
    int rozmiar;

    /**
     * @brief Rekurencyjnie dzieli wskazany zakres tablicy na mniejsze czesci i scala je.
     *
     * @param lewy Indeks poczatkowy aktualnie przetwarzanego zakresu.
     * @param prawy Indeks koncowy aktualnie przetwarzanego zakresu.
     */
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

    /**
     * @brief Scala dwie sasiednie, posortowane juz podtablice w jeden uporzadkowany fragment.
     *
     * Wykorzystuje tymczasowa tablice alokowana dynamicznie, a po przepisaniu
     * elementow z powrotem do tablicy docelowej zwalnia zajeta pamiec.
     *
     * @param lewy Indeks poczatkowy lewej podtablicy.
     * @param srodek Indeks koncowy lewej podtablicy (prawa zaczyna sie od srodek + 1).
     * @param prawy Indeks koncowy prawej podtablicy.
     */
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
    /**
     * @brief Konstruktor inicjalizujacy obiekt sortujacy.
     *
     * @param tab Wskaznik na tablice przeznaczona do posortowania.
     * @param n Liczba elementow w tablicy.
     */
    MergeSort(T* tab, int n)
    {
        tablica = tab;
        rozmiar = n;
    }

    /**
     * @brief Uruchamia sortowanie calej tablicy w kolejnosci rosnacej.
     *
     * Dla tablic pustych (rozmiar <= 0) lub jednoelementowych bezpiecznie
     * konczy dzialanie bez modyfikacji danych.
     */
    void sort()
    {
        mergeSort(0, rozmiar - 1);
    }
};