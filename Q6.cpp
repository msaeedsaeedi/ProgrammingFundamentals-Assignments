/*
    Assignment # 2 - Q6

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <unistd.h>
#include <bitset>
#include <ctime>
using namespace std;

int main()
{
    unsigned long long int Tlamps = ~0;
    int lamps, lamps_on;
    int fps_count = 0;
    cout << ">>> For Animation [1-20] <<<\n\n";
    cout << "Enter Number of Lamps : ";
    cin >> lamps;

    if (lamps <= 0)
    {
        system("clear");
        cout << "\nThe Lamp count should be greater than zero.\n"
             << endl;
        return 1;
    }
    else if (lamps <= 20)
    {
        for (int round = 1; round <= lamps; round++)
        {
            for (int fps = 1; fps <= lamps * 2; fps++)
            {
                float t = clock();
                system("clear");
                for (int row = 1; row <= lamps * 2; row++, cout << endl)
                {
                    cout << "\t|";
                    int row_reg = (row - 1) / 2;
                    for (int col = 1; col <= 21; col++)
                    {
                        if (row & 1)
                        {
                            int check = (Tlamps >> row_reg) & 1;
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
                            if (((row_reg + 1) % 3) == 0)
                                Tlamps = Tlamps & ~(1 << row_reg);
                        }
                        else if ((row_reg + 1) % round == 0)
                        {
                            Tlamps = Tlamps ^ (1 << row_reg);
                        }
                    }
                    cout << "|";
                }
                if (fps % 3 == 0 || fps == 1)
                    fps_count = 1 / ((clock() - t) / double(CLOCKS_PER_SEC));
                lamps_on = 0;
                for (int i = 0; i < lamps; i++)
                    if ((Tlamps >> i) & 1)
                        lamps_on++;
                cout << "\n\n Round : " << round
                     << "\n\n Total Lamps : \t" << lamps
                     << "\t FPS : " << fps_count
                     << "\n Lamps on : \t" << lamps_on
                     << "\n Lamps off : \t" << (lamps - lamps_on)
                     << endl;
                usleep(300000);
            }
        }
    }
    return 0;
}