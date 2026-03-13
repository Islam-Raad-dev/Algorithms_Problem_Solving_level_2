#include <iostream>
#include <cmath>
using namespace std;

float Read_Number()
{
    short Number;

    cout << "\nPlease Enter A Float Number: ";
    cin >> Number;

    return Number;
}

float Get_Fration_Part(float Number)
{
    return Number - int(Number);
}

float My_Round(float Number)
{

    int InPart;

    InPart = int(Number);

    float FractionPart = Get_Fration_Part(Number);

    if (abs(FractionPart) >= .5)
    {
        if (Number > 0)
            return ++InPart;
        else
            return --InPart;
    }
    else
    {
        return InPart;
    }
}

int main()
{

    float Number = Read_Number();

    cout << "\nMy Round Result:" << My_Round(Number) << endl;

    cout << "\nC++ Round Result:" << round(Number) << endl;

    return 0;
}