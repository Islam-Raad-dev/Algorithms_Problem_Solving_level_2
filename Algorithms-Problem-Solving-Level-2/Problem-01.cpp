#include <iostream>
using namespace std;

void PrintTableheader()
{

    cout << "\n\n\t\t Mulipaiation Table From 1 to 10\n\n";
    cout << "\t";

    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n___________________________________________________________________________________\n";
}

string ColumSperator(int i)
{

    if (i < 10)
        return "    |";
    else
        return "   |";
}

void PrintMuliplactionTable()
{

    PrintTableheader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumSperator(i) << "\t";

        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main()
{

    PrintMuliplactionTable();

    return 0;
}