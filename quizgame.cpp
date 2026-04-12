#include "quizgame.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandom(int max)
{
    return rand() % max;
}

vector<string> splitLine(string line)
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

void readFile(string filename, board jepordy[][5])
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string category;
    getline(file, category);

    cout << "\nCategory: " << category << endl;

    string line;
    int row = 0;
    int col = 0;

    while (getline(file, line) && row < 5)
    {
        vector<string> parts = splitLine(line);

        if (parts.size() >= 6)
        {
            jepordy[row][col].points = (row + 1) * 100;
            jepordy[row][col].question = parts[1];

            jepordy[row][col].fake1 = parts[2];
            jepordy[row][col].fake2 = parts[3];
            jepordy[row][col].fake3 = parts[4];
            jepordy[row][col].answer = parts[5];

            jepordy[row][col].used = false;

            col++;
            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }

    file.close();
}

int getInput(int min, int max)
{
    int choice;

    while (true)
    {
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
        }
        else if (choice < min || choice > max)
        {
            cout << "Out of range.\n";
        }
        else
        {
            return choice;
        }
    }
}

void pauseGame()
{
    cin.ignore(1000, '\n');
    cin.get();
}