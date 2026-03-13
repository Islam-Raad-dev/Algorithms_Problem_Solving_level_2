#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

float Read_Number()
{
    short Number;

    cout << "\nPlease Enter A Number: ";
    cin >> Number;

    return Number;
}

float My_ABS(int Number)
{

    if (Number > 0)
        return Number;

    else
        return Number * -1;
}

int main()
{

    int Number = Read_Number();

    cout << "\nMy ABS Result:" << My_ABS(Number) << endl;

    cout << "\nC++ ABS Result:" << abs(Number) << endl;

    return 0;
}