#ifndef QUIZGAME_H
#define QUIZGAME_H

#include <string>
#include <vector>

using namespace std;

struct Question
{
    int value;
    string text;
    vector<string> answers;
    int correctIndex;
};

int getRandom(int max);
vector<string> splitLine(string line);
void readFile(string filename);
int getInput(int min, int max);
void pauseGame();

#endif