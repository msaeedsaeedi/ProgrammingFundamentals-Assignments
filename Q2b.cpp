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
    /*
        ** Everything Depends on Size**
        
        Size of Shape
    */
    int size = 7;

    /*
        OuterDiamond        -> Outer Diamond Shape
        InnerDiamond        -> Diamond inside (Outer Diamond) 
        CenterBox           -> Centeral Box with Aestrisk's and number series
        Not_CentralDiamond  -> Area Excluding Most Central Diamond
        EmptyTriangle       -> Empty Triangle Inside Most Central Diamond
    */
    bool OuterDiamond, InnerDiamond, CenterBox, Not_CentralDiamond, EmptyTriangle;

    /*
        width   -> Calculated Width of Shape based on size
        height  -> Calculated Height of Shape based on size
    */
    int width = (2 * size + 7);
    int height = (4 * size + 4);

    /*
        ** Print Shape **

        Iterate on every row of Shape until height
        
    */
    for (short int row = 1; row <= height; row++, cout << endl)
    {

        /*
            Iterate on every column of shape until width
        */
        for (short int col = 1, n = 0; col <= width; col++)
        {
            /*
                Conditions to print outer Diamond
                    - These are calculated from equations on line then Applying boolean algebra
            */
            OuterDiamond = ((row + col) == (size + 5)) || ((col - (size + 3)) == row);
            OuterDiamond = OuterDiamond || ((row >= (size + 4) && row <= (3 * size + 1)) && (col == 1 || col == width));
            OuterDiamond = OuterDiamond || ((row - col == 3 * size) || (row + col) == (5 * size + 8));

            /*
                Conditions to print Inner Diamond
                    - These are calculated from equations on line then Applying boolean algebra
            */
            InnerDiamond = (row != 1 && row < (size + 5)) && ((row + col) == (size + 7) || (col - (size + 1) == row));
            InnerDiamond = InnerDiamond || ((row >= (size + 4) && row <= (3 * size + 1)) && (col == 3 || col == width - 2));
            InnerDiamond = InnerDiamond || (row >= (3 * size + 1) && row < height) && ((row - col) == (3 * size - 2) || (row + col) == (5 * size + 6));

            /*
                Condition Check weather it is central box area or not
                    - These are calculated from equations on line then Applying boolean algebra
            */
            CenterBox = (row >= (size + 3) && row <= (3 * size + 1)) && (col >= 5 && col <= width - 4);

            /*
                Print '-' or '*' based on Shape row
            */
            if (OuterDiamond)
                cout << ((row % 2 == 0) ? ("- ") : ("* "));
            else if (InnerDiamond)
                cout << ((row % 2 == 0) ? ("* ") : ("- "));
            else if (CenterBox)
            {
                /*
                    Conditions to Check weather it is central diamond or not
                        - These are calculated from equations on line then Applying boolean algebra
                */
                Not_CentralDiamond = (col <= ((size <= 4) ? (size + 3) : (2 * size - 2))) && ((row + col) <= (2 * size + 6));
                Not_CentralDiamond = Not_CentralDiamond || ((col - 2) >= row);
                Not_CentralDiamond = Not_CentralDiamond || ((col + (2 * size - 2)) <= row);
                Not_CentralDiamond = Not_CentralDiamond || ((row + col) >= ((4 * size + 6)));

                /*
                    Print Aestrisk Excluding Central Diamond
                */
                if (Not_CentralDiamond)
                    cout << "* ";
                else
                {
                    /*
                        leave space for empty triangle
                    */
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