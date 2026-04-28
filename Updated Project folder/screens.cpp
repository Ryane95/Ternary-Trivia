/**************************
 * Ryan Edimo
 * Ternary Trivia project
 * Date Completed: April 12,2026
 * Version: 1.0
 ***************************/
#include "screens.h"
#include "quizgame.h"
#include <iostream>
#include <string>
using namespace std;

void printWrappedString(string beforeString, string &String, int width,
                        string AfterString) {
  int currentPosition = 0;
  int size = String.size();

  while (currentPosition < size) {
    int lineStart = currentPosition;
    int lineLen = 0;
    while (lineLen < width && currentPosition < size) {
      if (lineLen + 1 > width)
        break;
      if (currentPosition < size && String[currentPosition] == ' ') {
        int nextWordLen = 0;
        int temp = currentPosition + 1;
        while (temp < size && String[temp] != ' ' && nextWordLen < width) {
          nextWordLen++;
          temp++;
        }
        if (lineLen + 1 + nextWordLen > width)
          break;
      }
      currentPosition++;
      lineLen++;
    }
    string line = String.substr(lineStart, lineLen);
    if (line.size() < (size_t)width)
      line += string(width - line.size(), ' ');
    cout << beforeString << line << AfterString << "\n";
    while (currentPosition < size && String[currentPosition] == ' ')
      currentPosition++;
  }
}

void screens::introScreen() {
  cout << "===================================================================="
          "===============\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                             Welcome to Jeopardy!                  "
          "               |\n";
  for (int counter = 0; counter < 5; counter++) {
    cout << "|                                                                 "
            "                 |\n";
  }
  cout << "                            (Press Enter to continue)               "
          "              |\n";
  cout << "===================================================================="
          "===============\n";
  pauseGame();
}
void screens::menuScreen() {
  cout << "===================================================================="
          "===============\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                             Ternary Trivia                        "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                       What would you like to do?                  "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|               1.Answer a question                                 "
          "               |\n";
  cout << "|               2.Check current points                              "
          "               |\n";
  cout << "|               3.Restart Game                                      "
          "               |\n";
  cout << "|               4.Change current points                             "
          "               |\n";
  cout << "|               5.Exit the program                                  "
          "               |\n";
  for (int count = 0; count < 2; count++) {
    cout << "|                                                                 "
            "                 |\n";
  }
  cout << "|                                                                   "
          "      _________|\n";
  cout << "|                                                                   "
          "      |         \n";
  cout << "===================================================================="
          "======| :";
}
void screens::menuScreen(string category) {
  cout << "===================================================================="
          "===============\n";
  printWrappedString("|                    category: ", category, 14,
                     "                                       |\n");
  cout << "|                                                                   "
          "               |\n";
  cout << "|                             Ternary Trivia                        "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                       What would you like to do?                  "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|               1.Answer a question                                 "
          "               |\n";
  cout << "|               2.Check current points                              "
          "               |\n";
  cout << "|               3.Restart Game                                      "
          "               |\n";
  cout << "|               4.Change current points                             "
          "               |\n";
  cout << "|               5.Exit the program                                  "
          "               |\n";
  for (int count = 0; count < 2; count++) {
    cout << "|                                                                 "
            "                 |\n";
  }
  cout << "|                                                                   "
          "      _________|\n";
  cout << "|                                                                   "
          "      |         \n";
  cout << "===================================================================="
          "======| :";
}
void screens::questionTable() {}
void screens::aTeamsTurn(string teamName) {
  cout << "===================================================================="
          "===============\n";
  for (int counter = 0; counter < 6; counter++) {
    cout << "|                                                                 "
            "                 |\n";
  }
  string announcement = "It is team: " + teamName + "'s turn...";
  printWrappedString("|          ", announcement, 33,
                     "                                       |");
  for (int counter = 0; counter < 3; counter++) {
    cout << "|                                                                 "
            "                 |\n";
  }
  cout << "|                                                                   "
          "  ____________|\n";
  cout << "|                                                                   "
          " |             \n";
  cout << "===================================================================="
          "=| :(press enter)";
  pauseGame();
}
void screens::questionSelection(string rowOrColumn) {
  if (rowOrColumn == "row") {
    cout << "=================================================================="
            "==================\n";
    cout << "|                                                                 "
            "                 |\n";
    cout << "|                  Choose your question(enter a row (0-4) )       "
            "                 |\n";
    cout << "|                                                                 "
            "                 |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 0. 100      |    | 0. 100      |     | 0. 100      |    | "
            "0. 100    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 1. 200      |    | 1. 200      |     | 1. 200      |    | "
            "1. 200    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 2. 300      |    | 2. 300      |     | 2. 300      |    | "
            "2. 300    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 3. 400      |    | 3. 400      |     | 3. 400      |    | "
            "3. 400    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 4. 500      |    | 4. 500      |     | 4. 500      |    | "
            " 4. 500   |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________| _____|\n";
    cout << "|                                                                 "
            "           |      \n";
    cout << "=================================================================="
            "===========| :";
  }
  if (rowOrColumn == "column") {
    cout << "=================================================================="
            "==================\n";
    cout << "|                                                                 "
            "                 |\n";
    cout << "|                Choose your question(enter a column (0-4) )      "
            "                 |\n";
    cout << "|                                                                 "
            "                 |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 0. 100      |    | 0. 100      |     | 0. 100      |    | "
            "0. 100    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 1. 200      |    | 1. 200      |     | 1. 200      |    | "
            "1. 200    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 2. 300      |    | 2. 300      |     | 2. 300      |    | "
            "2. 300    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 3. 400      |    | 3. 400      |     | 3. 400      |    | "
            "3. 400    |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________|      |\n";
    cout << "|      _____________      _____________       _____________      "
            "___________       |\n";
    cout << "|     |             |    |             |     |             |    | "
            "          |      |\n";
    cout << "|     | 4. 500      |    | 4. 500      |     | 4. 500      |    | "
            " 4. 500   |      |\n";
    cout << "|     |_____________|    |_____________|     |_____________|    "
            "|___________| _____|\n";
    cout << "|                                                                 "
            "           |      \n";
    cout << "=================================================================="
            "===========| :";
  }
}
void screens::questionScreen(string question, string multipleChoice[],
                             int row) {
  row += 1;
  string prompt[4];
  int MultipleChoice[4] = {0, 1, 2, 3};
  for (int i = 0; i < 4; i++) {
    int j = rand() % 4;
    int temp = MultipleChoice[i];
    MultipleChoice[i] = MultipleChoice[j];
    MultipleChoice[j] = temp;
  }
  for (int i = 0; i < 4; i++) {
    prompt[i] = to_string(i + 1) + ") " + multipleChoice[MultipleChoice[i]];
  }
  cout << "===================================================================="
          "===============\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                           Question" << to_string(row) << " : ("
       << to_string(row) << "00 points)                               | \n";
  cout << "|                                                                   "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  printWrappedString("|                 ", question, 53, "            |");
  cout << "|                                                                   "
          "               |\n";
  cout << "|                                                                   "
          "               |\n";
  for (int counter = 0; counter < 4; counter++) {
    printWrappedString(
        "|               ", prompt[counter], 13,
        "                                                      |\n");
  }
  cout << "|                                                                   "
          "               |\n";
  cout << "|                                                                   "
          "      _________|\n";
  cout << "|                                                                   "
          "      |        \n";
  cout << "===================================================================="
          "======| :";
}
