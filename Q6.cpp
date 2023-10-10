/*
    Assignment # 2 - Q6

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;

int main()
{
    unsigned long long int Tlamps = ~0;
    int lamps, lamps_on = 0;
    int fps_count = 0;
    char animation;
    cout << ">>> For Animation [1-10] <<<\n\n";
    do
    {
        cout << "Enter Number of Lamps : ";
        cin >> lamps;
        cin.ignore(100, '\n');
    } while (lamps <= 0);
    if (lamps <= 10)
    {
        do
        {
            cout << "Do you want animation (y/n) : ";
            cin >> animation;
            cin.ignore(100, '\n');
        } while (animation != 'n' && animation != 'N' && animation != 'y' && animation != 'Y');
    }
    if (animation == 'y' || animation == 'Y')
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
    else
    {
        for (int round = 1; round <= lamps; round++)
        {
            for (int row = 1; row <= lamps; row++)
            {
                if (round == 1)
                {
                    if (row >= 3 && (row % 3) == 0)
                        Tlamps = Tlamps & ~(1 << row - 1);
                }
                else if (row % round == 0)
                {
                    Tlamps = Tlamps ^ (1 << row - 1);
                }
            }
        }
        system("clear");
        for (int i = 0; i < lamps; i++)
            if ((Tlamps >> i) & 1)
                lamps_on++;
        cout << "\n\n Total Lamps : \t" << lamps
             << "\n Lamps on : \t" << lamps_on
             << "\n Lamps off : \t" << (lamps - lamps_on)
             << endl;
    }
    return 0;
}