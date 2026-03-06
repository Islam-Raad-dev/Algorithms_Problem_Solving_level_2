#include <iostream>
#include <string>
using namespace std;

void PrintWordFromAAAToZZZ()
{

    cout << "\n";
    string word = "";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int y = 65; y <= 90; y++)
            {

                word = word + char(i);
                word = word + char(j);
                word = word + char(y);

                cout << word << endl;

                word = "";
            }
        }
    }
    cout << "\n______________________________________________________\n";
}

int main()
{
    PrintWordFromAAAToZZZ();

    return 0;
}