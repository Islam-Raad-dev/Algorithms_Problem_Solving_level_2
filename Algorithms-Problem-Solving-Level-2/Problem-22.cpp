#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{

    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void ReadArray(int arr[100], int &arrLength)
{

    cout << "\nEnter Number Of Element: ";
    cin >> arrLength;

    cout << "\nEnter Array Element: \n";

    for (int i = 0; i <= arrLength; i++)
    {

        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }

    cout << endl;
}

void PrintArray(int arr[100], int &arrLength)
{

    for (int i = 0; i <= arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int TimesRepaeted(int Number, int arr[100], int &arrLength)
{

    int Count = 0;

    for (int i = 0; i <= arrLength; i++)
    {
        if (Number == arr[i])
        {
            Count++;
        }
    }

    return Count;
}

int main()
{

    int arr[100], arrLength, NumberToCheck;

    ReadArray(arr, arrLength);

    NumberToCheck = ReadPositiveNumber("Please Enter The Number You Want To Check: ");

    cout << "\nOriginal Array: ";
    PrintArray(arr, arrLength);

    cout << "\nNumber " <<"("<< NumberToCheck<<")";
    cout << " Is Repeated ";
    cout <<"("<<TimesRepaeted(NumberToCheck, arr, arrLength)<<")" << " Times\n";

    return 0;
}