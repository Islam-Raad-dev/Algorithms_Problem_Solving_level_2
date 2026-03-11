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

void Fill_Array_With_Random_Numbers(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = Random_Number(1, 100);
    }
}

void Copy_Array_In_Reverse_Order(int arrSource[100], int arrDestination[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[arrLength - 1 - i];
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
    int arrLength = Read_Positive_Number("Please Enter Number Of Elements: ");

    Fill_Array_With_Random_Numbers(arr, arrLength);

    int arr2[100];
    Copy_Array_In_Reverse_Order(arr, arr2, arrLength);

    cout << "\nArray 1 Element Before Copy: ";
    Print_Array(arr, arrLength);

    cout << "\nArray 2 Element After Copy: ";
    Print_Array(arr2, arrLength);

    return 0;
}