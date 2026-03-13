#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random_Number(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill_Array_With_Random_Numbers(int arr[200], int &arrLength)
{
    cout << "\nEnter Number of Elements: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = Random_Number(-100, 100);
}

void Print_Array(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int Count_Positive_Numbers(int arr[200], int arrLength)
{

    int Counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0)
        {
            Counter++;
        }
    }

    return Counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[200];
    int arrLength;

    Fill_Array_With_Random_Numbers(arr, arrLength);

    cout << "\nArray Elements:";
    Print_Array(arr, arrLength);

    cout << "\nPositive Numbers Count Is:";
    cout << Count_Positive_Numbers(arr, arrLength) << endl;

    return 0;
}