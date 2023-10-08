/*
    Assignment # 2 - Q6

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <unistd.h>
#include <bitset>
using namespace std;

int main()
{
    unsigned long long int Tlamps = ~0;
    int lamps, lamps_on = 0;

    cout << "Enter Number of Lamps : ";
    cin >> lamps;

    for (int round = 1; round <= lamps; round++)
    {
        for (int fps = 1; fps <= lamps * 2; fps++)
        {
            system("clear");
            for (int row = 1; row <= lamps * 2; row++, cout << endl)
            {
                cout << "\t|";

                for (int col = 1; col <= 21; col++)
                {
                    if (row & 1)
                    {
                        int check = (Tlamps >> (((row - 1) / 2) + 1)) & 1;
                        if (check && (col == 2 || col == 20))
                            cout << "*";
                        else if (col == 11 && fps == row)
                            cout << "&";
                        else
                            cout << " ";
                    }
                    else
                        cout << " ";
                }
                if (row & 1 && fps == row)
                {
                    if (round == 1)
                    {
                        if (((((row - 1) / 2) + 1) % 3) == 0)
                            Tlamps = Tlamps & ~(1 << (((row - 1) / 2) + 1));
                    }
                    else if ((((row - 1) / 2) + 1) % round == 0)
                    {
                        int row_reg = (((row - 1) / 2) + 1);
                        Tlamps = Tlamps ^ (1 << row_reg);
                    }
                }
                cout << "|";
            }
            for (int i = 0; i < lamps; i++)
                if ((Tlamps >> i) & 1)
                    lamps_on++;
            cout << "\n Total Lamps : \t" << lamps << "\n Lamps on : \t" << lamps_on
                 << "\n Lamps off : \t" << (lamps - lamps_on) << endl;
            lamps_on = 0;
            usleep(300000);
        }
    }
    return 0;
}