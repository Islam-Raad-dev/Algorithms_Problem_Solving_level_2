#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength){

    cout<<"\nEnter Number Of Element: ";
    cin>>arrLength;

    for(int i = 0; i <= arrLength; i++){
        arr[i] = RandomNumber(1, 100);
    }

}

void PrintArray(int arr[100], int& arrLength)
{

    for (int i = 0; i <= arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){

    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumber(arr,arrLength);

    cout<<"\nArray Element: ";
    PrintArray(arr, arrLength);


    return 0;
}