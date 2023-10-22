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
    /*
        Variable Decleartion
        num     : Positive Number
        Gate_1  : Stores first 10 bits of Positive Number
        Gate_2  : Stores second 10 bits of Positive Number
        Gate_3  : Stores third 10 bits of Positive Number
        Gate_4  : Stores last 2 bits of Positive Number
    */
    unsigned int num = 0;
    short int Gate_1, Gate_2, Gate_3, Gate_4;
    Gate_1 = Gate_2 = Gate_3 = Gate_4 = 0;

    /*
        Input Validation
    */
    int temp = -1;
    do
    {
        cout << " Positive Number : ";
        cin >> temp;
        if (cin.fail())
            cin.clear(), temp = -1;
        cin.ignore(1000, '\n');
    } while (temp < 0);
    num = temp;

    /*
        Printing Binary of Positive Number
    */
    cout << "\n Binary : ";
    for (int i = 31; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << endl;

    /*
        Splitting Positive Number into 4 Gates
    */
    Gate_1 = num & 0x3FF;
    Gate_2 = (num >> 10) & 0x3FF;
    Gate_3 = (num >> 20) & 0x3FF;
    Gate_4 = (num >> 30) & 0b11;

    /*
        Printing Gates after splitting
    */
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

    /*
        Switching Upon 4th Gate values
        Logic:
            As 2 bits have 4 possible combinations
            00  ->  1st Operation   (Convert Back into number)
            01  ->  2nd Operation   (Print Hexadecimal)
            10  ->  3rd Operation   (Swap Gate 1 and Gate 2)
            11  ->  4th Operation   (Perform Division or Multiplication on two numbers [user])
    */
    switch (Gate_4)
    {
    case 0:
    {
        /*
            Convert Binary Back into Number
        */
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
        /*
            Print Hexadecimal of Number
        */
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
        /*
            Swap Gate 1 and Gate 2
        */
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
    {
        /*
            Perform Multiplication or Division [user] on two numbers [user]
        */
        cout << "\n";
        char c;

        /*
            Input Validation
        */
        do
        {
            cout << " Operation [ Multiply (*) / Divide (/) ] : ";
            cin >> c;
            if (cin.fail())
                cin.clear();
            cin.ignore(1000, '\n');
        } while (c != '*' && c != '/');

        /*
            Switch Operation
        */
        switch (c)
        {
        case '*':
        {
            /*
                Perform Multiplication with out '*' Operator
            */
            cout << "\n";
            int a = -1, b = -1, product = 0;

            /*
                Input Validation
            */
            do
            {
                cout << " Enter First Numbers  : ";
                cin >> a;
                if (cin.fail())
                    cin.clear(), a = -1;
                cin.ignore(1000, '\n');
            } while (a < 0);

            /*
                Input Validation
            */
            do
            {
                cout << " Enter Second Numbers : ";
                cin >> b;
                if (cin.fail())
                    cin.clear(), b = -1;
                cin.ignore(1000, '\n');
            } while (b < 0);

            /*
                Check Sign of resultant
            */
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
            /*
                Perform Division with out '/' Operator (only integer)
            */
            int a = -1, b = -1;
            int Quotient = 0;
            
            /*
                Input Validation
            */
            do
            {
                cout << " Enter First Numbers  : ";
                cin >> a;
                if (cin.fail())
                    cin.clear(), a = -1;
                cin.ignore(1000, '\n');
            } while (a < 0);

            /*
                Input Validation
            */
            do
            {
                cout << " Enter Second Numbers : ";
                cin >> b;
                if (cin.fail())
                    cin.clear(), b = -1;
                cin.ignore(1000, '\n');
            } while (b <= 0);

            /*
                Check sign of resultant
            */
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
        }
        break;
    }
    }

    return 0;
}