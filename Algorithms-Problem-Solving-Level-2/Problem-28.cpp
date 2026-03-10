#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[i];
    }
}

int main()
{

    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumber(arr, arrLength);

    int arr2[100];
    CopyArray(arr, arr2, arrLength);

    cout << "\nArray 1 Element: ";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Element: ";
    PrintArray(arr2, arrLength);

    return 0;
}