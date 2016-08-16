#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long int64;

void QuickSort(int* data, int l, int r, int64& comparisonCount, int problemNumber)
{
    if (r <= l)
    {
        return;
    }
    comparisonCount += (r - l);

    if (problemNumber == 2)
    {
        swap(data[l], data[r]);
    }
    else if (problemNumber == 3)
    {
        int three[3];
        int index[3];
        index[0] = l;
        index[1] = r;
        index[2] = (l + r)/2;
        for (int i = 0; i < 3; i++)
        {
            three[i] = data[index[i]];
        }
        for (int p = 0; p < 3; p++)
        {
            for (int q = p + 1; q < 3; q++)
            {
                if (three[p] > three[q])
                {
                    swap(three[p], three[q]);
                    swap(index[p], index[q]);
                }
            }
        }
        swap(data[l], data[index[1]]);
    }
    int p = data[l];
    int i = l + 1;
    for (int j = l + 1; j <= r; j++)
    {
        if (data[j] < p)
        {
            swap(data[j], data[i]);
            i++;
        }
    }
    swap(data[l], data[i - 1]);
    QuickSort(data, l, i - 2, comparisonCount, problemNumber);
    QuickSort(data, i, r, comparisonCount, problemNumber);
}

int main()
{
    ifstream fin("F:/QuickSort.txt");
    const int size = 10000;
    int source[size];
    int data[size];
    for (int i = 0; i < size; i++)
    {
        fin >> source[i];
    }
    fin.close();
    for (int problemNumber = 1; problemNumber <= 3; problemNumber++)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = source[i];
        }
        int64 comparisonCount = 0;
        QuickSort(data, 0, size - 1, comparisonCount, problemNumber);
        cout << comparisonCount << endl;
    }
}
