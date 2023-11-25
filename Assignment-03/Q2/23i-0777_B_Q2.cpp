/*
    Assignment # 3 - Q2

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/

#include <iostream>
using namespace std;

/*
    Main Function
*/
int Convert(int array[100][100], int into[100][100], int N, int K);

/*
    Driver Functions
*/
int DifferentElementsLength(int a[100][100], int b[100][100], int N);
bool IsSymmetric(int array[100][100], int N);
void CopyValues(int from[100][100], int to[100][100], int N);
int Randomk(int k, int excluding[2]);

void ValidateInput(int N, int a, int b);

int main()
{
    /*
        Variables   : TestCases -> Number of test case to perfrom
        Results     : Array of results [1,200]
    */
    int TestCases;
    int Results[200];

    /*
        Input Testcases
    */
    cin >> TestCases;
    ValidateInput(TestCases, 1, 200);   // Input Validation

    /*
        Iterate over all test cases
    */
    for (int TestNumber = 0; TestNumber < TestCases; TestNumber++)
    {
        /*
            N -> Number of Matrix Size (square)
            K -> Max of cell size (inclusive)
        */
        int N = 2;
        int K = 2;

        /*
            Two Arrays to store matrix data
        */
        int a[100][100];
        int b[100][100];

        /*
            Input [N,K]
                + Validation
        */
        cin >> N >> K;
        ValidateInput(N, 1, 100);
        ValidateInput(K, 1, 9);

        /*
            Input Martix A
        */
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> a[i][j];
                ValidateInput(a[i][j], 1, K);
            }

        /*
            Input Matrix B
        */
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> b[i][j];
                ValidateInput(b[i][j], 1, K);
            }

        /*
            Perform Conversion
        */
        Results[TestNumber] = Convert(a, b, N, K);
    }

    /*
        Display Results
    */
    for (int i = 0; i < TestCases; i++)
    {
        cout << "Case " << (i + 1) << ": " << Results[i] << endl;
    }

    return 0;
}

int Convert(int array[100][100], int into[100][100], int N, int K)
{
    /*
        Number of operations
    */
    int operations = 0;

    /*
        Number of operations to be done
    */
    int o_remaining = DifferentElementsLength(array, into, N);

    /*
        Temporary Arrays
    */
    int temp[100][100];
    int excluding[2];

    /*
        Copy Values to Temporary Array
    */
    CopyValues(array, temp, N);

    /*
        Iterate until operations remaining are zero
    */
    for (int turn = 1; o_remaining > 0; turn++)
    {
        /*
            Iterate Over Matrix Rows
        */
        for (int i = 0; (i < N); i++)
        {
            /*
                Iterate Over Matrix Columns
            */
            for (int j = 0; (j < N); j++)
            {
                /*
                    Check If the Respective Element is matched or not
                */
                if (array[i][j] != into[i][j])
                {
                    /*
                        Commit in temporary array
                    */
                    temp[i][j] = into[i][j];

                    /*
                        Check whether the resultant array is symmetric or not
                    */
                    if (IsSymmetric(temp, N))
                    {
                        /*

                        */
                        if (turn > 1)
                        {
                            /*
                                Generate Dummy element for Swap
                            */
                            excluding[0] = array[i][j];
                            excluding[1] = array[j][i];
                            int random = Randomk(K, excluding);

                            /*
                                Exit if Array can't be interchanged
                            */
                            if (random == -1)
                                return -1;
                            
                            /*
                                Apply Commit
                            */
                            temp[i][j] = array[i][j] = random;
                            operations++;
                        }
                        else
                            temp[i][j] = array[i][j];   // Discard Changes
                    }
                    else
                    {
                        /*
                            Apply Commit
                        */
                        array[i][j] = into[i][j];
                        o_remaining--;
                        operations++;
                    }
                }
            }
        }
    }
    
    /*
        Return Number of operation Done
    */
    return operations;
}

int DifferentElementsLength(int a[100][100], int b[100][100], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != b[i][j])
                count++;
        }
    }
    return count;
}
bool IsSymmetric(int array[100][100], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array[i][j] != array[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
void CopyValues(int from[100][100], int to[100][100], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            to[i][j] = from[i][j];
    }
}
int Randomk(int k, int excluding[2])
{
    int r;
    bool flag = true;
    if (k - 1 == 1)
    {
        return -1;
    }
    while (flag)
    {
        flag = false;
        r = 1 + (rand() % k);
        for (int i = 0; i < 2; i++)
            if (r == excluding[i])
                flag = true;
    }
    return r;
}
void ValidateInput(int N, int lower, int upper)
{
    if (N > upper || N < lower)
    {
        cout << "Invalid Input..." << endl;
        exit(1);
    }
}