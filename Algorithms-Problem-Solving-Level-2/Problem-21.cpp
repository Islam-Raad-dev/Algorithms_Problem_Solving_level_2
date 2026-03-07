#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message)
{

    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

char GetRandomCharcter(enCharType CharType)
{

    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122));
        break;

    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));
        break;

    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));
        break;

    case enCharType::Digit:
        return char(RandomNumber(48, 57));
        break;

    default:
        break;
    }
}

string GenrateWord(enCharType CharType, short Length)
{

    string Word;

    for (int i = 1; i <= Length; i++)
    {

        Word = Word + GetRandomCharcter(CharType);
    }

    return Word;
}

string GenrateKey()
{
    string Key = "";

    Key = GenrateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenrateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenrateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenrateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void GenrateKeys(short NumberOfKeys)
{

    cout << "\n";
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key " << "[" << i << "]" << " : ";
        cout << GenrateKey() << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    GenrateKeys(ReadPositiveNumber("Please Enter How Many Key To Genrate: "));

    return 0;
}