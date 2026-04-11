#include "quizgame.h"
#include <iostream>
#include <fstream>
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

void readFile(string filename)
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

    vector<Question> questions;

    string line;

    while (getline(file, line))
    {
        vector<string> parts = splitLine(line);

        if (parts.size() >= 7)
        {
            Question q;

            q.value = stoi(parts[0]);
            q.text = parts[1];

            for (int i = 2; i <= 5; i++)
            {
                q.answers.push_back(parts[i]);
            }

            for (int i = 0; i < 4; i++)
            {
                if (parts[6] == q.answers[i])
                {
                    q.correctIndex = i;
                }
            }

            questions.push_back(q);
        }
    }

    for (int i = 0; i < questions.size(); i++)
    {
        cout << "\nValue: " << questions[i].value << endl;
        cout << "Question: " << questions[i].text << endl;

        for (int j = 0; j < questions[i].answers.size(); j++)
        {
            cout << j + 1 << ") " << questions[i].answers[j] << endl;
        }

        int answer = getInput(1, 4) - 1;

        if (answer == questions[i].correctIndex)
        {
            cout << "Correct!\n";
        }
        else
        {
            cout << "Incorrect. Correct answer: "
                 << questions[i].answers[questions[i].correctIndex] << endl;
        }

        pauseGame();
    }

    file.close();
}

int getInput(int min, int max)
{
    int choice;

    while (true)
    {
        cout << "Enter a number (" << min << "-" << max << "): ";
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