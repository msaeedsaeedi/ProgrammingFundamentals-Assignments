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
    int n = -1, x = -1, y = 0;

    /*
        Input Validation
    */
    do
    {
        cout << "Enter X [0,x] : ";
        cin >> x;
        if (cin.fail())
            cin.clear(), x = -1;
        cin.ignore(10, '\n');

    } while (x < 0);

    /*
        Input Validation
    */
    do
    {
        cout << "Enter N [1,n] : ";
        cin >> n;
        if (cin.fail())
            cin.clear(), n = -1;
        cin.ignore(10, '\n');

    } while (n <= 0);

    system("clear");

    /*
        Check if plot can be drawn or not
    */
    if (x == 0 && n == 0)
    {
        cout << "Graph can't be displayed due to low points" << endl;
        return 1;
    }

    /*
        calculate Y value
    */
    y = pow(x, n) + pow(x, n - 1);

    /*
        Print Graph
    */
    cout << "   |    " << endl;
    for (int i = y; i >= 0; i -= 1, cout << endl)
    {
        if (i % 2 == 0)
        {
            cout << setw(2) << setfill('0') << i << " |";

            for (int j = 0; j <= x; j++)
            {
                /*
                    calculate Y value
                */
                y = pow(j, n) + pow(j, n - 1);

                /*
                    Print of related point
                */
                if (y == i)
                    cout << "    *";
                else
                    cout << "     ";
            }
        }
        else
            cout << "   |";
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