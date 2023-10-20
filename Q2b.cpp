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
    int size = 7;

    bool OuterDiamond, InnerDiamond, CenterBox, Not_CentralDiamond, EmptyTriangle;
    int width = (2 * size + 7);
    int height = (4 * size + 4);
    for (short int row = 1; row <= height; row++, cout << endl)
    {
        for (short int col = 1, n = 0; col <= width; col++)
        {
            OuterDiamond = ((row + col) == (size + 5)) || ((col - (size + 3)) == row);
            OuterDiamond = OuterDiamond || ((row >= (size + 4) && row <= (3 * size + 1)) && (col == 1 || col == width));
            OuterDiamond = OuterDiamond || ((row - col == 3 * size) || (row + col) == (5 * size + 8));

            InnerDiamond = (row != 1 && row < (size + 5)) && ((row + col) == (size + 7) || (col - (size + 1) == row));
            InnerDiamond = InnerDiamond || ((row >= (size + 4) && row <= (3 * size + 1)) && (col == 3 || col == width - 2));
            InnerDiamond = InnerDiamond || (row >= (3 * size + 1) && row < height) && ((row - col) == (3 * size - 2) || (row + col) == (5 * size + 6));

            CenterBox = (row >= (size + 3) && row <= (3 * size + 1)) && (col >= 5 && col <= width - 4);

            if (OuterDiamond)
                cout << ((row % 2 == 0) ? ("- ") : ("* "));
            else if (InnerDiamond)
                cout << ((row % 2 == 0) ? ("* ") : ("- "));
            else if (CenterBox)
            {
                Not_CentralDiamond = (col <= ((size <= 4) ? (size + 3) : (2 * size - 2))) && ((row + col) <= (2 * size + 6));
                Not_CentralDiamond = Not_CentralDiamond || ((col - 2) >= row);
                Not_CentralDiamond = Not_CentralDiamond || ((col + (2 * size - 2)) <= row);
                Not_CentralDiamond = Not_CentralDiamond || ((row + col) >= ((4 * size + 6)));

                if (Not_CentralDiamond)
                    cout << "* ";
                else
                {
                    EmptyTriangle = (row >= (2 * size + 3) && col >= (size + 5));
                    if (EmptyTriangle)
                        cout << "  ";
                    else
                    {
                        if ((row + col - (size + 11)) <= (row - 7))
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