/*
    Assignment # 3 - Q1 Part 2

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/

#include <iostream>
using namespace std;

/*
    Functions Declaration
*/
void DisplayMenu();
int Select();

void PracticeAdd();
void PracticeSub();

int main()
{
    /*
        Set Random Seed based on time
    */
    srand(time(0));
    /*
        Print Menu
    */
    DisplayMenu();
    /*
        Declare Choice variable
    */
    int choice;
    /*
        Get User Choice
    */
    choice = Select();
    /*
        Perform Operation based on choice
    */
    switch (choice)
    {
    case 1:
        /*
            Initiate Addition Problems
         */
        PracticeAdd();
        break;
    case 2:
        /*
            Initiate Subtraction Problems
        */
        PracticeSub();
        break;
    }
    return 0;
}
void DisplayMenu()
{
    cout << "---------- Practice Arithmetic ----------" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
}

int Select()
{
    /*
        Input Validation of Choice (User Must Enter 1 or 2)
    */
    int choice;
    do
    {
        cout << "Enter your choice (1/2): ";
        cin >> choice;
        if (cin.fail())
            cin.clear();
        cin.ignore(100, '\n');
    } while (choice < 1 || choice > 2);

    return choice;
}
void PracticeAdd()
{
    /*
        a           : 1st Number
        b           : 2nd Number
        sum         : Calculated Sum
        response    : response From user
        correct     : No. of Correct Answers
        wrong       : No. of Wrong Answers
    */
    int a, b, sum, response, correct = 0, wrong = 0;
    char c = 'y';
    /*
        Generate Problems until user don't want to continue
    */
    while (c == 'y')
    {
        /*
            Generate Two Random Numbers and Add them
        */
        a = 1 + (rand() % 100);
        b = 1 + (rand() % 100);
        sum = a + b;
        /*
            Response of User
        */
        cout << a << " + " << b << " =? ";
        cin >> response;
        /*
            Input Validation
        */
        do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << a << " + " << b << " =? ";
                cin >> response;
            }
        } while (cin.fail());
        /*
            Output whether response matches or not and increment wrong/correct answers
        */
        if (response == sum)
        {
            cout << "\tCORRECT";
            correct++;
        }
        else
        {
            cout << "\tWRONG";
            wrong++;
        }
        /*
            Ask User whether he/she want to continue?
        */
        cout << "\n\tContinue (y/n)? ";
        cin >> c;
        /*
            Input Validation
        */
        do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\n\tContinue (y/n)? ";
                cin >> c;
            }
        } while (cin.fail());
    }
    /*
        Print Result
    */
    cout << "    No. of CORRECT answers = " << correct << endl;
    cout << "    No. of WRONG answers = " << wrong << endl;
}
void PracticeSub()
{
    /*
        a           : 1st Number
        b           : 2nd Number
        sub         : Calculated Difference
        response    : response From user
        correct     : No. of Correct Answers
        wrong       : No. of Wrong Answers
    */
    int a, b, sub, response, correct = 0, wrong = 0;
    char c = 'y';
    /*
        Generate Problems until user don't want to continue
    */
    while (c == 'y')
    {
        /*
            Generate Two Random Numbers and Add them
        */
        a = 1 + (rand() % 100);
        b = 1 + (rand() % 100);
        sub = a - b;
        /*
            Response of User
        */
        cout << a << " - " << b << " =? ";
        cin >> response;
        /*
            Input Validation
        */
        do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << a << " - " << b << " =? ";
                cin >> response;
            }
        } while (cin.fail());
        /*
            Output whether response matches or not and increment wrong/correct answers
        */
        if (response == sub)
        {
            cout << "\tCORRECT";
            correct++;
        }
        else
        {
            cout << "\tWRONG";
            wrong++;
        }
        /*
            Ask User whether he/she want to continue?
        */
        cout << "\n\tContinue (y/n)? ";
        cin >> c;
        /*
            Input Validation
        */
        do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\n\tContinue (y/n)? ";
                cin >> c;
            }
        } while (cin.fail());
    }
    /*
        Print Result
    */
    cout << "    No. of CORRECT answers = " << correct << endl;
    cout << "    No. of WRONG answers = " << wrong << endl;
}