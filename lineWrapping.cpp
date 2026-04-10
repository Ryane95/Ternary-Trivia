/******
 * This code is from AI: it's inspiration for line wrapping the arbitrary
 * strings into the UI
 ******/
#include <iostream>
#include <string>
using namespace std;

void printWrappedBox(const string &question, int width) {
  // width = number of characters inside the box (not counting borders)
  // Top border

  int pos = 0;
  int n = question.size();

  while (pos < n) {
    int lineStart = pos;
    int lineLen = 0;

    // Try to extend the line up to width characters
    while (pos < n && lineLen < width) {
      // If adding this character exceeds width, break
      if (lineLen + 1 > width)
        break;

      // If it's a space and the next word won't fit, break
      if (question[pos] == ' ') {
        int nextWordLen = 0;
        int temp = pos + 1;
        while (temp < n && question[temp] != ' ' && nextWordLen < width) {
          nextWordLen++;
          temp++;
        }
        if (lineLen + 1 + nextWordLen > width)
          break;
      }

      pos++;
      lineLen++;
    }

    // Extract the substring for this line
    string line = question.substr(lineStart, lineLen);

    // Pad with spaces to fill the width
    if (line.size() < (size_t)width)
      line += string(width - line.size(), ' ');

    // Print inside border
    cout << line << "\n";

    // Skip any extra spaces before next line
    while (pos < n && question[pos] == ' ')
      pos++;
  }
}

int main() {
  string q = "This is a very long question that needs to wrap inside a box "
             "without using any extra libraries. I am sure adding any more "
             "characters to test the limits of this code is fine right ? Who "
             "knows how long the questions or answers will be in the game!";
  printWrappedBox(q, 25);
}
