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

int ReadNumber()
{
    int Number;

    cout << "\nPlease Enter A Number To Search For: ";
    cin >> Number;

    return Number;
}

int FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = Read_Positive_Number("Please Enter Number Of Elements: ");

    Fill_Array_With_Random_Numbers(arr, arrLength);

    cout << "\nArray 1 Element: ";
    Print_Array(arr, arrLength);

    int Number = ReadNumber();
    cout << "\nNumber Your Are Looking For Is: " << Number << endl;

    short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);

    if (NumberPosition == -1)
    {
        cout << "The Number Is Not Found.\n";
    }
    else
    {
        cout << "The Number Found At Position: " << NumberPosition << endl;
        cout << "The Number Found Its Order: " << NumberPosition + 1 << endl;
    }

    return 0;
}