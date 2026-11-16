#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSort.h"

// 1. Tablica juz posortowana rosnaco
TEST(MergeSortTest, TablicaRosnaco)
{
    int tablica[] = { 1, 2, 3, 4, 5 };
    int oczekiwane[] = { 1, 2, 3, 4, 5 };

    MergeSort<int> sortowanie(tablica, 5);
    sortowanie.sort();

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 2. Tablica posortowana malejaco
TEST(MergeSortTest, TablicaMalejaco)
{
    int tablica[] = { 9, 7, 5, 3, 1 };
    int oczekiwane[] = { 1, 3, 5, 7, 9 };

    MergeSort<int> sortowanie(tablica, 5);
    sortowanie.sort();

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 3. Tablica losowa
TEST(MergeSortTest, TablicaLosowa)
{
    int tablica[] = { 8, 3, 5, 1, 9, 2 };
    int oczekiwane[] = { 1, 2, 3, 5, 8, 9 };

    MergeSort<int> sortowanie(tablica, 6);
    sortowanie.sort();

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 4. Tablica zawierajaca tylko liczby ujemne
TEST(MergeSortTest, TylkoLiczbyUjemne)
{
    int tablica[] = { -5, -1, -10, -3 };
    int oczekiwane[] = { -10, -5, -3, -1 };

    MergeSort<int> sortowanie(tablica, 4);
    sortowanie.sort();

    for (int i = 0; i < 4; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 5. Tablica z liczbami ujemnymi i dodatnimi
TEST(MergeSortTest, LiczbyUjemneIDodatnie)
{
    int tablica[] = { -3, 7, -1, 5, 0, -8 };
    int oczekiwane[] = { -8, -3, -1, 0, 5, 7 };

    MergeSort<int> sortowanie(tablica, 6);
    sortowanie.sort();

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 6. Pusta tablica
TEST(MergeSortTest, PustaTablica)
{
    int* tablica = nullptr;

    MergeSort<int> sortowanie(tablica, 0);

    EXPECT_NO_THROW(sortowanie.sort());
}

// 7. Tablica z jednym elementem
TEST(MergeSortTest, JedenElement)
{
    int tablica[] = { 42 };

    MergeSort<int> sortowanie(tablica, 1);
    sortowanie.sort();

    EXPECT_EQ(tablica[0], 42);
}

// 8. Tablica zawierajaca duplikaty
TEST(MergeSortTest, Duplikaty)
{
    int tablica[] = { 4, 2, 4, 1, 2, 3 };
    int oczekiwane[] = { 1, 2, 2, 3, 4, 4 };

    MergeSort<int> sortowanie(tablica, 6);
    sortowanie.sort();

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 9. Liczby ujemne z duplikatami
TEST(MergeSortTest, UjemneZDuplikatami)
{
    int tablica[] = { -2, -5, -2, -1, -5 };
    int oczekiwane[] = { -5, -5, -2, -2, -1 };

    MergeSort<int> sortowanie(tablica, 5);
    sortowanie.sort();

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 10. Liczby ujemne, dodatnie i duplikaty
TEST(MergeSortTest, UjemneDodatnieDuplikaty)
{
    int tablica[] = { -3, 5, -3, 2, 5, -1, 2 };
    int oczekiwane[] = { -3, -3, -1, 2, 2, 5, 5 };

    MergeSort<int> sortowanie(tablica, 7);
    sortowanie.sort();

    for (int i = 0; i < 7; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 11. Dwa elementy juz posortowane rosnaco
TEST(MergeSortTest, DwaElementyRosnaco)
{
    int tablica[] = { 2, 8 };
    int oczekiwane[] = { 2, 8 };

    MergeSort<int> sortowanie(tablica, 2);
    sortowanie.sort();

    for (int i = 0; i < 2; i++)
        EXPECT_EQ(tablica[i], oczekiwane[i]);
}

// 12. Duza tablica - wiecej niz 100 elementow
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

// 13. Duza tablica z liczbami ujemnymi,
// dodatnimi i duplikatami
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