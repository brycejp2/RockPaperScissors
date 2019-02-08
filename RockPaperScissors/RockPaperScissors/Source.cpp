

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {

	int userScore = 0;
	int computerScore = 0;
	char menuInput = ' ';
	srand(time(0)); 


	while (menuInput != 'q') {
		cout << "q to quit. p to play once. m to play multiple rounds in a row. s to see score" << endl;
		cin >> menuInput;
		cin.ignore();

		if (menuInput == 'q') {
			break;
		}
		else if (menuInput == 'p' || menuInput == 'm') {
			int roundsToBePlayed = 1;
			if (menuInput == 'm') {
				cout << "Enter how many times you would like to play: ";
				cin >> roundsToBePlayed;
			}

			for (int i = 0; i < roundsToBePlayed; i++) {
				int currentHand;
				bool isValidChoice = false;
				do {
					cout << "Enter your hand (0 for rock, 1 for paper, 2 for scissors): ";
					cin >> currentHand;
					cin.ignore();

					if (currentHand < 0 || currentHand > 2)
						cout << "Invalid choice!! Please try again." << endl;
					else
						isValidChoice = true;

				} while (!isValidChoice);

				//get computer's hand
				int cpChoice = rand() % 3; //0 - rock, 1 - paper, 2 - scissors

				if (cpChoice == currentHand) {
					cout << "tie - no score change" << endl;
				}
				else if (currentHand == 0) {
					if (cpChoice == 1) {
						cout << "Computer wins!" << endl;
						computerScore++;
					}
					else {
						cout << "player wins..." << endl;
						userScore++;
					}
				}
				else if (currentHand == 1) {
					if (cpChoice == 2) {
						cout << "Computer wins!" << endl;
						computerScore++;
					}
					else {
						cout << "player wins..." << endl;
						userScore++;
					}
				}
				else if (currentHand == 2) {
					if (cpChoice == 0) {
						cout << "Computer wins!" << endl;
						computerScore++;
					}
					else {
						cout << "player wins..." << endl;
						userScore++;
					}
				}
			}
		}
		else if (menuInput == 's') {
			cout << left << setw(15) << "Current user score: " << right << setw(3) << userScore << endl;
			cout << left << setw(15) << "Current computer score: " << right << setw(3) << computerScore << endl;
		}
		else
		{
			cout << "invalid input!! Please try again" << endl;
		}
	}
	cout << "Ending Score was: " << userScore << endl;
	cout << "Thanks for playing" << endl;

	system("pause");
	return 0;
}
