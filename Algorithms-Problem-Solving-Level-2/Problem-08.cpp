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

int CountDigitFrequency(short DigitToCheck, int Number)
{

    int FreqCount = 0, Remainder = 0;

    while (Number > 0)
    {

        Remainder = Number % 10;
        Number = Number /  10;

        if (DigitToCheck == Remainder)
        {
            FreqCount++;
        }
    }

    return FreqCount;
}

int main()
{

    int Number = ReadPositiveNumber("Please Enter A Positive Number: ");
    short DigitToCheck = ReadPositiveNumber("Please Enter One Digit To Check: ");

    cout << DigitToCheck<<" " << "Frequency is: " << CountDigitFrequency(DigitToCheck, Number) << " Times\n";

    return 0;
}