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

    for (int i = 0; i <= arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int &arrLength)
{

    for (int i = 0; i <= arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int MinNumberInArray(int arr[100], int arrLength)
{
    int Min = 0;
    Min = arr[0];

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }

    return Min;
}

int main()
{

    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumber(arr, arrLength);

    cout << "\nArray Element: ";
    PrintArray(arr, arrLength);

    cout << "\nMin Number Is: " << MinNumberInArray(arr, arrLength) << endl;

    return 0;
}