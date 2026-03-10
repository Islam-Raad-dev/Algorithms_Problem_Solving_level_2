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