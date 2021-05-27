#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
	char square[10] = { '0','1','2','3','4','5','6','7','8','9' };

	void board() {
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
	int checkwin() {
		for (int i = 1; i < 7; i += 3) {
			if (square[i] == square[i + 1] && square[i + 1] == square[i + 2])
				return 1;
		}
		for (int i = 1; i < 3; i++) {
			if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])

				return 1;
		}
		if (square[1] == square[5] && square[5] == square[9])

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

public:

	int StartGame() {

		int player = 1, i, choice;

		char mark;
		do {
			board();
			player = (player % 2) ? 1 : 2;

			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';
			if (choice == 1 && square[1] == '1')

				square[1] = mark;
			else if (choice == 2 && square[2] == '2')

				square[2] = mark;
			else if (choice == 3 && square[3] == '3')

				square[3] = mark;
			else if (choice == 4 && square[4] == '4')

				square[4] = mark;
			else if (choice == 5 && square[5] == '5')

				square[5] = mark;
			else if (choice == 6 && square[6] == '6')

				square[6] = mark;
			else if (choice == 7 && square[7] == '7')

				square[7] = mark;
			else if (choice == 8 && square[8] == '8')

				square[8] = mark;
			else if (choice == 9 && square[9] == '9')

				square[9] = mark;

			else {
				cout << "\nInvalid move ";

				player--;
				cin.clear();
				cin.ignore(256, '\n');
				cin.get();
			}
			i = checkwin();

			player++;
		} while (i == -1);
		board();
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