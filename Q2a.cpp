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
    int space = 25, counter = 0;
    for (int i = 1; i <= 16; i++, cout << endl)
    {
        for (int j = 1; j <= 32; j++)
            if (j == 32 || i == 16 || j == space + 1 || (counter <= 5 && counter > 0))
                cout << "*", counter++;
            else
                cout << " ";
        if (i % 3 == 0)
            space -= 5, counter = 0;
    }
    cout << endl;
    return 0;
}