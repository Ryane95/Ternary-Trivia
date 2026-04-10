#include "quizgame.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    readFile("Math.txt");
    readFile("Science.txt");

    return 0;
}