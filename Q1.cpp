/*
    Assignment # 2 - Q1

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
using namespace std;

int main()
{

    unsigned int num = 0;
    short int Gate_1, Gate_2, Gate_3, Gate_4;
    Gate_1 = Gate_2 = Gate_3 = Gate_4 = 0;

    cout << " Positive Number : ";
    cin >> num;

    cout << "\n Binary : ";
    for (int i = 31; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << endl;

    Gate_1 = num & 0x3FF;
    Gate_2 = (num >> 10) & 0x3FF;
    Gate_3 = (num >> 20) & 0x3FF;
    Gate_4 = (num >> 30) & 0b11;

    cout << " Gate 1 : ";
    for (int i = 9; i >= 0; i--)
        cout << ((Gate_1 >> i) & 1);
    cout << endl;
    cout << " Gate 2 : ";
    for (int i = 9; i >= 0; i--)
        cout << ((Gate_2 >> i) & 1);
    cout << endl;
    cout << " Gate 3 : ";
    for (int i = 9; i >= 0; i--)
        cout << ((Gate_3 >> i) & 1);
    cout << endl;
    cout << " Gate 4 : ";
    for (int i = 1; i >= 0; i--)
        cout << ((Gate_4 >> i) & 1);
    cout << endl;

    switch (Gate_4)
    {
    case 0:
    {
        unsigned int converted = 0;
        converted |= (Gate_1) & 0x3FF;
        converted |= ((Gate_2) & 0x3FF) << 10;
        converted |= ((Gate_3) & 0x3FF) << 20;
        converted |= ((Gate_4) & 0b11) << 30;
        cout << "\n After Conversion " << endl;
        cout << " Positive Number : " << num << endl;
        break;
    }
    case 1:
    {
        cout << "\n After Conversion " << endl;
        cout << " Hexadecimal : ";
        bool nonZeroFound = false;
        for (int i = 28; i >= 0; i -= 4)
        {
            int nibble = (num >> i) & 0xF;
            if (nibble != 0 || nonZeroFound)
            {
                char hexDigit = (nibble < 10) ? ('0' + nibble) : ('A' + nibble - 10);
                cout << hexDigit;
                nonZeroFound = true;
            }
        }
        if (!nonZeroFound)
            cout << '0';
        break;
    }
    case 2:
    {
        Gate_1 ^= Gate_2;
        Gate_2 ^= Gate_1;
        Gate_1 ^= Gate_2;
        cout << "\n After Swap " << endl;
        cout << " Gate 1 : ";
        for (int i = 9; i >= 0; i--)
            cout << ((Gate_1 >> i) & 1);
        cout << endl;

        cout << " Gate 2 : ";
        for (int i = 9; i >= 0; i--)
            cout << ((Gate_2 >> i) & 1);
        cout << endl;
        break;
    }
    case 3:
        char c;
        cout << "\n Operation [ Multiply (*) / Divide (/) ] : ";
        cin >> c;
        switch (c)
        {
        case '*':
        {
            int a, b, product = 0;
            cout << "\n Enter First Numbers  : ";
            cin >> a;
            cout << " Enter Second Numbers : ";
            cin >> b;
            bool negative = (a < 0) ^ (b < 0);
            a = abs(a);
            b = abs(b);
            for (int i = 0; i < a; i++)
                product += b;
            if (negative)
                product = -product;
            cout << "\n Product : " << product << endl;
            break;
        }
        case '/':
        {
            int a, b;
            int Quotient = 0;
            cout << "\n Enter First Numbers : ";
            cin >> a;
            cout << " Enter Second Numbers : ";
            cin >> b;
            bool negative = (a < 0) ^ (b < 0);
            a = abs(a), b = abs(b);
            while (a >= b)
            {
                a -= b;
                Quotient++;
            }
            if (negative)
                Quotient = -Quotient;
            cout << "\n Division : " << Quotient << endl;
            break;
        }
        default:
            cout << "Invalid";
        }
        break;
    }

    return 0;
}