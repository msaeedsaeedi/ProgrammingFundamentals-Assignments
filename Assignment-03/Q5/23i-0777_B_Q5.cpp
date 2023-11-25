/*
    Assignment # 3 - Q5

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/

#include <iostream>
#include <iomanip>

using namespace std;

/*
    Main Functions
*/
void draw(int n, int m);
void play(int s);
void showOutput();

/*
    Miscellaneous Functions
*/
void GenerateCells(int n, int m);
void Select(int, int);
int GetValue(int, int);
void Move(int i, int j);
int GetIndexODD(int);
int GetIndexEVEN(int);

/*
    Global Values
    n       -> Number of rows
    m       -> Number of columns
    Board   -> 2D Array of board
    selected-> Currently Selected Cell

    score   -> Total Score
    Jumps   -> Jumps made
*/
int n = 8;
int m = 6;
int Board[100][150];
int selected[2] = {-1, -1};

int score = 0;
int Jumps = 0;

int main()
{
    /*
        s   -> 'S' value
    */
    int s = 3;

    /*
        Input Number of rows between 1-100
    */
    do
    {
        cout << "Enter Number of rows [0,99]\t: ";
        cin >> n;
        cin.ignore(100, '\n');
    } while (n >= 100 || n <= 0);

    /*
        Input Number of columns between 1-150
    */
    do
    {
        cout << "Enter Number of columns [0,149]\t: ";
        cin >> m;
        cin.ignore(100, '\n');
    } while (m >= 150 || m <= 0);

    /*
        Generate Cells and Display
    */
    GenerateCells(n, m);
    draw(n, m);

    /*
        Input Value of 's'
    */
    do
    {
        cout << "Enter Value of s : [0," << (n - 1) << "]\t: ";
        cin >> s;
        cin.ignore(100, '\n');
    } while (s < 0 || s >= n);

    /*
        Start the game
    */
    play(s);

    /*
        Show Output
    */
    showOutput();

    return 0;
}

void draw(int n, int m)
{
    system("clear");

    /*
        Display Current Score
    */
    cout << "Score : " << score << endl;

    /*
        Print the board
            - Animation Added
            - Styling Done!
    */
    for (int i = 0; i < (2 * n + 1); i++, cout << endl)
    {
        for (int j = 0; j < (2 * m + 1); j++)
        {
            if ((i & 1))
            {
                if (j & 1)
                    cout << setw(3) << setfill(' ') << left << Board[GetIndexODD(i)][GetIndexODD(j)] << " ";
                else
                {
                    if (GetIndexEVEN(i - 1) == selected[0] && (selected[1] == GetIndexEVEN(j) || selected[1] == GetIndexEVEN(j) - 1))
                        cout << "| ";
                    else
                        cout << "  ";
                }
            }
            else if (i % 2 == 0)
            {
                if (selected[0] == GetIndexEVEN(i) || selected[0] == GetIndexEVEN(i) - 1)
                {
                    if ((j & 1) == 0)
                    {
                        if (selected[1] == GetIndexEVEN(j))
                        {
                            cout << "-------";
                            break;
                        }
                        else
                            cout << "      ";
                    }
                }
            }
            else
                cout << "  ";
        }
    }
}
void play(int s)
{
    /*
        Value of 'k'
    */
    int k = -1;

    /*
        Iterate until score reaches 100
    */
    while (score <= 100)
    {
        /*
            Select cell (s,0)
        */
        Select(s, 0);
        draw(n, m);

        /*
            Get value at cell (s,0)
        */
        int q = GetValue(s, 0);

        /*
            Iterate over the column
        */
        while (true)
        {
            /*
                Increase 'k' and reset if 'k' reaches 'n'
            */
            k++;
            if (k == n)
            {
                q = 0;
                k = -1;
                break;
            }

            /*
                Increase Jump count
            */
            Jumps++;
            Move(k, q);

            /*
                Update Score
            */
            if (GetValue(k, q) == 0)
                score = 0;
            else
                score += GetValue(k, q);
            draw(n, m);

            /*
                Exit If score reached 100
            */
            if (score >= 100)
            {
                return;
            }

            /*
                Play Simulation on [ENTER]
            */
            cout << "Press [ENTER] ";
            cin.get();
        }
        /*
            Update Frame
        */
        draw(n, m);

        /*
            Input value of 's'
        */
        do
        {
            cout << "Enter Value of s : [0," << (n - 1) << "]\t: ";
            cin >> s;
            cin.ignore(100, '\n');
        } while (s < 0 || s >= n);
    }
    return;
}
void showOutput()
{
    /*
        Display Score and Jumps made
    */
    system("clear");
    cout << "\n Final Score : " << score << endl;
    cout << " Jumps made : " << Jumps << endl;
}

/*
    Generate Random cell between 0 and m.
*/
void GenerateCells(int n, int m)
{
    srand(time(0));
    int cell = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cell = (rand() % m);
            Board[i][j] = cell;
        }
    }
}

/*
    Select cell
*/
void Select(int i, int j)
{
    selected[0] = i;
    selected[1] = j;
}

/*
    Return value at specific cell
*/
int GetValue(int i, int j)
{
    return Board[i][j];
}

/*
    Move to a cell
*/
void Move(int i, int j)
{
    selected[0] = i;
    selected[1] = j;
}

/*
    Miscellaneous Functions (For animation)
*/
int GetIndexODD(int i)
{
    return (i - 1) / 2;
}
int GetIndexEVEN(int i)
{
    return (i / 2);
}
