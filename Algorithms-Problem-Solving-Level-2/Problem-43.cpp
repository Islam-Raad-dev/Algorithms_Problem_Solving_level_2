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
    cout << "\nEnter Number of Elements: ";
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

int Count_Even_Numbers(int arr[100], int arrLength)
{

    int Counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
        {
            Counter++;
        }
    }

    return Counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength;

    Fill_Array_With_Random_Numbers(arr, arrLength);

    cout << "\nArray Elements:";
    Print_Array(arr, arrLength);

    cout << "\nOdd Numbers Count Is:";
    cout << Count_Even_Numbers(arr, arrLength) << endl;

    return 0;
}