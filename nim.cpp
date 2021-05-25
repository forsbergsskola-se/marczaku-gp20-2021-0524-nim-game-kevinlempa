
#include <iostream>
#include <string>
using namespace std;


class Nim
{
public:
   void Start(int numberOfMatches)
   {
      TwoPlayers(numberOfMatches);
   }
   void TwoPlayers(int numberOfMatches)
   {
      bool winner = false;
      int n;
      do
      {
         if (numberOfMatches > 0)
         {
            cout << "There are " << numberOfMatches << " sticks" << endl;
            cout << "Player 1, pick a number between 1 and 3" << endl;
            cin >> n;
            if (n >= 1 && n <= 3)
            {
               cout << "You have removed " << n << " stick(s)" << endl;
               numberOfMatches -= n;
            }
            else
            {
               cout << " Invalid number" << endl;
            }
            if (numberOfMatches < 1)
            {
               winner = true;
               cout << " Player 2 wins" << endl;
            }
         }
         if (numberOfMatches > 0)
         {
            cout << "There are " << numberOfMatches << " sticks" << endl;
            cout << "Player 2, pick a number between 1 and 3" << endl;
            cin >> n;
            if (n >= 1 && n <= 3)
            {
               cout << "You have removed " << n << " stick(s)" << endl;
               numberOfMatches -= n;
            }
            else
            {
               cout << " Invalid number " << endl;
            }
            if (numberOfMatches < 1)
            {
               winner = true;
               cout << " Player 1 wins" << endl;
            }
         }

      } while (!winner);
   }
};

int main()
{
   Nim nim;
   nim.Start(24);
}