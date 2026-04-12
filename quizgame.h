#ifndef QUIZGAME_H
#define QUIZGAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct team
{
    string name;
    int points = 0;
};

struct board
{
    string question;
    string answer;
    string fake1, fake2, fake3;
    int points;
    bool used = false;
};

struct Question
{
    int value;
    string text;
    vector<string> answers;
    int correctIndex;
};

void readFile(string filename, board jepordy[][5]);
vector<string> splitLine(string line);
int getInput(int min, int max);
void pauseGame();
int getRandom(int max);

#endif