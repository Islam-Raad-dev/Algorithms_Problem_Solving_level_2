#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Random_Number(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill_Array(int arr[100], int &arrLength)
{
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 90;
    arr[9] = 90;
}

void Print_Array(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int Find_Number_Position_In_Array(int Number, int arr[100], int arrLength)
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

bool Is_Number_In_Array(int Number, int arr[100], int arrLength)
{
    return (Find_Number_Position_In_Array(Number, arr, arrLength) != -1);
}

void Add_Array_Element(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void Copy_Disinct_Number_To_Array(int arrSource[100], int arrDestination[100], int SourceLength, int &arrDestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!Is_Number_In_Array(arrSource[i], arrDestination, arrDestinationLength))
        {
            Add_Array_Element(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

int main()
{
    int arrSource[100], SourceLength = 0;
    int arrDestination[100], DestinationLength = 0;

    Fill_Array(arrSource, SourceLength);

    cout << "\nArray 1 Elements: ";
    Print_Array(arrSource, SourceLength);

    Copy_Disinct_Number_To_Array(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\nArray 2 Distinct Elements: ";
    Print_Array(arrDestination, DestinationLength);

    return 0;
}