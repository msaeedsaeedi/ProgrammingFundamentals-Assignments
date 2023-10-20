/*
    Assignment # 2 - Q5

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main()
{
    srand(time(0));

    string P1_name, P2_name;
    unsigned int P1_roll = 0, P2_roll = 0;
    unsigned int dice_1 = 0, dice_2 = 0;
    unsigned int P1_Score = 0, P2_Score = 0;
    int P1_last_index = 0, P2_last_index = 0;
    bool tie = false;
    cout << "Player 1\n\n Name : ";
    getline(cin, P1_name);

    cout << " Roll (last 4 digits) : ";
    cin >> P1_roll;
    cin.ignore(4, '\n');

    cout << "\nPlayer 2\n\n Name : ";
    getline(cin, P2_name);

    cout << " Roll (last 4 digits) : ";
    cin >> P2_roll;
    cin.ignore(4, '\n');

    P1_last_index += (P1_name.at(P1_name.length() - 1) - 64) * (P1_name.at(P1_name.length() - 1) <= 90);
    P1_last_index += (P1_name.at(P1_name.length() - 1) - 96) * (P1_name.at(P1_name.length() - 1) >= 97);

    P2_last_index += (P2_name.at(P2_name.length() - 1) - 64) * (P2_name.at(P2_name.length() - 1) <= 90);
    P2_last_index += (P2_name.at(P2_name.length() - 1) - 96) * (P2_name.at(P2_name.length() - 1) >= 97);

    cout << "\n=================================";
    cout << "\n=================================" << endl;
    for (int round = 1; round <= 5; round++)
    {

        cout << "\nRound " << round << "\n"
             << endl;
        bool extra_roll = false;
        int round_sum;
        for (int player = 1; player <= 2; player++)
        {
            (extra_roll) ? (extra_roll = false) : (round_sum = 0);
            cout << " Player : " << player << endl;
            for (int i = 1; i <= 2; i++)
            {
                dice_1 = 1 + (rand() % 6);
                dice_2 = 1 + (rand() % 6);
                cout << "\n  Dice 1 : " << dice_1;
                cout << "\n  Dice 2 : " << dice_2 << endl;
                round_sum += dice_1 + dice_2;
            }
            if (round_sum == P1_roll % 100 || round_sum == P2_roll % 100)
            {
                int points = 0;
                points += (P1_roll % 10) * (player == 1);
                points += (P2_roll % 10) * (player == 2);
                round_sum += points;
                cout << "\n  ** Awarded Points +" << points << " **" << endl;
            }
            if (round_sum == P1_last_index || round_sum == P2_last_index)
            {
                round_sum += 5;
                cout << "\n  ** Awarded Points +5 **" << endl;
            }
            if (((round_sum) * (round_sum)-4 * (round_sum)) == 0)
            {
                cout << "\n  ** Awarded Extra Roll **\n"
                     << endl;
                extra_roll = true;
                player--;
                continue;
            }
            if (player == 1)
                P1_Score += round_sum;
            else
                P2_Score += round_sum;
            cout << "\n  -> Score : " << round_sum << " <-\n"
                 << endl;
        }
        if (round != 5)
        {
            cout << "=================================" << endl;
            cout << "    Press Enter to continue..." << endl;
            cout << "=================================";
            cin.get();
        }
        if (round == 5)
        {
            cout << "=================================" << endl;
            cout << "    Player 1 Score : \t" << P1_Score << endl;
            cout << "    Player 2 Score : \t" << P2_Score << endl;
            cout << "=================================" << endl;
            if (P1_Score > P2_Score)
            {
                cout << "    " << P1_name << " Wins" << endl;
                cout << "=================================" << endl;
            }
            else if (P2_Score > P1_Score)
            {
                cout << "    " << P2_name << " Wins" << endl;
                cout << "=================================" << endl;
            }
            else
                tie = true;
        }
    }
    if (tie)
    {
        while (tie)
        {
            cout << "\nFinal Round\n"
                 << endl;
            for (int player = 1; player <= 2; player++)
            {
                cout << " Player : " << player;
                dice_1 = 1 + (rand() % 6);
                cout << "\n  Dice : " << dice_1 << endl
                     << endl;
                if (player == 1)
                    P1_Score += dice_1;
                else
                    P2_Score += dice_1;
            }
            cout << "=================================" << endl;
            cout << "     Player 1 Score : \t" << P1_Score << endl;
            cout << "     Player 2 Score : \t" << P2_Score << endl;
            cout << "=================================" << endl;
            if (P1_Score > P2_Score)
            {
                cout << "     " << P1_name << " Wins" << endl;
                cout << "=================================" << endl;
                tie = false;
            }
            else if (P2_Score > P1_Score)
            {
                cout << "     " << P2_name << " Wins" << endl;
                cout << "=================================" << endl;
                tie = false;
            }
            else
                tie = true;
        }
    }
    return 0;
}