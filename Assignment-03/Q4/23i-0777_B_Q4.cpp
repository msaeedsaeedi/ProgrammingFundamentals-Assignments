/*
    Assignment # 3 - Q4

    Name    : Mohammad Saeed
    Roll    : 23i-0777
    Section : B

*/

#include <iostream>
using namespace std;

/*
    Function Declaration
*/
void Replace(char array[], char find[], char replace[], char complete_word);

/*
    Return the length of the array. [1,n]
*/
int Length(char array[]);

/*
    Return whether the word is matched in the array or not
*/
bool MatchWord(int starting_index, char array[], char find[]);

int main()
{
    /*
        Text    -> Main Text Provided by User
        Find    -> Text to find in the text
        Replace -> Text to replace
    */
    char text[500]{}, find[50]{}, replace[50]{};

    /*
        used to ask user whether he/she wants to replace complete word
    */
    char complete_word;

    /*
        Input Main Text
    */
    cout << "\n Please enter the text (500 chars max) : \n\n ";
    cin.getline(text, 500);

    /*
        Iterate Until user provided empty space
    */
    do
    {
        /*
            Input the text to find
        */
        cout << "\n -> Please enter the word to find : ";
        cin.getline(find, 50);

        /*
            Exit if the find text is empty
        */
        if (Length(find) == 0)
            break;

        /*
            Input the text to replace
        */
        cout << " -> Please enter the replace word : ";
        cin.getline(replace, 50);

        /*
            Ask whether he want to repace whole word?
        */
        cout << " -> Replace Complete Word ? (y/n) : ";
        cin >> complete_word;

        /*
            Display The result
        */
        cout << "\n Result: \n"
             << endl;
        Replace(text, find, replace, complete_word);
        cout << " " << text << endl;

        /*
            Clear the buffer
        */
        cin.ignore(1000, '\n');
    } while (true);
    return 0;
}
void Replace(char array[], char find[], char replace[], char complete_word)
{
    /*
        If user want's to replace whole word then add spaces before and after find and replace text.
    */
    if (complete_word == 'y')
    {
        int length = Length(find);
        for (int i = length; i > 0; i--)
        {
            find[i] = find[i - 1];
        }
        find[0] = ' ';
        find[Length(find)] = ' ';
        length = Length(replace);
        for (int i = length; i > 0; i--)
        {
            replace[i] = replace[i - 1];
        }
        replace[0] = ' ';
        replace[Length(replace)] = ' ';
    }

    /*
        Iterate over every character of the array
    */
    for (int i = 0; i < Length(array); i++)
    {
        /*
            If find's text first character is matched
        */
        if (array[i] == find[0])
        {
            /*
                Match if it is a complete word
            */
            if (MatchWord(i, array, find))
            {
                /*
                    If replace text is greater than the find text.
                        - Shift array to the right
                        - Replace the word
                */
                if (Length(find) < Length(replace))
                {
                    int diff = Length(replace) - Length(find);
                    for (int j = (Length(array)); j >= (i + Length(find) - 1); j--)
                        array[j + diff] = array[j];
                    for (int j = 0; j < Length(replace); j++)
                        array[i + j] = replace[j];
                }

                /*
                    If replace text is equal to the find text.
                        - Replace the word
                */
                else if (Length(find) == Length(replace))
                {
                    for (int j = 0; j < Length(replace); j++)
                        array[i + j] = replace[j];
                }

                /*
                    If replace text is smaller than the find text.
                        - Shift array to the left
                        - Replace the word
                */
                else
                {
                    int diff = Length(find) - Length(replace);
                    for (int j = Length(replace); j < (Length(array) - i); j++)
                        array[i + j] = ((i + j + diff) < Length(array)) ? array[i + j + diff] : '\0';
                    for (int j = 0; j < Length(replace); j++)
                        array[i + j] = replace[j];
                }
                i += Length(replace) - 1;
            }
        }
    }
}

bool MatchWord(int starting_index, char array[], char find[])
{
    for (int j = 1; j < Length(find); j++)
        if (array[starting_index + j] != find[j])
            return false;
    return true;
}
int Length(char array[])
{
    int count = 0;
    while (array[count] != '\0')
        count++;
    return count;
}
