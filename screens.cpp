/**************************
 * Ryan Edimo
 * Ternary Trivia project
 * Date Completed: April 12,2026
 * Version: 1.0
 ***************************/
#include "screens.h"
#include "quizgame.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void screens::introScreen()
{
cout << "===================================================================================\n";
cout << "|                                                                                  |\n";
cout << "|                             Welcome to Jeopardy!                                 |\n";
for (int counter =0; counter <5; counter++){
    cout << "|                                                                                  |\n";
}
cout << "===================================================================================\n";
pauseGame();
}
void screens::questionScreen(vector<vector<string>> questions, string category,
                             int index) {

}
