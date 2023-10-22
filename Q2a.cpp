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
    /*
        Stair's Step count
    */
    int steps = 5;

    /*
        Stair's Step Height
    */
    int step_height = 3;

    /*
        Stair's Step Width
    */
    int step_width = 5;

    /*
        Space before step
    */
    int space = steps * step_width, counter = 0;

    /*
        Width of Whole Stairs
    */
    int width = (step_width * (steps + 1) + 2);

    /*
        Height of Whole Stairs
    */
    int height = (steps * step_height + 1);

    /*
        Print Stairs
    */
    for (int i = 1; i <= height; i++, cout << endl)
    {
        for (int j = 1; j <= width; j++)
            /*
                j == width                              -> Print Right Line
                i == height                             -> Print Bottom Line
                j == space + 1                          -> Print Step Height
                counter <= step_width && counter > 0    -> Print Step Width
             */
            if (j == width || i == height || j == space + 1 || (counter <= step_width && counter > 0))
                cout << "*", counter++;
            else
                cout << " ";
        /*
            Decrease the space after step height
        */
        if (i % step_height == 0)
            space -= step_width, counter = 0;
    }
    cout << endl;
    return 0;
}