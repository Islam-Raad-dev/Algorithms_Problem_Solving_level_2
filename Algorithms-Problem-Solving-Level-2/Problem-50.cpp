#include <iostream>
#include <cmath>
using namespace std;

float Read_Number()
{
    short Number;

    cout << "\n Please Enter A Float Number: ";
    cin >> Number;

    return Number;
}

float My_Sqrt(float Number)
{
    return pow(Number, 0.5);
}

int main()
{

    float Number = Read_Number();

    cout << "\nMy Sqrt Result:" << My_Sqrt(Number ) << endl;

    cout << "\nC++ Sqrt Result:" << sqrt(Number) << endl;

    return 0;
}