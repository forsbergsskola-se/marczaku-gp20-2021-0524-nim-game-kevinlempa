#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
	char square[10] = { '0','1','2','3','4','5','6','7','8','9' };

	void drawBoard() {
		cout << "\n\n\tTic Tac Toe\n\n";

		cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
		cout << endl;

		cout << "     |     |     " << endl;
		cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

		cout << "     |     |     " << endl << endl;
	}
	int checkWin() {
		if (square[1] == square[2] && square[2] == square[3])

			return 1;
		else if (square[4] == square[5] && square[5] == square[6])

			return 1;
		else if (square[7] == square[8] && square[8] == square[9])

			return 1;
		else if (square[1] == square[4] && square[4] == square[7])

			return 1;
		else if (square[2] == square[5] && square[5] == square[8])

			return 1;
		else if (square[3] == square[6] && square[6] == square[9])

			return 1;
		else if (square[1] == square[5] && square[5] == square[9])

			return 1;
		else if (square[3] == square[5] && square[5] == square[7])

			return 1;
		else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
			&& square[4] != '4' && square[5] != '5' && square[6] != '6'
			&& square[7] != '7' && square[8] != '8' && square[9] != '9')

			return 0;
		else
			return -1;
	}

	bool checkBoard(int choice, char mark) {
		if (choice == 1 && square[1] == '1') {
			square[1] = mark;
			return true;
		}
		else if (choice == 2 && square[2] == '2') {
			square[2] = mark;
			return true;
		}
		else if (choice == 3 && square[3] == '3') {
			square[3] = mark;
			return true;
		}
		else if (choice == 4 && square[4] == '4') {
			square[4] = mark;
			return true;
		}
		else if (choice == 5 && square[5] == '5') {
			square[5] = mark;
			return true;
		}
		else if (choice == 6 && square[6] == '6') {
			square[6] = mark;
			return true;
		}
		else if (choice == 7 && square[7] == '7') {
			square[7] = mark;
			return true;
		}
		else if (choice == 8 && square[8] == '8') {
			square[8] = mark;
			return true;
		}
		else if (choice == 9 && square[9] == '9') {
			square[9] = mark;
			return true;
		}
		else return false;
	}

public:

	int StartGame() {
		srand(time(NULL));
		bool ai;
		char aichoice;
		cout << "Would you like to play vs AI : y/n ?" << endl;
		cin >> aichoice;
		switch (aichoice) {
		case 'y':
			ai = true;
			break;
		case 'n':
			ai = false;
			break;
		default:
			cin.clear();
			cin.ignore(256, '\n');
			StartGame();
		}

		int player = 1, i, choice;

		char mark;
		do {
			drawBoard();
			player = (player % 2) ? 1 : 2;
			mark = (player == 1) ? 'X' : 'O';

			if (ai && player == 2) {
				do {
					choice = (rand() % 9) + 1;
				} while (!checkBoard(choice, mark));

			}
			else {
				cout << "Player " << player << ", enter a number:  ";
				cin >> choice;
			}

			if (!checkBoard(choice, mark)) {
				if (ai && player == 2) {}
				else {
					cout << "\nInvalid move try again.";

					player--;
					cin.clear();
					cin.ignore(256, '\n');

				}

			}
			i = checkWin();

			player++;
		} while (i == -1);
		drawBoard();
		if (i == 1)

			cout << "==>Player " << --player << " won ";
		else
			cout << "==>Game draw";

		cin.ignore(256, '\n');
		cin.get();
		return 0;
	}

};

int main() {
	TicTacToe tic;
	return tic.StartGame();
}