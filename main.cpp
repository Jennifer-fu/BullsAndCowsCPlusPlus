#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Game.h>
#include <InvalidInputException.h>

using namespace std;

const int ANSWER_LENGTH = 4;

int welcom()
{
    string answer;
    while (true)
    {
      if (!getline(cin, answer))
      {
        cout << "I can't get an answer. Exiting.\n";
        return EXIT_FAILURE;
      }
      if (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y")
        break;
      if (answer == "no" || answer == "No" || answer == "n" || answer == "N")
      {
        cout << "Ok. Goodbye.\n";
        return EXIT_SUCCESS;
      }
      cout << "Please answer yes or no: ";
    }
}

int main()
{
  cout << "Welcome to bulls and cows!\nDo you want to play? ";
  while (true)
  {
      if(!welcom()) return EXIT_SUCCESS;
      string guess;
      Game game(ANSWER_LENGTH);
      while (cout << "Your guess? ", getline(cin, guess))
      {
        try{
            game.run(guess);
            cout << game.result()<<"\n";
            if (game.over())
            {
                cout << "Congratulations! You have won!\n";
                break;
            }
        }catch(InvalidInputException e)
        {
            cout << e.get_message();
        }
      }
      cout << "Another game? ";
  }
}

