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
	}


};
int main() {
	BinaryConverter bin;
	bin.decToBinary(25);
}