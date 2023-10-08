/*
    Assignment # 2 - Q6

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++, cout << endl)
        {
            cout << "\t|";

            for (int k = 1; k <= 21; k++)
            {
                if (j & 1)
                {
                    if ((k == 2 || k == 20))
                        cout << "*";
                    else if (k == 11 && i == j)
                        cout << "&";
                    else
                        cout << " ";
                }
                else
                    cout << " ";
            }
            cout << "|";
        }

        usleep(300000);
        system("clear");
    }
    return 0;
}