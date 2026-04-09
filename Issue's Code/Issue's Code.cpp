/**************************************
James Sturdivant
Group Project
Date: April 13th
Description: A game of Jepordy
Version: 1.3
***************************************/
#include <iostream>
#include <string>
#include <limits>

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
	int points;
	bool used = false;
};
int getchoice();

int main()
{
	//Make sure to give a input validate function.
	team team1, team2, team3;
	//Add a file and import it into struct

	//Trying out structures with array
	board jepordy[5][5];
	//r for request
	string r;
	int i, j, choice;
	bool creative = false;


	cout << "Would you like to populate your own questions, or get a random category and question (y/n)? ";
	cin >> r;
	while (r != "y" || r != "Y" || r != "n" || r != "N")
	{
		if (r == "y" || r == "Y")
			creative = true;
		else if (r == "n" || r == "N")
			creative = false;
		else
		{
			cout << "Pleases enter y/Y for yes or n/N for no. ";
			cin >> r;
		}
	}
	//Found cin >> ws; on https://stackoverflow.com/questions/58705197/cin-ws-vs-cin.ignorenumeric-limitsstreamsizemax-n
	//clears leftover characters until white space good for getline.
	cin >> ws;
	while (creative == true)
	{
		for (i = 0; 5 >= i; i++)
		{
			for (j = 0; 5 >= j; j++)
			{
				cout << "Please provide your question.";
				getline(cin, jepordy[i][j].question);
				cout << "What is the answer to your question?";
				getline(cin, jepordy[i][j].answer);
			}
		}
	}
	do
	{
		displayMenu();
		choice = getChoice();

		switch (choice)
		{
		case 1: displaySeats();
			break;

		case 2: displayPrices();
			break;

		case 3: displaySales();
			break;

		case 4: purchaseTicket();
			break;

		default: // Do nothing
			break;
		}
	} while (choice != 5);

	return 0;
}

void displayMenu()
{
	// Display menu of choices
	cout << "\n\n\n\t\tTernary Trivia" << endl << endl;
	cout << "\n\t1. Answer a question";
	cout << "\n\t2. Check current points";
	cout << "\n\t3. Restart game";
	cout << "\n\t4. Change current points";
	cout << "\n\t5. Exit the Program\n\n";
	cout << "\n\tEnter your choice(1-5): ";
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
		if (choice < 1 || choice > 5)
		{
			cout << "The number must be between 1 to 5" << endl;
		}
	}
	return choice;
}

void answerQuestion()
{

}

void checkPoints()
{

}

void restartGame()
{

}

void changePoints()
{

}