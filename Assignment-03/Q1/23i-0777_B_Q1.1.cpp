/*
    Assignment # 3 - Q1 Part 1

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/

#include <iostream>
using namespace std;

/*
    Functions Declaration
*/
int FindSum(int, int, int);
void ShowSum(int);

float FindAvg(int, int, int);
void ShowAvg(float);

int FindMax(int, int, int);
void ShowMax(int);

int FindMin(int, int, int);
void ShowMin(int);

int main()
{
    /*
        Declare 3 Integers along with max and min
    */
    int x, y, z, max, min;
    /*
        Input 3 Integers
    */
    cout << "Enter 3 integer numbers: ";
    cin >> x >> y >> z;
    /*
        Input Validation
    */
    do
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter 3 integer numbers: ";
            cin >> x >> y >> z;
        }
    } while (cin.fail());
    /*
        Declare Sum and Average Variables
    */
    int Sum;
    float Average;
    /*
        Find and Print Sum
    */
    Sum = FindSum(x, y, z);
    ShowSum(Sum);
    /*
        Find and Print Average
    */
    Average = FindAvg(x, y, z);
    ShowAvg(Average);
    /*
        Find and Print Maximum
    */
    max = FindMax(x, y, z);
    ShowMax(max);
    /*
        Find and Print Minimum
    */
    min = FindMin(x, y, z);
    ShowMin(min);

    return 0;
}

int FindSum(int a, int b, int c)
{
    /*
        Calculate Addition
    */
    return (a + b + c);
}
void ShowSum(int sum)
{
    /*
        Print Addition
    */
    cout << "\n\tSum = " << sum << endl;
}

float FindAvg(int a, int b, int c)
{
    /*
        Calculate Average
    */
    return ((a + b + c) / 3.0f);
}

void ShowAvg(float avg)
{
    /*
        Print Average
    */
    cout.precision(2);
    cout << "\tAverage = " << fixed << avg << endl;
}

int FindMax(int a, int b, int c)
{

    /*
        Find Maximum
    */
    int max;
    if (a > b)
    {
        if (a > c)
            max = a;
        else
            max = c;
    }
    else
    {
        if (b > c)
            max = b;
        else
            max = c;
    }
    /*
        Return Maximum
    */
    return max;
}

void ShowMax(int max)
{
    /*
        Print Maximum
    */
    cout << "\n\tMaximum = " << max << endl;
}

int FindMin(int a, int b, int c)
{
    /*
        Find Minimum
    */
    int min;
    if (a < b)
    {
        if (a < c)
            min = a;
        else
            min = c;
    }
    else
    {
        if (b < c)
            min = b;
        else
            min = c;
    }
    /*
        Return Minimum
    */
    return min;
}

void ShowMin(int min)
{
    /*
        Print Minimum
    */
    cout << "\tMinimum = " << min << endl;
}
