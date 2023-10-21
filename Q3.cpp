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
    unsigned short int Initial_Velocity = 0;
    const float G = 9.8;

    int time_scale = 0;
    int scaleFactor = 100;
    const double delta = 0.01;

    double Time = 0;
    double Velocity = 0;
    double Position = 0;
    double Position_second = 0;
    double F_Position_second = 0;
    double F_Position = 0;
    double Position_max = 0;
    double Time_Position_max = 0;

    int step = 0;
    int Height_rounded = 0;

    bool Is_Second = false;

    cout << "Enter Initial Velocity : ";
    cin >> Initial_Velocity;
    cin.ignore(1000, '\n');

    Velocity = Initial_Velocity;
    Time_Position_max = (double(Initial_Velocity) / G);
    Position_max = (Initial_Velocity * (Time_Position_max)) - ((G / 2) * (Time_Position_max * Time_Position_max));

    step = (0.05 * (ceil(Position_max) - 128)) + 7;
    Height_rounded = ((int(ceil(Position_max)) % step != 0) ? (ceil(Position_max) + (step - int(ceil(Position_max)) % step)) : (floor(Position_max)));

    while (Position_second >= 0)
    {
        system("clear");
        time_scale++;
        Time = double(time_scale) / scaleFactor;
        Position += Velocity * delta;
        Velocity -= G * delta;
        F_Position = (Initial_Velocity * Time) - ((G / 2) * (Time * Time));
        Is_Second = ((floor(abs(Velocity)) == Initial_Velocity) || int(ceil(Time * 100)) % 100 == 0);
        if (Is_Second)
        {
            Position_second = Position;
            F_Position_second = F_Position;
        }

        cout << "\n Interval [0-" << step << "] Rounded-up\n"
             << endl;
        cout << "\n --Time------------------ \n";
        cout << " |                      |" << endl;
        cout << " | Total   : " << setw(10) << setfill(' ') << fixed << setprecision(4) << Time_Position_max << " |" << endl;
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

        for (int i = 0; i <= Height_rounded; i += step)
        {
            if ((Position_second < i) && (Position_second > i - step))
                cout << " ";
            cout << setw(4) << setfill('0') << i << " |";
            if ((Position_second < i) && (Position_second > i - step))
                cout << "  *";
            cout << "\n";
        }
        cout << endl;
        if (Is_Second)
        {
            cout << "Press [Enter] to Continue...";
            cin.get();
        }
    }
    return 0;
}