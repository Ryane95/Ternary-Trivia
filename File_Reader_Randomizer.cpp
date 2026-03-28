/***************************************************************
 * UPDATE ME PLEASE!!!
 * Version 1.2
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

int getRandom(int max); // proto start
vector<string> splitLine(string line);
void readFile(string filename);

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

            cout << "Choices: ";
            for (int j = 2; j <= 5; j++)
            {
                cout << questions[i][j] << " ";
            }

            cout << "\nCorrect Answer: " << questions[i][6] << endl;
        }
    }

    file.close();
}