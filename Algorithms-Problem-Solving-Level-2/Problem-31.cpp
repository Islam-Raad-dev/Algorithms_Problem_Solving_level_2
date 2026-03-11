#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int Read_Positive_Number(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

int Random_Number(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

void Swap(int &A, int &B)
{

    int Temp;

    Temp = A;
    A = B;
    B = Temp;
}

void Fill_Array_With_1_To_N(int arr[100], int &arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = i + 1;
    }
}

void Shuffle_Array(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[Random_Number(1, arrLength) - 1], arr[Random_Number(1, arrLength) - 1]);
    }
}

void Print_Array(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = Read_Positive_Number("Please Enter Number Of Element: ");

    Fill_Array_With_1_To_N(arr, arrLength);

    cout << "\nArray Element Before Shuffle: ";
    Print_Array(arr, arrLength);

    Shuffle_Array(arr, arrLength);

    cout << "\nArray Element After Shuffle: ";
    Print_Array(arr, arrLength);

    return 0;
}