#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>
using namespace std;

int Read_Number()
{
    int Number;

    cout << "\nPlease Enter A Number: ";
    cin >> Number;

    return Number;
}
void Cpp_Round(){

    int Round;
    

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

    int arr[200];
    int arrLength;

    Fill_Array_With_Random_Numbers(arr, arrLength);

    cout << "\nMy ABS Result:";
    Print_Array(arr, arrLength);

    cout << "\nC++ ABS Result:";
    cout << Count_Positive_Numbers(arr, arrLength) << endl;

    return 0;
}