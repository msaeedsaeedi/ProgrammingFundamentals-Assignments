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
    bool OuterDiamond, InnerDiamond, CenterBox, Not_Triangle, Not_Triangle_RowFlag = false;
    short int NotTrianlgeColumnL = 8;
    short int NotTrianlgeColumnR = 10;
    for (short int i = 1; i <= 9; i++, cout << endl)
    {
        for (short int j = 1; j <= 17; j++)
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
                Not_Triangle = (j >= 5 && j <= NotTrianlgeColumnL) || j >= NotTrianlgeColumnR;
                if (Not_Triangle)
                    cout << "*", Not_Triangle_RowFlag = true;
                else
                {
                    cout << "1";
                }
            }
            else
                cout << " ";

            OuterDiamond = 0, InnerDiamond = 0, CenterBox = 0, Not_Triangle = 0;
        }
        if (Not_Triangle_RowFlag)
            NotTrianlgeColumnL--, NotTrianlgeColumnR++;
    }
    for (short int i = 10; i <= 16; i++, cout << endl)
    {
        for (short int j = 1; j <= 17; j++)
        {
            CenterBox = (j >= 5) && (j <= 13);

            if (j == 1 || j == 17)
                cout << ((i % 2 == 0) ? ("-") : ("*"));
            else if (j == 3 || j == 15)
                cout << ((i % 2 == 0) ? ("*") : ("-"));
            else if (CenterBox)
            {
                Not_Triangle = (j >= 5 && j <= NotTrianlgeColumnL) || j >= NotTrianlgeColumnR;
                if (Not_Triangle)
                    cout << "*", Not_Triangle_RowFlag = true;
                else if (i >= 13 && j >= 10)
                {
                    cout << " ";
                }
                else
                {
                    cout << "1";
                }
            }
            else
                cout << " ";
            CenterBox = 0, Not_Triangle = 0;
        }
        if (Not_Triangle_RowFlag)
        {
            (i < 12) ? NotTrianlgeColumnL-- : NotTrianlgeColumnL++;
            (i < 12) ? NotTrianlgeColumnR++ : NotTrianlgeColumnR--;
        }
    }
    for (short int i = 8; i >= 1; i--, cout << endl)
    {
        for (short int j = 1; j <= 17; j++)
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