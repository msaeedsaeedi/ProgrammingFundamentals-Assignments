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
    double formula_s = 0;
    double max_height = 0;
    double t_max_height = 0;

    bool Is_Second = false;

    cout << "Enter Initial Velocity : ";
    cin >> initial_velocity;
    cin.ignore(1000, '\n');

    v = initial_velocity;
    t_max_height = (double(initial_velocity) / G);
    max_height = (initial_velocity * (t_max_height)) - ((G / 2) * (t_max_height * t_max_height));

    while (formula_s >= 0)
    {
        system("clear");
        scaledValue++;
        t = double(scaledValue) / scaleFactor;
        s += v * delta;
        v -= G * delta;
        formula_s = (initial_velocity * t) - ((G / 2) * (t * t));
        Is_Second = ((floor(abs(v)) == initial_velocity) || int(ceil(t * 100)) % 100 == 0);
        if (Is_Second)
            s_sec = s;
        // cout << (t) << "\t- " << setfill('0') << setw(8) << fixed << s_sec << "\t- " << formula_s << "\t- " << v << endl;
        if (Is_Second)
        {
            cout << "Press [Enter] to Continue";
            cin.get();
        }
    }
    return 0;
}