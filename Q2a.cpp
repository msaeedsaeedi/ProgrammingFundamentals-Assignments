/*
    Assignment # 2 - Q2-A

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
using namespace std;

int main()
{
    1, 4, 7, 10, 13;
    int space = 25;
    for (int i = 1; i <= 15; i++, cout << "*" << endl)
    {
        for (int j = 1; j <= space; j++)
            cout << " ";
        for (int j = 1; j <= 6; j++)
            if ((i - 1) % 3 == 0 || j == 1)
                cout << "*";
            else
                cout<<" ";
        for (int j = 1; j <= 32 - space - 7; j++)
            cout << " ";
        if (i % 3 == 0)
            space -= 5;
    }
    for (int i = 1; i <= 32; i++)
        cout << "*";
    cout << endl;
    return 0;
}