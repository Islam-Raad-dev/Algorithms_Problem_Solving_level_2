#include <iostream>
#include <cmath>
#include <cstdlib>
#include<time.h>
using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

enPrimeNotPrime CheckPrime(int Number)
{

    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {

        if (Number % Counter == 0)
        {
            return enPrimeNotPrime::NotPrime;
        }
    }

    return enPrimeNotPrime::Prime;
}

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

void FillArrayWithRandomNumber(int arr[100], int &arrLength)
{

    cout << "\nEnter Number Of Element: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int &arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void CopyOnlyPrimeNumber(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{

    int Counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {

            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }
    arr2Length = --Counter;
}

int main()
{

    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumber(arr, arrLength);

    int arr2[100], arr2Length;
    CopyOnlyPrimeNumber(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 Element: ";
    PrintArray(arr, arrLength);

    cout << "\nPrime Number In Array 2: ";
    PrintArray(arr2, arr2Length);

    return 0;
}