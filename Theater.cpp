// Exercise 08 Guidelines
// Feel free to use any other logic/technique, i.e, it is not necessary to
// follow this approach.

#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

// Constants for rows and columns
const int ROWS = 15;
const int COLS = 30;

// Function prototypes
void pause();
void displayMenu();
int getChoice();
void displaySeats(const bool[][COLS]);
void displayPrices(const double[]);
void displaySales(double);
void purchaseTicket(bool[][COLS], const double[], double &);
void getPurchase(bool[][COLS], const double[], double &, int &, double &);

int main() {
  bool theater[ROWS][COLS] = {{false}};
  double ticketPrice[ROWS] = {0.0};
  double totalSales = 0.0;
  int choice;
  // Get seat prices for each of the ROWS rows
  for (int counter = 0; counter < ROWS; counter++) {
    cout << "Enter price for Row " << counter + 1 << ": ";
    cin >> ticketPrice[counter];
  }
  do {
    displayMenu();
    choice = getChoice();

    switch (choice) {
    case 1:
      displaySeats(theater);
      break;

    case 2:
      displayPrices(ticketPrice);
      break;

    case 3:
      displaySales(totalSales);
      break;

    case 4:
      purchaseTicket(theater, ticketPrice, totalSales);
      break;

    default: // Do nothing
      break;
    }

  } while (choice != 5);
  return 0;
}

// ********************************************************
// Function displayMenu                                   *
// Displays the menu of program options                   *
// ********************************************************
void displayMenu() {
  // Display menu of choices
  cout << "\n\n\n\t\tC++ Theatre" << endl << endl;
  cout << "\n\t1.  View Available Seats";
  cout << "\n\t2.  View Seating Prices";
  cout << "\n\t3.  View Ticket Sales";
  cout << "\n\t4.  Purchase a Ticket";
  cout << "\n\t5.  Exit the Program\n\n";
  cout << "\n\tEnter your choice(1-5):  ";
}
// pauses the screen.
void pause() {
  cout << "\nPress Enter to continue...";

  cout.flush();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cin.get();
}
// ********************************************************
// Function getChoice                                     *
// This function inputs, validates, and returns the       *
// user's choice                                          *
// ********************************************************
int getChoice() {
  int choice;
  cin >> choice;
  while (choice > 5 || choice < 1 || choice - static_cast<int>(choice) != 0) {
    cerr << "\n\tInvalid Choice. Enter your choice(1-5): ";
    cin >> choice;
  }
  return choice;
}
// ********************************************************
// Function displaySeats                                  *
// Displays a chart showing sold and available seats      *
// ********************************************************
void displaySeats(const bool theater[][COLS]) {
  cout << "\n\t";
  for (int counter = 1; counter <= COLS; counter++) {
    cout << (counter % 10);
  }
  cout << "\n\n";
  for (int row = 0; row < ROWS; row++) {
    cout << "Row " << setw(2) << row + 1 << " ";
    for (int column = 0; column < COLS; column++) {
      cout << (theater[row][column] ? 'X' : '.');
    }
    cout << "\n";
  }
  cout << "\nLegend: X=sold\t.=available";
  pause();
}

// ********************************************************
// Function displayPrices                                 *
// Displays ticket prices for each row                    *
// ********************************************************
void displayPrices(const double price[]) {
  cout << left << setw(5) << "Row" << right << setw(8) << "Price" << "\n";
  cout << "-------------------\n";
  for (int i = 0; i < ROWS; i++) {
    cout << left << setw(5) << (i + 1) << right << setw(8) << fixed
         << setprecision(2) << price[i] << "\n";
  }
  pause();
}

// ********************************************************
// Function purchaseTicket                                *
// Handles ticket purchases                               *
// ********************************************************
void purchaseTicket(bool theater[][COLS], const double price[],
                    double &totSales) {
  cout << "Would you like to see the seats before purchasing a ticket?(y/n): ";
  char answer;
  cin >> answer;
  while (answer != 'y' && answer != 'n') {
    cout << "Invalid input, please answer y (yes) or n (no):  ";
    cin >> answer;
  }
  if (answer == 'y') {
    displaySeats(theater);
  }
  answer = '\t';
  int numOfTickets = 0;
  double customerPrice = 0;
  do {
    getPurchase(theater, price, totSales, numOfTickets, customerPrice);
    cout << "\nWould you like to purchase another ticket? (y/n)";
    cin >> answer;
    while (answer != 'y' && answer != 'n') {
      cerr << "Please enter y (yes) or n (no): ";
      cin >> answer;
    }
  } while (answer == 'y' && answer != 'n');
  cout << "You have purchased a total of " << numOfTickets
       << " tickets for a total price of $" << setw(5) << fixed
       << setprecision(2) << customerPrice;
  customerPrice = 0;
}

void getPurchase(bool theater[][COLS], const double price[], double &totSales,
                 int &numOfTickets, double &customerPrice) {
  int seatNum = 0, rowNum = 0;
  cout << "please enter desired row number (1-15): ";
  cin >> rowNum;
  while (rowNum < 1 || rowNum > 15) {
    cout << "Row must be between 1 and 15. Please re-enter: ";
    cin >> rowNum;
  }
  rowNum--;
  cout << "please enter desired seat number (1-30): ";
  cin >> seatNum;
  while (seatNum < 1 || seatNum > 30) {
    cout << "Row must be between 1 and 30. Please re-enter: ";
    cin >> seatNum;
  }
  seatNum--;
  if (theater[rowNum][seatNum]) {
    cerr << "Sorry, this spot has already been sold";
  } else {
    theater[rowNum][seatNum] = true;
    double priceOfSeat = price[rowNum];
    totSales += priceOfSeat;
    customerPrice += priceOfSeat;
    numOfTickets++;
    cout << "Purchase confirmed";
  }
}
// ********************************************************
// Function displaySales                                  *
// Displays total sales information                       *
// ********************************************************
void displaySales(double totalSales) {
  cout << "\nTotal Sales to Date:  $" << totalSales;
}
