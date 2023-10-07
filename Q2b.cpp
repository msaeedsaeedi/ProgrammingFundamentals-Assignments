/*
    Assignment # 2 - Q2-B

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
using namespace std;

int main()
{
    bool OuterDiamond, InnerDiamond, CenterBox, Not_CentralDiamond, EmptyTriangle;

    for (short int row = 1; row <= 24; row++, cout << endl)
    {
        for (short int col = 1, n = 0; col <= 17; col++)
        {
            OuterDiamond = ((col - 8) == row || (row + col) == 10);
            OuterDiamond = OuterDiamond || ((row >= 9 && row <= 16) && (col == 1 || col == 17));
            OuterDiamond = OuterDiamond || (col == (row - 15) || (row + col) == 33);

            InnerDiamond = (row != 1 && row < 10) && ((row + col) == 12 || (col - 6 == row));
            InnerDiamond = InnerDiamond || ((row >= 9 && row <= 16) && (col == 3 || col == 15));
            InnerDiamond = InnerDiamond || (row >= 16 && row < 24) && ((row + col) == 31 || col == (row - 13));

            CenterBox = (row >= 8 && row <= 16) && (col >= 5 && col <= 13);

            if (OuterDiamond)
                cout << ((row % 2 == 0) ? ("- ") : ("* "));
            else if (InnerDiamond)
                cout << ((row % 2 == 0) ? ("* ") : ("- "));
            else if (CenterBox)
            {
                Not_CentralDiamond = (col <= 8) && ((row + col) <= 16);
                Not_CentralDiamond = Not_CentralDiamond || ((col - 2) >= row);
                Not_CentralDiamond = Not_CentralDiamond || ((col + 8) <= row);
                Not_CentralDiamond = Not_CentralDiamond || ((row + col) >= 26);

                if (Not_CentralDiamond)
                    cout << "* ";
                else
                {
                    EmptyTriangle = (row >= 13 && col >= 10);
                    if (EmptyTriangle)
                        cout << "  ";
                    else
                    {
                        if ((row + col - 16) <= (row - 7))
                            cout << ++n << " ";
                        else
                            cout << --n << " ";
                    }
                }
            }
            else
                cout << "  ";
        }
    }
    return 0;
}