#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSort.h"

TEST(MergeSortTest, SortowanieTablicyInt)
{
    int tablica[] = { 8, 3, 5, 1, 9, 2 };
    int rozmiar = 6;

    int oczekiwanyWynik[] = { 1, 2, 3, 5, 8, 9 };

    MergeSort<int> sortowanie(tablica, rozmiar);

    sortowanie.sort();

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwanyWynik[i]);
    }
}