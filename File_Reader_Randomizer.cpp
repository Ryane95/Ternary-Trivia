/***************************************************************
 * UPDATE ME PLEASE!!!
 * Version 1.3
 * Last Updated 3/28/26
 * Last Edited by: Hunter
 ***************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/******************************************
 * file format should be the following
 * fiel name : "category.txt" i.e. "Math.txt" or "Sci-fi history.txt"
 * "value (1-5) indicating value/points/difficulty" "Question" "answer1" ... "answer 4" "correct answer"
 ****************************************** */

int getRandom(int max);
vector<string> splitLine(string line);
void readFile(string filename);
int getInput(int min, int max);
void pauseGame();

int main()
{
    srand(time(0));

    vector<string> files;
    files.push_back("Math.txt");
    files.push_back("Science.txt");
    files.push_back("History.txt");
    files.push_back("Movies.txt");
    files.push_back("Games.txt");
    files.push_back("Sports.txt");

    int numToPick = files.size();

    if (files.size() < numToPick)
    {
        numToPick = files.size();
    }

    vector<bool> used(files.size(), false);

    for (int i = 0; i < numToPick; i++)
    {
        int index;

        do
        {
            index = getRandom(files.size());
        } while (used[index]);

        used[index] = true;

        readFile(files[index]);
    }

    return 0;
}

int getInput(int min, int max)
{
    int choice;

    while (true)
    {
        cout << "Enter a number (" << min << "-" << max << "): ";
        cin >> choice;

        if (cin.fail()) // checks if user typed something non-numeric
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
        else if (choice < min || choice > max)
        {
            cout << "Please enter a number between " << min << " and " << max << ".\n";
        }
        else
        {
            return choice;
        }
    }
}

int getRandom(int max) // function defs. start here
{
    return rand() % max;
}

vector<string> splitLine(string line) // split thee eline by the tab that seperare the info
{
    vector<string> parts;
    string temp = "";

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '\t')
        {
            parts.push_back(temp);
            temp = "";
        }
        else
        {
            temp += line[i];
        }
    }
    parts.push_back(temp);
    return parts;
}

void readFile(string filename) // read in the file
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string category;
    getline(file, category); // first line is category  i.e.
    /*
    "Sci-fi history.txt" THIS PART!
    "value (1-5) indicating value/points/difficulty" "Question" "answer1" ... "answer 4" "correct answer"
    */

    cout << "\nCategory: " << category << endl;

    vector<vector<string>> questions(6); // index 1–5

    string line;
    while (getline(file, line))
    {
        vector<string> parts = splitLine(line);

        if (parts.size() >= 7)
        {
            int value = stoi(parts[0]); // value == 1–5  stoi is str2int https://cplusplus.com/reference/string/stoi/
            questions[value] = parts;
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        if (!questions[i].empty())
        {
            cout << "\nValue: " << questions[i][0] << endl;
            cout << "Question: " << questions[i][1] << endl;

            for (int j = 2; j <= 5; j++)
            {
                cout << j - 1 << ") " << questions[i][j] << endl;
            }

            int answer = getInput(1, 4);

            string chosen = questions[i][answer + 1];
            string correct = questions[i][6];

            if (chosen == correct)
            {
                cout << "Correct!\n";
            }
            else
            {
                cout << "Incorrect. Correct answer: " << correct << endl;
            }
            pauseGame();
        }
    }

    file.close();
}

void pauseGame()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore(1000, '\n');
    cin.get();
}