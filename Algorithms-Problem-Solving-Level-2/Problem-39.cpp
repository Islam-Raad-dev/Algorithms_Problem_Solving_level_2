#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

enum enPrime
{
    Prime = 1,
    NotPrime = 2
};

int Random_Number(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill_Array_With_Random_Numbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of Elements: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = Random_Number(1, 100);
}

void Print_Array(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void Add_Array_Element(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

enPrime Check_Prime_Number(int Number)
{
    if (Number <= 1)
        return enPrime::NotPrime;

    int M = round(Number / 2.0);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrime::NotPrime;
    }

    return enPrime::Prime;
}

void Copy_Prime_Numbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (Check_Prime_Number(arrSource[i]) == enPrime::Prime)
        {
            Add_Array_Element(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = 0, arr2Length = 0;

    Fill_Array_With_Random_Numbers(arr, arrLength);

    int arr2[100];
    Copy_Prime_Numbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 Elements:\n";
    Print_Array(arr, arrLength);

    cout << "\nArray 2 Prime Numbers:\n";
    Print_Array(arr2, arr2Length);

    return 0;
}