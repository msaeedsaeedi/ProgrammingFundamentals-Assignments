/*
    Assignment # 2 - Q2-B

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
/*
    Information :
        Rows    :   12+12 = 24
        Columns :   8+1+8 = 17

        Center Box Row Start:   8
        Center Box Row End  :   16
        Center Box Col Start:   5
        Center Box Col End  :   13

*/
#include <iostream>
using namespace std;

int main()
{
    bool OuterDiamond, InnerDiamond, CenterBox;

    for (int i = 1; i <= 9; i++, cout << endl)
    {
        for (int j = 1; j <= 17; j++)
        {
            OuterDiamond = (j - 8) == i || (i + j) == 10;

            InnerDiamond = (i != 1) && ((i + j) == 12 || (j - 6 == i));

            if (OuterDiamond)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else if (InnerDiamond)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else
                cout << " ";

            OuterDiamond = 0, InnerDiamond = 0;
        }
    }
    for (int i = 1; i <= 6; i++, cout << endl)
    {
        for (int j = 1; j <= 17; j++)
        {
            if (j == 1 || j == 17)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else if (j == 3 || j == 15)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else
                cout << " ";
        }
    }
    for (int i = 9; i >= 1; i--, cout << endl)
    {
        for (int j = 1; j <= 17; j++)
        {
            OuterDiamond = (j - 8) == i || (i + j) == 10;

            InnerDiamond = (i != 1) && ((i + j) == 12 || (j - 6 == i));

            if (OuterDiamond)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else if (InnerDiamond)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else
                cout << " ";

            OuterDiamond = 0, InnerDiamond = 0;
        }
    }
    return 0;
}