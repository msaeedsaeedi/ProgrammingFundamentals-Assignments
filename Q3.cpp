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
    unsigned short int initial_velocity = 0;
    const float G = 9.8;

    int scaledValue = 0;
    int scaleFactor = 100;
    const double delta = 0.01;

    double t = 0;
    double v = 0;
    double s = 0;
    double s_sec = 0;
    double sf_sec = 0;
    double s_formula = 0;
    double max_height = 0;
    double t_max_height = 0;

    bool Is_Second = false;

    cout << "Enter Initial Velocity : ";
    cin >> initial_velocity;
    cin.ignore(1000, '\n');

    v = initial_velocity;
    t_max_height = (double(initial_velocity) / G);
    max_height = (initial_velocity * (t_max_height)) - ((G / 2) * (t_max_height * t_max_height));

    int step = (0.05 * (ceil(max_height) - 128)) + 7;
    int rounded_height = ((int(ceil(max_height)) % step != 0) ? (ceil(max_height) + (step - int(ceil(max_height)) % step)) : (floor(max_height)));

    while (s_sec >= 0)
    {
        system("clear");
        scaledValue++;
        t = double(scaledValue) / scaleFactor;
        s += v * delta;
        v -= G * delta;
        s_formula = (initial_velocity * t) - ((G / 2) * (t * t));
        Is_Second = ((floor(abs(v)) == initial_velocity) || int(ceil(t * 100)) % 100 == 0);
        if (Is_Second)
        {
            s_sec = s;
            sf_sec = s_formula;
        }

        cout << "\n Interval [0-" << step << "] Rounded-up\n"
             << endl;
        cout << "\n --Time------------------ \n";
        cout << " |                      |" << endl;
        cout << " | Total   : " << setw(10) << setfill(' ') << fixed << setprecision(4) << t_max_height << " |" << endl;
        cout << " | Current : " << setw(10) << setfill(' ') << fixed << setprecision(4) << t << " |" << endl;
        cout << " ------------------------" << endl;

        cout << "\n --Position--------------";
        cout << "\t --Velocity-------------- \n";
        cout << " |                      |";
        cout << "\t |                      |\n";
        cout << " | Update  : " << setw(10) << setfill(' ') << fixed << setprecision(4) << s_sec << " |";
        cout << "\t | Initial : " << setw(10) << setfill(' ') << initial_velocity << " |\n";
        cout << " | Formula : " << setw(10) << setfill(' ') << fixed << setprecision(4) << sf_sec << " |";
        cout << "\t | Update  : " << setw(10) << setfill(' ') << fixed << setprecision(4) << v << " |\n";
        cout << " ------------------------";
        cout << "\t ------------------------\n\n";

        for (int i = 0; i <= rounded_height; i += step)
        {
            if ((s_sec < i) && (s_sec > i - step))
                cout << " ";
            cout << setw(4) << setfill('0') << i << " |";
            if ((s_sec < i) && (s_sec > i - step))
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