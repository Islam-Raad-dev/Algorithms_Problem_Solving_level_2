#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Fill_Array(int arr[100], int &arrLength)
{
    arrLength = 6;

    arr[0] = 10;
    arr[1] = 30;
    arr[2] = 20;
    arr[3] = 10;
    arr[4] = 20;
    arr[5] = 30;
}

void Print_Array(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

bool Is_Palindrome_Array(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] != arr[Length - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[100], Length = 0;

    Fill_Array(arr, Length);

    cout << "\nArray Elements: ";
    Print_Array(arr, Length);

    if (Is_Palindrome_Array(arr, Length))
        cout << "\n  Yes , It is a PalindromNumber\n";
    else
        cout << "\n No , It is Not a Palindrom Number.\n";

    return 0;
}