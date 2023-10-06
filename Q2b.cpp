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
    bool OuterDiamond, InnerDiamond, CenterBox, Not_PascalTriangle, Not_PascalTriangle_RowFlag = false;
    int Pascal_Coefficent = 1;
    int NotPascalColumnL = 8;
    int NotPascalColumnR = 10;
    for (int i = 1; i <= 9; i++, cout << endl)
    {
        Pascal_Coefficent = 1;
        for (int j = 1; j <= 17; j++)
        {
            OuterDiamond = (j - 8) == i || (i + j) == 10;

            InnerDiamond = (i != 1) && ((i + j) == 12 || (j - 6 == i));

            CenterBox = (i >= 8 && j >= 5) && (j <= 13);

            if (OuterDiamond)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else if (InnerDiamond)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else if (CenterBox)
            {
                Not_PascalTriangle = (j >= 5 && j <= NotPascalColumnL) || j >= NotPascalColumnR;
                if (Not_PascalTriangle)
                    cout << "*", Not_PascalTriangle_RowFlag = true;
                else
                {
                    cout << Pascal_Coefficent;
                    // Pascal_Coefficent = Pascal_Coefficent * ((i - 7) - (j - 5)) / (j - 5);
                }
            }
            else
                cout << " ";

            OuterDiamond = 0, InnerDiamond = 0, CenterBox = 0, Not_PascalTriangle = 0;
        }
        if (Not_PascalTriangle_RowFlag)
            NotPascalColumnL--, NotPascalColumnR++;
    }
    for (int i = 10; i <= 16; i++, cout << endl)
    {
        Pascal_Coefficent = 1;
        for (int j = 1; j <= 17; j++)
        {
            CenterBox = (j >= 5) && (j <= 13);

            if (j == 1 || j == 17)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else if (j == 3 || j == 15)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else if (CenterBox)
            {
                Not_PascalTriangle = (j >= 5 && j <= NotPascalColumnL) || j >= NotPascalColumnR;
                if (Not_PascalTriangle)
                    cout << "*", Not_PascalTriangle_RowFlag = true;
                else
                {
                    cout << Pascal_Coefficent;
                    // Pascal_Coefficent = Pascal_Coefficent * ((i - 7) - (j - 5)) / (j - 5);
                }
            }
            else
                cout << " ";
            CenterBox = 0, Not_PascalTriangle = 0;
        }
        if (Not_PascalTriangle_RowFlag)
            NotPascalColumnL--, NotPascalColumnR++;
    }
    for (int i = 8; i >= 1; i--, cout << endl)
    {
        for (int j = 1; j <= 17; j++)
        {
            OuterDiamond = (j - 8) == i || (i + j) == 10;

            InnerDiamond = (i != 1) && ((i + j) == 12 || (j - 6 == i));

            CenterBox = (i == 9 && j >= 5) && (j <= 13);

            if (OuterDiamond)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else if (InnerDiamond)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else if (CenterBox)
                cout << "*";
            else
                cout << " ";

            OuterDiamond = 0, InnerDiamond = 0, CenterBox = 0;
        }
    }
    return 0;
}