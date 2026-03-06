#include <iostream>
#include <string>
using namespace std;

string ReadUserName(string Massege)
{

    string Text;

    cout << Massege;
    getline(cin, Text);

    return Text;
}

string EncryptText(string Text, short EncryptonKey)
{

    for (int i = 0; i <= Text.length(); i++)
    {

        Text[i] = char((int)Text[i] + EncryptonKey);
    }

    return Text;
}

string DecryptText(string Text, short EncryptonKey)
{

    for (int i = 0; i <= Text.length(); i++)
    {

        Text[i] = char((int)Text[i] - EncryptonKey);
    }

    return Text;
}

int main()
{

    const short EncryptionKey = 2;

    string Text = ReadUserName("Please Enter Your Name: ");
    string TextAfterEncyption = EncryptText(Text, EncryptionKey);
    string TextAfterDecyption = DecryptText(TextAfterEncyption, EncryptionKey);

    cout << "\nText Before Encryption = " << Text << endl;
    cout << "Text After Encryption = " << TextAfterEncyption << endl;
    cout << "Text After Decryption = " << TextAfterDecyption << endl;

    return 0;
}