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
    double S_sec = 0;
    double formula_s = 0;
    cout << "Enter Initial Velocity : ";
    cin >> initial_velocity;
    cin.ignore(1000, '\n');
    v = initial_velocity;
    while (formula_s >= 0)
    {
        bool second = false;
        system("clear");
        scaledValue++;
        t = double(scaledValue) / scaleFactor;
        s += v * delta;
        v -= G * delta;
        formula_s = (initial_velocity * t) - ((G / 2) * (t * t));
        second = ((floor(abs(v)) == initial_velocity) || int(ceil(t * 100)) % 100 == 0);
        if (second)
            S_sec = s;
        //cout << (t) << "\t- " << setfill('0') << setw(8) << fixed << S_sec << "\t- " << formula_s << "\t- " << v << endl;
        if (second)
        {
            cout << "Press [Enter] to Continue";
            cin.get();
        }
    }
    return 0;
}