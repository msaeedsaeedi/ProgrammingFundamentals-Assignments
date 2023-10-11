/*
    Assignment # 2 - Q1

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <bitset>
using namespace std;

int main()
{

    unsigned int num = 0;
    short int Gate_1, Gate_2, Gate_3, Gate_4;
    Gate_1 = Gate_2 = Gate_3 = Gate_4 = 0;
    cout << "Numericus Number : ";
    cin >> num;
    cout << bitset<32>(num) << endl;
    Gate_1 = num & 0x3FF;
    Gate_2 = (num >> 10) & 0x3FF;
    Gate_3 = (num >> 20) & 0x3FF;
    Gate_4 = (num >> 30) & 0b11;

    return 0;
}