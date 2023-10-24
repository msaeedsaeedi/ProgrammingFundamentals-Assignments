/*
    Assignment # 2 - Q6

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/
#include <iostream>
using namespace std;

int main()
{
    int lamps, lamps_on = 0;
    cout << "\n >>> Dance of Lamps <<<\n\n";

    /*
        Input Validation
    */
    do
    {
        cout << " Enter Number of Lamps : ";
        cin >> lamps;
        if (cin.fail())
            cin.clear();
        cin.ignore(100, '\n');
    } while (lamps <= 0);
    int number = lamps;
    /*
        Logic
            Split number into parts and then iterate over each patch
            Move to rounds for until next patch reached
            Iterate to each lamp to next patch number

            I used bits to calculate weather the lamp is on or not
            ~0 is used to set all the lamps to 1
    */
    int partSize = 64;
    int i = 1;
    while (number > 0)
    {
        unsigned long Tlamps = ~0;
        const unsigned long ONE = 1;
        int currentPart = min(number, partSize);
        for (int round = 1; round <= (partSize * i) - (partSize - currentPart); round++)
        {
            for (int row = ((partSize * i) + 1 - partSize); row <= (partSize * i) - (partSize - currentPart); row++)
            {
                if (round == 1)
                {
                    if (row >= 3 && (row % 3) == 0)
                        /*
                            off every third lamp on 1st round
                         */
                        Tlamps = Tlamps & ~(ONE << (((row - 1) % partSize) + 1) - 1);
                }
                else if (row % round == 0)
                    /*
                        Toogle every (round)th lamp;
                    */
                    Tlamps = Tlamps ^ (ONE << (((row - 1) % partSize) + 1) - 1);
            }
        }
        /*
            Calculate Number of lamps on in each patch
        */
        for (int j = 0; j < currentPart; j++)
            if ((Tlamps >> j) & 1)
                lamps_on++;
        number -= currentPart;
        i++;
    }
    /*
        Print Values
    */
    cout << "\n Total Lamps : \t" << lamps
         << "\n Lamps on : \t" << lamps_on
         << "\n Lamps off : \t" << (lamps - lamps_on)
         << "\n"
         << endl;
    return 0;
}
