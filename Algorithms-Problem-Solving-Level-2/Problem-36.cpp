#include <iostream>
#include <string>
using namespace std;

int Read_Number()
{
    int Number;

    cout << "\nPlease Enter A Number: ";
    cin >> Number;

    return Number;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{

    arrLength++;
    arr[arrLength - 1] = Number;
}

void InputUserNumberInArray(int arr[100], int &arrLength)
{

    bool AddMore = true;

    do
    {
        AddArrayElement(Read_Number(), arr, arrLength);

        cout << "\nDo You Want To Add More Numbers [0]: No, [1]: Yes ?";
        cin >> AddMore;

    } while (AddMore);
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

    int arr[100];
    int arrLength = 0;

    InputUserNumberInArray(arr, arrLength);
    cout << "\nArray Length: " << arrLength << endl;

    cout << "\nArray Element: ";
    Print_Array(arr, arrLength);

    return 0;
}
