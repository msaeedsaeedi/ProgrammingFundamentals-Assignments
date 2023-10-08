/*
    Assignment # 2 - Q4

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int n = 0, x = 0, y = 0;
    cout << "Enter X : ";
    cin >> x;
    cout << "Enter N : ";
    cin >> n;
    system("clear");

    if (x == 0 && n == 0)
    {
        cout << "Graph can't be displayed due to low points" << endl;
        return 1;
    }

    y = pow(x, n) + pow(x, n - 1);
    cout << "   |    " << endl;
    for (int i = y; i >= 0; i -= 1, cout << endl)
    {
        if (i % 2 == 0)
            cout << setw(2) << setfill('0') << i << " |";
        else
            cout << "   |";
        for (int j = 0; j <= x; j++)
        {
            y = pow(j, n) + pow(j, n - 1);
            if (y == i)
                cout << "    *";
            else
                cout << "     ";
        }
    }
    cout << "___|____";
    for (int i = 0; i <= x + 1; i++)
        cout << "____";
    cout << "\n   |\n   |";
    for (int i = 0; i <= x; i++)
    {
        cout << "    " << i;
    }
    cout << "\n"
         << endl;
    return 0;
}