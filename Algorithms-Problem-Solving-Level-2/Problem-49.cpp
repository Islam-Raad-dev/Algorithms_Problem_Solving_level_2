#include <iostream>
#include<cmath>
using namespace std;


float Get_Fraction_Part(float Number)
{
    return Number - int(Number);
}

int My_Ceil(float Number)
{

    if (abs(Get_Fraction_Part(Number)) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number); 
    }
    else
        return Number; 
}

float Read_Number()
{
    float Number; 

  
    cout << "Please enter a number? ";
    cin >> Number;  

    return Number;
}


int main()
{
    float Number = Read_Number();

  
    cout << "My MyCeil Result : " << My_Ceil(Number) << endl;

    cout << "C++ Ceil Result: " << ceil(Number) << endl;

    return 0;
}