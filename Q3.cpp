/*
    Assignment # 2 - Q3

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    /*
        Initial Velocity
    */
    unsigned short int Initial_Velocity = 0;

    /*
        Value of Gravity
    */
    const float G = 9.8;

    /*
        time_scale and scaleFactor is used to precisely calculate the time after delta
    */
    unsigned int time_scale = 0;
    const short int scaleFactor = 100;
    const double delta = 0.01;

    double Time = 0;
    double Velocity = 0;
    double Position = 0;

    /*
        Position_second     -> Position after 1 second
        F_Position_second   -> Position from formula after 1 second
        F_Position          -> Position from forumula
        Position_max        -> Maximum height of object
        Time_Position_max   -> Time to reach max height
    */
    double Position_second = 0;
    double F_Position_second = 0;
    double F_Position = 0;
    double Position_max = 0;
    double Time_Position_max = 0;

    /*
        step            -> Used to plot graph
        Height_rounded  -> Rounded height for ploting graph [rounded-up]
    */
    int step = 0;
    int Height_rounded = 0;

    /*
        Is_Second   -> Used to check if a second passed or not
    */
    bool Is_Second = false;

    /*
        Input Validation
    */
    do
    {
        cout << "Enter Initial Velocity [50,150] : ";
        cin >> Initial_Velocity;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (Initial_Velocity < 50 || Initial_Velocity > 150);

    /*
        Calculate 
            Velocity
            Time to reach max height
            Maximum height
    */
    Velocity = Initial_Velocity;
    Time_Position_max = (double(Initial_Velocity) / G);
    Position_max = (Initial_Velocity * (Time_Position_max)) - ((G / 2) * (Time_Position_max * Time_Position_max));
    
    /*
        Calculate 
            Step for ploting graph
            Height rounded for check the height
    */
    step = (0.05 * (ceil(Position_max) - 128)) + 7;
    Height_rounded = ((int(ceil(Position_max)) % step != 0) ? (ceil(Position_max) + (step - int(ceil(Position_max)) % step)) : (floor(Position_max)));

    /*
        Iterate on all seconds after delta interval
    */
    while (Position_second >= 0)
    {
        system("clear");
        time_scale++;
        Time = double(time_scale) / scaleFactor;
        Position += Velocity * delta;
        Velocity -= G * delta;
        F_Position = (Initial_Velocity * Time) - ((G / 2) * (Time * Time));
        Is_Second = ((floor(abs(Velocity)) == Initial_Velocity) || int(ceil(Time * 100)) % 100 == 0);

        /*
            Update after second
                Position
                Formula Position
        */
        if (Is_Second)
        {
            Position_second = Position;
            F_Position_second = F_Position;
        }

        /*
            Print Output
        */
        cout << "\n Interval [0-" << step << "] Rounded-up\n"
             << endl;
        cout << "\n --Time------------------ \n";
        cout << " |                      |" << endl;
        cout << " | Total   : " << setw(10) << setfill(' ') << fixed << setprecision(4) << Time_Position_max * 2 << " |" << endl;
        cout << " | Current : " << setw(10) << setfill(' ') << fixed << setprecision(4) << Time << " |" << endl;
        cout << " ------------------------" << endl;

        cout << "\n --Position--------------";
        cout << "\t --Velocity-------------- \n";
        cout << " |                      |";
        cout << "\t |                      |\n";
        cout << " | Update  : " << setw(10) << setfill(' ') << fixed << setprecision(4) << Position_second << " |";
        cout << "\t | Initial : " << setw(10) << setfill(' ') << Initial_Velocity << " |\n";
        cout << " | Formula : " << setw(10) << setfill(' ') << fixed << setprecision(4) << F_Position_second << " |";
        cout << "\t | Update  : " << setw(10) << setfill(' ') << fixed << setprecision(4) << Velocity << " |\n";
        cout << " ------------------------";
        cout << "\t ------------------------\n\n";

        /*
            Plot astrisk on height [rounded-up]
        */
        for (int i = 0; i <= Height_rounded; i += step)
        {
            if ((Position_second < i) && (Position_second > i - step))
                cout << " ";
            cout <<" " << setw(4) << setfill('0') << i << " |";
            if ((Position_second < i) && (Position_second > i - step))
                cout << "  *";
            cout << "\n";
        }
        cout << endl;

        /*
            Wait for user to press [Enter] after a second
        */
        if (Is_Second)
        {
            cout << "Press [Enter] to Continue...";
            cin.get();
        }
    }
    return 0;
}