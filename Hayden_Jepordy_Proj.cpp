/**************************************
James Sturdivant, Hunter Hayden
Group Project
Date: April 13th
Description: A game of Jepordy
Version: 1.6
***************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "quizgame.h"
#include "screens.h"
#include "editor2.h"

using namespace std;

void loadPoints(board jepordy[5][5]);
void shuffleTeams(team teams[]);
int order();
void populateOwnQuestions(board jepordy[5][5]);
void displayMenu();
int getChoice();
int answerQuestion(team teams[], board jepordy[5][5]);
void showScore(team teams[]);
void restartGame(team teams[], board jepordy[5][5]);
void changePoints(team teams[]);
int validation();
string chooseRandSubject();
board jepordy[5][5];
int main()
{
    screens::introScreen();
    srand(time(0));

    team teams[3];
    

    string request;
    bool creative = false;

    for (int i = 0; i < 3; i++)
    {
        cout << "Team " << i + 1 << " is called? ";
        getline(cin, teams[i].name);
    }

    shuffleTeams(teams);
    loadPoints(jepordy);

    cout << "Use the editor to make questions? (y/n): ";
    cin >> request;

    if (request == "y" || request == "Y")
        creative = true;

    cin.ignore(1000, '\n');
    string category = " ";

    if (creative)
    {
        fileEditor();
        category = chooseRandSubject();
    }
    else
    {
        category = chooseRandSubject();
    }

    int choice;

    do
    {
        if (category == " ")
            screens::menuScreen();
        else
            screens::menuScreen(category);
        choice = getChoice();

        switch (choice)
        {
        case 1:
            answerQuestion(teams, jepordy);
            break;
        case 2:
            showScore(teams);
            break;
        case 3:
            restartGame(teams, jepordy);
            break;
        case 4:
            changePoints(teams);
            break;
        }

    } while (choice != 5);

    return 0;
}

void populateOwnQuestions(board jepordy[5][5])
{
    bool creative;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Please provide your question: ";
            getline(cin, jepordy[i][j].question);
            cout << "What is the answer to your question: ";
            getline(cin, jepordy[i][j].answer);
            cout << "Please enter three fake answers: " << endl;
            getline(cin, jepordy[i][j].fake1);
            getline(cin, jepordy[i][j].fake2);
            getline(cin, jepordy[i][j].fake3);
        }
    }
    creative = false;
}

void loadPoints(board jepordy[5][5])
{
    for (int row = 0; row < 5; row++)
        for (int col = 0; col < 5; col++)
        {
            jepordy[row][col].points = (row + 1) * 100;
        }
}

void shuffleTeams(team teams[])
{
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        int j = rand() % 3;
        team temp = teams[i];
        teams[i] = teams[j];
        teams[j] = temp;
    }
}
int order()
{
    static int current = 0;
    int index = current;
    current = (current + 1) % 3;
    return index;
}

int validation()
{
    int valid;
    while (!(cin >> valid))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please put a integer: ";
    }
    return valid;
}

void displayMenu()
{
    // Display menu of choices
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\n\n\n\t\tTernary Trivia" << endl
         << endl;
    cout << "\n\t1.  Answer a question";
    cout << "\n\t2.  Check current points";
    cout << "\n\t3.  Restart game";
    cout << "\n\t4.  Change current points";
    cout << "\n\t5.  Exit the Program\n\n";
    cout << "\n\tEnter your choice(1-5):  ";
}

int getChoice()
{
    int choice = 0;
    while (choice < 1 || choice > 5)
    {
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please put a integer value: " << endl;
        }
    }
    return choice;
}

int answerQuestion(team teams[], board jepordy[5][5])
{
    int row, col, teamChoice;
    int turn = order();

    screens::aTeamsTurn(teams[turn].name);

    screens::questionSelection("row");
    row = validation();
    while (row < 0 || row > 4)
    {
        cout << "Invalid row. Enter a row (0-4): ";
        row = validation();
    }

    screens::questionSelection("column");
    col = validation();
    while (col < 0 || col > 4)
    {
        cout << "Invalid column. Enter a column (0-4): ";
        col = validation();
    }

    if (jepordy[row][col].used)
    {
        cout << "That question has already been used.\n";
        return 0;
    }
    else
    {
        jepordy[row][col].used = true;
    }

    string prompts[4] = {jepordy[row][col].answer, jepordy[row][col].fake1, jepordy[row][col].fake2, jepordy[row][col].fake3};

    int multipleChoice[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        int temp = multipleChoice[i];
        multipleChoice[i] = multipleChoice[j];
        multipleChoice[j] = temp;
    }

    //cout << jepordy[row][col].question << endl
    //     << endl;

    //for (int i = 0; i < 4; i++)
    //{
    //    cout << i + 1 << ") " << prompts[multipleChoice[i]] << endl;
    //}
    screens::questionScreen(jepordy[row][col].question, prompts, row);
    //cout << "Choose your answer (1-4): ";
    int choice = validation();
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid choice. Choose 1-4: ";
        choice = validation();
    }

    if (prompts[multipleChoice[choice - 1]] == jepordy[row][col].answer)
    {
        cout << "The answer is correct. " << jepordy[row][col].points << " points.\n";
        teams[turn].points += jepordy[row][col].points;
    }
    else
    {
        cout << "The answer is Incorrect. " << jepordy[row][col].points << " points.\n";
        teams[turn].points -= jepordy[row][col].points;
    }
    return 0;
}

void showScore(team teams[])
{
    cout << "The current points for each team: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << teams[i].name << " has " << teams[i].points << " points. " << endl;
    }
}

void restartGame(team teams[], board jepordy[5][5])
{
    bool creative = false;
    string request;

    for (int i = 0; i < 3; i++)
    {
        teams[i].points = 0;
    }
    for (int row = 0; row < 5; row++)
        for (int col = 0; col < 5; col++)
            jepordy[row][col].used = false;

    cout << "Would you like to populate your own questions, or get a random category and question (y/n)? ";
    while ((cin >> request) && request != "y" && request != "Y" && request != "n" && request != "N")
    {
        cout << "Pleases enter y/Y for yes or n/N for no. ";
    }
    if (request == "y" || request == "Y")
        creative = true;
    else if (request == "n" || request == "N")
        creative = false;

    cin.ignore(1000, '\n');
    if (creative == true)
    {
        populateOwnQuestions(jepordy);
    }
}

void changePoints(team teams[])
{
    int piece;
    int score;
    do
    {
        cout << "What team's points would you like to change? (1,2,3) ";
        piece = validation();
        if (piece < 1 || piece > 3)
            cout << "Invalid choice, please pick 1 2 or 3";

    } while (piece < 1 || piece > 3);
    cout << "What is the new score?";
    score = validation();
    teams[piece - 1].points = score;
}
string chooseRandSubject() {
    ifstream file("Subjects.txt");
    srand(time(0));
    vector<string> subfiles;

    if (!file)
    {
        cout << "Error opening file: " << "Subjects.txt" << endl;
        return " ";
    }
    string line;
    while (getline(file, line))
    {
        subfiles.push_back(line);
    }
    file.close();
    int randomInt = rand() % subfiles.size();
    string category = readFile(subfiles[randomInt], jepordy);

    return category;
}
