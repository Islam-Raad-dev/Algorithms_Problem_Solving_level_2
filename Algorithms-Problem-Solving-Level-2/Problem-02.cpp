#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum enPrime
{
    Prime = 1,
    NotPrime = 2
};

int Read_Positive_Number(string Message)
{
    int Number;

    cout << "_________________________\n\n";
    cout << "Please Enter A Number: ";
    cin >> Number;

    return Number;
}
enPrime Check_Prime_Number(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {

        if (Number % Counter == 0)
            return enPrime::NotPrime;
    }

    return enPrime::Prime;
}

void Print_Prime_Number_Form_1_to_N(int Number)
{

    cout << "_________________________\n\n";
    cout << "Prime Number From " << 1 << " To " << Number;
    cout << " Are : \n" << endl;
    

    for (int i = 1; i <= Number; i++)
    {

        if (Check_Prime_Number(i) == enPrime::Prime)
        {
            cout << i << endl;
        }
    }
    cout << "_________________________\n\n";
}

int main()
{

    Print_Prime_Number_Form_1_to_N(Read_Positive_Number("Please Enter A Positive Number: "));

    return 0;
}