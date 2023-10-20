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
    int steps = 5;
    int step_height = 3;
    int step_width = 5;
    int space = steps * step_width, counter = 0;
    int width = (step_width * (steps + 1) + 2);
    int height = (steps * step_height + 1);
    for (int i = 1; i <= height; i++, cout << endl)
    {
        for (int j = 1; j <= width; j++)
            if (j == width || i == height || j == space + 1 || (counter <= step_width && counter > 0))
                cout << "*", counter++;
            else
                cout << " ";
        if (i % step_height == 0)
            space -= step_width, counter = 0;
    }
    cout << endl;
    return 0;
}