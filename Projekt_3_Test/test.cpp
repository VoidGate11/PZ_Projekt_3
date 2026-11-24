/**
 * @file test.cpp
 * @brief Zestaw testow jednostkowych Google Test dla szablonowej klasy MergeSort.
 */

#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSort.h"

 /** @brief Sprawdza zachowanie algorytmu dla tablicy juz posortowanej rosnaco. */
TEST(MergeSortTest, TablicaRosnaco)
{
    int tablica[] = { 1, 2, 3, 4, 5 };
    int oczekiwane[] = { 1, 2, 3, 4, 5 };

    MergeSort<int> sortowanie(tablica, 5);
    sortowanie.sort();

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie tablicy uporzadkowanej w odwrotnej kolejnosci (malejaco). */
TEST(MergeSortTest, TablicaMalejaco)
{
    int tablica[] = { 9, 7, 5, 3, 1 };
    int oczekiwane[] = { 1, 3, 5, 7, 9 };

    MergeSort<int> sortowanie(tablica, 5);
    sortowanie.sort();

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie tablicy o losowym ulozeniu elementow. */
TEST(MergeSortTest, TablicaLosowa)
{
    int tablica[] = { 8, 3, 5, 1, 9, 2 };
    int oczekiwane[] = { 1, 2, 3, 5, 8, 9 };

    MergeSort<int> sortowanie(tablica, 6);
    sortowanie.sort();

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie tablicy zawierajacej wylacznie liczby ujemne. */
TEST(MergeSortTest, TylkoLiczbyUjemne)
{
    int tablica[] = { -5, -1, -10, -3 };
    int oczekiwane[] = { -10, -5, -3, -1 };

    MergeSort<int> sortowanie(tablica, 4);
    sortowanie.sort();

    for (int i = 0; i < 4; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie tablicy z liczbami ujemnymi, zerem i dodatnimi. */
TEST(MergeSortTest, LiczbyUjemneIDodatnie)
{
    int tablica[] = { -3, 7, -1, 5, 0, -8 };
    int oczekiwane[] = { -8, -3, -1, 0, 5, 7 };

    MergeSort<int> sortowanie(tablica, 6);
    sortowanie.sort();

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza bezpieczna obsluge pustej tablicy bez rzucania wyjatku. */
TEST(MergeSortTest, PustaTablica)
{
    int* tablica = nullptr;

    MergeSort<int> sortowanie(tablica, 0);

    EXPECT_NO_THROW(sortowanie.sort());
}

/** @brief Sprawdza zachowanie algorytmu dla tablicy jednoelementowej. */
TEST(MergeSortTest, JedenElement)
{
    int tablica[] = { 42 };

    MergeSort<int> sortowanie(tablica, 1);
    sortowanie.sort();

    EXPECT_EQ(tablica[0], 42);
}

/** @brief Sprawdza sortowanie tablicy zawierajacej powtarzajace sie wartosci. */
TEST(MergeSortTest, Duplikaty)
{
    int tablica[] = { 4, 2, 4, 1, 2, 3 };
    int oczekiwane[] = { 1, 2, 2, 3, 4, 4 };

    MergeSort<int> sortowanie(tablica, 6);
    sortowanie.sort();

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie liczb ujemnych z wystepujacymi duplikatami. */
TEST(MergeSortTest, UjemneZDuplikatami)
{
    int tablica[] = { -2, -5, -2, -1, -5 };
    int oczekiwane[] = { -5, -5, -2, -2, -1 };

    MergeSort<int> sortowanie(tablica, 5);
    sortowanie.sort();

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie mieszanki liczb ujemnych, dodatnich i duplikatow. */
TEST(MergeSortTest, UjemneDodatnieDuplikaty)
{
    int tablica[] = { -3, 5, -3, 2, 5, -1, 2 };
    int oczekiwane[] = { -3, -3, -1, 2, 2, 5, 5 };

    MergeSort<int> sortowanie(tablica, 7);
    sortowanie.sort();

    for (int i = 0; i < 7; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza tablice dwuelementowa juz posortowana rosnaco. */
TEST(MergeSortTest, DwaElementyRosnaco)
{
    int tablica[] = { 2, 8 };
    int oczekiwane[] = { 2, 8 };

    MergeSort<int> sortowanie(tablica, 2);
    sortowanie.sort();

    for (int i = 0; i < 2; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie duzej tablicy (150 elementow) w odwrotnej kolejnosci. */
TEST(MergeSortTest, DuzaTablica)
{
    int tablica[150];
    int oczekiwane[150];

    for (int i = 0; i < 150; i++)
    {
        tablica[i] = 150 - i;
        oczekiwane[i] = i + 1;
    }

    MergeSort<int> sortowanie(tablica, 150);
    sortowanie.sort();

    for (int i = 0; i < 150; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

/** @brief Sprawdza sortowanie duzej tablicy (200 elementow) z liczbami ujemnymi, dodatnimi i duplikatami. */
TEST(MergeSortTest, DuzaTablicaZDuplikatami)
{
    int tablica[200];
    int oczekiwane[200];

    for (int i = 0; i < 200; i++)
    {
        tablica[i] = (i % 21) - 10;
    }

    for (int i = 0; i < 200; i++)
    {
        oczekiwane[i] = (i % 21) - 10;
    }

    // Sortowanie tablicy oczekiwanej
    for (int i = 0; i < 200; i++)
    {
        for (int j = i + 1; j < 200; j++)
        {
            if (oczekiwane[i] > oczekiwane[j])
            {
                int temp = oczekiwane[i];
                oczekiwane[i] = oczekiwane[j];
                oczekiwane[j] = temp;
            }
        }
    }

    MergeSort<int> sortowanie(tablica, 200);
    sortowanie.sort();

    for (int i = 0; i < 200; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}