/**************************************
James Sturdivant
Group Project
Date: April 13th
Description: A game of Jepordy
Version: 1.4
***************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

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
int loadPoints(board jepordy[5][5]);
void shuffleTeams(team teams[]);
int order();
void displayMenu();
int getChoice();
int answerQuestion(team teams[], board jepordy[5][5]);
void showScore(team teams[]);
void restartGame(team teams[], board jepordy[5][5]);
void changePoints(team teams[]);
int validation();


int main()
{
	//Make sure to give a input validate function. 
	team team1, team2, team3;
	team teams[3];
	teams[0] = team1;
	teams[1] = team2;
	teams[2] = team3;

	//Add a file and import it into struct

	//Trying out structures with array
	board jepordy[5][5];
	//r for request
	string r, name;
	int i,j, choice;
	bool creative = false;

	screens::introScreen();
		for (int i = 0; i < 3; i++)
		{
			cout << "Team " << i + 1 << " is called? ";
			getline(cin,teams[i].name);
		}
		shuffleTeams(teams);

	cout << "Would you like to populate your own questions, or get a random category and question (y/n)? ";
	cin >> r;
	while (r != "y" && r != "Y" && r != "n" && r != "N")
	{
		cout << "Pleases enter y/Y for yes or n/N for no. ";
		cin >> r;
	}
		if (r == "y" || r == "Y")
			creative = true;
		else if (r == "n" || r == "N")
			creative = false;

	//Found cin >> ws; on https://stackoverflow.com/questions/58705197/cin-ws-vs-cin.ignorenumeric-limitsstreamsizemax-n
	//clears leftover characters until white space good for getline.
	cin >> ws; 
	if (creative == true)
	{
		for (i = 0; i < 5; i++ )
		{
			for (j = 0; j < 5; j++)
			{
				cout << "Please provide your question.";
				getline(cin, jepordy[i][j].question);
				cout << "What is the answer to your question?" ;
				getline(cin, jepordy[i][j].answer);
				cout << "Please enter three fake answers." << endl;
				getline(cin, jepordy[i][j].fake1);
				getline(cin, jepordy[i][j].fake2); 
				getline(cin, jepordy[i][j].fake3);

			}
		}
		creative = false;
	}

do
{
	displayMenu();
	choice = getChoice();

	switch (choice)
	{
	case 1: answerQuestion(teams, jepordy);
		break;

	case 2: showScore(teams);
		break;

	case 3: restartGame(teams, jepordy);
		break;

	case 4: changePoints(teams);
		break;

	default: // Do nothing
		break;
	}

} while (choice != 5);

return 0;
}

//void loadPoints(board Jepordy[5][5]){}

void shuffleTeams(team teams[])
{
	srand(time(0));
	for (int i = 0; i < 3; i++)
	{
		int r = rand() % 3;
		team temp = teams[i];
		teams[i] = teams[r];
		teams[r] = temp;
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
	while (!(cin >> valid)) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please put a integer: ";
	}
	return valid;
}

void displayMenu()
{
	// Display menu of choices
	cout << "\n\n\n\t\tTernary Trivia" << endl << endl;
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
	int r, c, teamChoice;
	int turn = order(); 

	screens::aTeamsTurn(teams[turn].name);

	screens::questionSelection("row");
	r = validation();
	while (r < 0 || r > 4)
	{
		cout << "Invalid row. Enter a row (0-4): ";
		r = validation();
	}

	screens::questionSelection("column");
	c = validation();
	while (c < 0 || c > 4)
	{
		cout << "Invalid column. Enter a column (0-4): ";
		c = validation();
	}

	if (jepordy[r][c].used)
	{
		cout << "That question has already been used.\n";
		return 0;
	}
	else
	{
		jepordy[r][c].used = true;
	}

	string prompts[4] = { jepordy[r][c].answer,jepordy[r][c].fake1 ,jepordy[r][c].fake2 ,jepordy[r][c].fake3};

	int multipleChoice[4] = {0,1,2,3};

	for (int i = 0; i < 4; i++)
	{
		int j = rand() % 4;
		int temp = multipleChoice[i];
		multipleChoice[i] = multipleChoice[j];
		multipleChoice[j] = temp;
	}
	
	//cout << jepordy[row][col].question << endl << endl;

	//for (int i = 0; i < 4; i++)
	//{
	//	cout << i + 1 << ") " << prompts[multipleChoice[i]] << endl;
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
		cout << "The answer is correct. " << jepordy[r][c].points << " points.\n";
		teams[turn].points += jepordy[r][c].points;
	}
	else
	{
		cout << "The answer is Incorrect. " << jepordy[r][c].points << " points.\n";
		teams[turn].points -= jepordy[r][c].points;
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
	for (int i = 0; i < 3; i++)
	{
		teams[i].points = 0;
	}
	for (int r = 0; r < 5; r++)
		for (int c = 0; c < 5; c++)
			jepordy[r][c].used = false;

}


void changePoints(team teams[])
{
	int piece;
	int score;
	do {
		cout << "What team's points would you like to change? (1,2,3) ";
		piece = validation();
		if (piece < 1 || piece > 3)
			cout << "Invalid choice, please pick 1 2 or 3";

	} while (piece < 1 || piece > 3);
	cout << "What is the new score?";
	score = validation();
	teams[piece - 1].points = score;
}

