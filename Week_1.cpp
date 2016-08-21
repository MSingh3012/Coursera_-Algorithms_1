//Made by Manpreet Singh
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef long long int64;

int64 inversion(int* input, int length);
int64 inversion(int* input, int* output, int* buffer, int begin, int end);

int64 inversion(int* input, int length)
{
    int* output = new int[length];
    int* buffer = new int[length];
    int64 result = inversion(input, output, buffer, 0, length);
    delete[] output;
    delete[] buffer;
    return result;
}

int64 inversion(int* input, int* output, int* buffer, int begin, int end)
{
    if (end - begin == 1)
    {
        output[begin] = input[begin];
        // With only one element, there is nothing to sort, and there is no inversion
        return 0;
    }
    else
    {
        assert(end - begin > 1);
        int mid = (begin + end) / 2;
        int64 inversion1 = inversion(input, buffer, output, begin, mid);
        int64 inversion2 = inversion(input, buffer, output, mid, end);
        int i = begin;
        int j = mid;
        int k = begin;
        int64 inversion3 = 0;
        while ((i < mid) || (j < end))
        {
            if (i < mid && j < end)
            {
                if (buffer[i] < buffer[j])
                {
                    output[k++] = buffer[i++];
                }
                else
                {
                    assert(buffer[i] > buffer[j]);
                    inversion3 += mid - i;
                    output[k++] = buffer[j++];
                }
            }
            else if (i < mid)
            {
                output[k++] = buffer[i++];
            }
            else
            {
                assert(j < end);
                output[k++] = buffer[j++];
            }
        }
        return inversion1 + inversion2 + inversion3;
    }
}

int main()
{
    ifstream fin("c:/users/hp pc/Desktop/IntegerArray.txt");
    const int size = 100000;
    int data[size];
    for (int i = 0; i < size; i++)
    {
        fin >> data[i];
    }
    fin.close();
    cout << inversion(data, size) << endl;
}
