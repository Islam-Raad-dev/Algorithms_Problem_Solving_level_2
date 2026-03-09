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

int RevreseNumber(int Number)
{

    int Remainder = 0, Number2 = 0;

    while (Number > 0)
    {

        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }

    return Number2;
}

bool CheckPalindromNumber(int Number)
{

    return Number == RevreseNumber(Number);
}

int main()
{

    if (CheckPalindromNumber(ReadPositiveNumber("Please Enter A Positive Number: ")))
        cout << "\n  Yes , It is a PalindromNumber\n";
    else
        cout << "\n No , It is Not a Palindrom Number.\n";

    return 0;
}