using namespace std;
#include <iostream>

class BinaryConverter {
private:
public:
	void decToBinary(int n) {

		int binaryNum[32];
		int i = 0;
		cout << "0b";
		while (n > 0) {
			binaryNum[i] = n % 2;
			n = n / 2;
			i++;
		}
		for (int j = i - 1; j >= 0; j--)
			cout << binaryNum[j];
		cout << endl;
	}
	int getNumber() {
		int number = 0;
		while (true) {
			cout << "Write a positive number :" << endl;
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input try again!" << endl;
			}
			else return number;
		}
	}
	void decToBinaryExtra(int n) {
		int i = 0;
		bool printZero = false;
		cout << "0b";
		for (int i = 31; i >= 0; i--) {
			int k = n >> i;
			if (k & 1) {
				cout << "1";
				printZero = true;
			}
			else if(printZero)
				cout << "0";
		}
	}
};
int main() {
	BinaryConverter bin;
	int n = bin.getNumber();
	bin.decToBinary(n);
	bin.decToBinaryExtra(n);
	return 0;
}