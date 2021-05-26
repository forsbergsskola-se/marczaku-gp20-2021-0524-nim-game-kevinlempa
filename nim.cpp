
#include <iostream>
#include <string>
#include<limits>
using namespace std;


class Nim
{
public:
	void Start()
	{
		char choice;
		cout << "Would you like to play vs AI : y/n ?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 'y' :
			PlayWithAI(true);
			break;
		case 'n' : 
			PlayWithAI(false);
			break;
		default:
			cin.clear();
			cin.ignore(256, '\n');
			Start();
		}
	}
	void PlayWithAI(bool ai)
	{

		int numberOfMatches = 24;
		bool winner = false;
		int n;
		bool playerTurn = true;
		do {
			srand(time(NULL));
			string player = playerTurn ? "Player 1" : "Player 2";
			if(ai)
				player = playerTurn ? "Player 1" : "AI";
			playerTurn = !playerTurn;
			string matches = "";
			PlayNim(numberOfMatches, ai, matches, player, n, winner, playerTurn);
		} while (!winner);
	}
	void PlayNim(int& numberOfMatches,bool& ai, std::string& matches, std::string& player, int& n, bool& winner, bool playerTurn)
	{
		if (numberOfMatches > 0) {
			matches = "";
			for (int i = 0; i < numberOfMatches; i++) {
				matches += "|";
			}
			cout << "There are " << numberOfMatches << " sticks" << endl;
			cout << matches << endl;
			cout << player + ", pick a number between 1 and 3" << endl;

			if (!ai)
				cin >> n;
			else if (!playerTurn)
				cin >> n;
			else {
				n = (rand() % 3) + 1;
			}

			if (n >= 1 && n <= 3) {
				if (n > numberOfMatches) {
					cout << player+" removed " << numberOfMatches << " stick(s)" << endl;
					numberOfMatches = 0;
				}
				else
					cout << player+" removed " << n << " stick(s)" << endl;
				numberOfMatches -= n;
			}
			else {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid number, try again." << endl;
				PlayNim(numberOfMatches, ai, matches, player, n, winner, playerTurn);
			}
			if (numberOfMatches < 1) {
				winner = true;
				player = playerTurn ? "Player 1" : "Player 2";
				if (ai)
					player = playerTurn ? "Player 1" : "AI";
				cout << player + " wins" << endl;
			}
		}
	}
};

int main()
{
	Nim nim;
	nim.Start();
}