#include <iostream>
#include <string>
using namespace std;

string ReadPasswordFromUser(string Massege)
{

    string Password;

    cout << Massege;
    cin >> Password;

    return Password;
}

bool GuessPassword(string OringnalPassword)
{

    cout << "\n";
    string word = "";
    int Counter = 0;

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int y = 65; y <= 90; y++)
            {

                Counter++;

                word = word + char(i);
                word = word + char(j);
                word = word + char(y);

                cout << "Trail Number [" << Counter << "]" << word << endl;

                if (word == OringnalPassword)
                {
                    cout << "\nPassword is " << word << "\n";
                    cout << "Found After " << Counter << " Trails\n";
                    return true;
                }
                word = "";
            }
        }
    }
    cout << "\n_____________________________________________________\n";
}

int main()
{
    GuessPassword(ReadPasswordFromUser("Please Enter A 3 Letter Password: "));

    return 0;
}