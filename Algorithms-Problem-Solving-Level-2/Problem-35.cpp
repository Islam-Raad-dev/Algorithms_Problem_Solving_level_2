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

void Print_Array(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int Read_Number()
{
    int Number;

    cout << "\nPlease Enter A Number To Search For: ";
    cin >> Number;

    return Number;
}

