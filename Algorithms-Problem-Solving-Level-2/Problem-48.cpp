#include <iostream>
#include <cmath>
using namespace std;

float Read_Number()
{
    int Number;

    cout << "\nPlease Enter A Float Number: ";
    cin >> Number;

    return Number;
}

float My_Floor(float Number){

    if (Number > 0)
    {
        return int(Number);
    }
    else
    {
        return int (Number) - 1;
    }
}

int main()
{

    float Number = Read_Number();

    cout << "\nMy Floor Result:" << My_Floor(Number) << endl;

    cout << "\nC++ Floor Result:" << floor(Number) << endl;

    return 0;
}