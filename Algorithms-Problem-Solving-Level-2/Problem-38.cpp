#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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

void Copy_Odd_Numbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arrSource[i] % 2 != 0)
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
    Copy_Odd_Numbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 Elements:\n";
    Print_Array(arr, arrLength);

    cout << "\nArray 2 Odd Numbers:\n";
    Print_Array(arr2, arr2Length);

    return 0;
}
