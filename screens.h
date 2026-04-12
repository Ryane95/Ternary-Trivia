/**************************
 * Ryan Edimo
 * Ternary Trivia project
 * Date Completed: April 12,2026
 * Description: This file defines the screens made in the screens.cpp file
 * Version: 1.0
 ***************************/
#ifndef Screens
#define Screens
#include <string>
#include <vector>
using namespace std;
namespace screens {

// This method simply presents an intro screen before the
// game starts and includes choices for exiting, adding your
// own questions, or selecting a category
void introScreen();

// A function that displays the question as well as it's category (passed in),
// the amounts of points it is
// worth and the answer choices
void questionScreen(string,string[],int);
void menuScreen();
void questionTable();
void aTeamsTurn(string);
void questionSelection(string);

} // namespace screens
#endif
