#include <iostream>
#include <string>
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

int PrintPateern(int Number)
{

    for (int i = Number; i >= 1; i--)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << i;
        }

        cout << "\n";
    }
}

int main()
{

    PrintPateern(ReadPositiveNumber("Please Enter Number: "));

    return 0;
}