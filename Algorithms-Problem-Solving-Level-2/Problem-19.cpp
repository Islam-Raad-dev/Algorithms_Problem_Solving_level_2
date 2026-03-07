// This Program About Print Random Number From - To

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 20) << endl;
    cout << RandomNumber(1, 30) << endl;

    return 0;
}