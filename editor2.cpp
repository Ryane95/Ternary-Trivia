/**************************************
Jack Harris
Group Project
Date: April 13th
Description: editor for Jepordy
Version: 0
***************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "quizgame.h"
#include "Updated Project folder/editor2.h"

using namespace std;
    vector<string> showFile(string filename)
    {
        ifstream file(filename);

        vector<string> subfiles;
        int numline = 1;

        if (!file)
        {
            cout << "Error opening file: " << filename << endl;
            return {};
        }
        string line;
        while (getline(file, line))
        {
            subfiles.push_back(line);
            cout << numline++ << ". " << line << endl;
        }

        file.close();
        return subfiles;
    }

    vector<string> showFile2(string filename)
    {
        ifstream file(filename);

        vector<string> subfiles;

        if (!file)
        {
            cout << "Error opening file: " << filename << endl;
            return {};
        }
        string line;
        while (getline(file, line))
        {
            subfiles.push_back(line);
            cout << line << endl;
        }

        file.close();
        return subfiles;
    }

    void write_Question(string filename, int diff, string question, string answer1, string answer2, string answer3, string answer4, string correct_Answer)
    {
        ofstream file(filename, ios::app);

        if (!file)
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }
        file << "\n" << diff << "\t" << question << "\t" << answer1 << "\t" << answer2 << "\t" << answer3 << "\t" << answer4 << "\t" << correct_Answer;

        file.close();
        return;
    }

    void innitiat_File(string filename)
    {
        ofstream file(filename, ios::app);

        if (!file)
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }
        filename.pop_back();
        filename.pop_back();
        filename.pop_back();
        filename.pop_back();
        file << filename; // adds category to the top of new file

        file.close();
        ofstream oldfile("Subjects.txt", ios::app); // adds new category to list of subjects

        oldfile << "\n" << filename << ".txt";

        oldfile.close();
        return;
    }

    //int getInput(int min, int max)
    //{
    //    int choice;
    //
    //    while (true)
    //    {
    //        cin >> choice;
    //
    //        if (cin.fail())
    //        {
    //            cin.clear();
    //            cin.ignore(1000, '\n');
    //            cout << "Invalid input.\n";
    //        }
    //        else if (choice < min || choice > max)
    //        {
    //            cout << "Out of range.\n";
    //        }
    //        else
    //        {
    //            return choice;
    //        }
    //    }
    //}

    string getstring()
    {
        string choice;

        while (true)
        {
            getline(cin, choice);

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input.\n";
            }
            else {
                return choice;
            }
        }
    }


    void fileEditor()
    {

        string Newquestion;
        string newfile;
        int filenum;
        int difficulty;
        string question, answer1, answer2, answer3, answer4, correct_Answer;

        // explanation
        cout << "This is the editor \n";
        cout << "This menu allows the addition of new subjects and new questions to old subjects \n";
        cout << "Subjects are orginized by file \n";
        cout << "each question is orginized like this \n";
        cout << "difficulty(1-5)), Question, answer1, answer2, ansewer3, answer4, correct answer \n";
        cout << "current subject files available:\n";

        vector<string> subjectfiles = showFile("Subjects.txt"); // shows all the available subjects

        cout << endl;
        cout << "Create a new file by entering 0 or edit an existing file by enetering its corrisponding number." << endl;
        filenum = getInput(0, subjectfiles.size()) - 1;// finds what the user wants to do
        cin.ignore(1000, '\n');
        if (filenum == -1) {
            cout << "Input the name of the new subject file ex: subject.txt \n";
            string newfile = getstring();
            cin.ignore(1000, '\n');
            innitiat_File(newfile);
            bool editing = true;
            do {
                bool inputcheck = true;
                do {
                    cout << "add new question Y or N: "; //loop that allows user to add as many questions as they want
                    Newquestion = getstring();
                    if (Newquestion == "Y" or Newquestion == "y" or Newquestion == "N" or Newquestion == "n") {
                        inputcheck = false;
                    }
                    else {
                        cout << "Invalid input.\n";
                    }
                } while (inputcheck); // checks input
                if (Newquestion == "Y" or Newquestion == "y") {
                    cout << "pls remember: difficulty(1 - 5)), Question, answer1, answer2, answer3, answer4, correct answer \n"; // gets all pieces for new question
                    cout << "enter difficulty (1-5):";
                    difficulty = getInput(1, 5);
                    cin.ignore(1000, '\n');
                    cout << "Eneter Question: ";
                    question = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer1: ";
                    answer1 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer2: ";
                    answer2 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer3: ";
                    answer3 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer4: ";
                    answer4 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter correct answer (make sure it is the exact same as one of the existing answers): ";
                    correct_Answer = getstring();
                    cin.ignore(1000, '\n');
                    write_Question(newfile, difficulty, question, answer1, answer2, answer3, answer4, correct_Answer); // adds new question to the bottom of the list
                }
                else {
                    editing = false;
                }

            } while (editing);
        }
        else {
            cout << "this is all the information on the " << subjectfiles[filenum] << " file" << endl; // shows all questions in the file that is being edited
            showFile2(subjectfiles[filenum]);
            bool editing = true;
            do {
                bool inputcheck = true;
                do {
                    cout << "add new question Y or N: "; //loop that allows user to add as many questions as they want
                    Newquestion = getstring();
                    if (Newquestion == "Y" or Newquestion == "y" or Newquestion == "N" or Newquestion == "n") {
                        inputcheck = false;
                    }
                    else {
                        cout << "Invalid input.\n";
                    }
                } while (inputcheck); // checks input
                if (Newquestion == "Y" or Newquestion == "y") {
                    cout << "pls remember: difficulty(1 - 5)), Question, answer1, answer2, answer3, answer4, correct answer \n";
                    cout << "enter difficulty (1-5):";
                    difficulty = getInput(1, 5);
                    cin.ignore(1000, '\n');
                    cout << "Eneter Question: ";
                    question = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer1: ";
                    answer1 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer2: ";
                    answer2 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer3: ";
                    answer3 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter answer4: ";
                    answer4 = getstring();
                    cin.ignore(1000, '\n');
                    cout << "Eneter correct answer (make sure it is the exact same as one of the existing answers): ";
                    correct_Answer = getstring();
                    cin.ignore(1000, '\n');
                    write_Question(subjectfiles[filenum], difficulty, question, answer1, answer2, answer3, answer4, correct_Answer);
                }
                else {
                    editing = false;
                }

            } while (editing);
        }
    }
