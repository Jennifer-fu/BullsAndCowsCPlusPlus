#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Game.h>

using namespace std;

int* generateAnswer()
  {
    int valid_numbers [9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        int j = rand()%10;
        int temp = valid_numbers[i];
        valid_numbers[i] = valid_numbers[j];
        valid_numbers[j] = temp;
    }
    int *answer = new int[4];
    memcpy(answer,valid_numbers,sizeof(int)*4);
    return answer;
  }


int main()
{
  cout << "Welcome to bulls and cows!\nDo you want to play? ";
  string answer;
  while (true)
  {
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


    int *answer = generateAnswer();
    string guess;
    while (cout << "Your guess? ", getline(cin, guess))
    {
        bool isValid = true;

        if (guess.length() != 4)
        {
            cout << "Guess must be 4 digits.";
            continue;
        }

        const char* chars = guess.data();
        int *guessNumber = new int[4];
        for (int i = 0; i < 4; i++)
        {
            int curNum = chars[i] - 48;
            if (curNum > 9 || curNum < 1)
            {
                cout << "Digit must be a 4-digit number within 1 to 9.";
                isValid = false;
                break;
            }
            guessNumber[i] = curNum;
        }

        if(!isValid)continue;

        for(int i = 0; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                if(guessNumber[i] == guessNumber[j])
                {
                    cout << "Digit must be a 4-digit number without duplication.";
                    isValid = false;
                    break;
                }
            }
            if(!isValid)break;
        }

        if(!isValid)continue;

//        unsigned int bulls = 0;
//        unsigned int cows = 0;
//        for (int i = 0; i < 4; i++)
//        {
//            if(guessNumber[i] == answer[i])
//                bulls++;
//            else
//            {
//                for (int j = 0; j < 4; j++) {
//                    if (guessNumber[i] == answer[j]) {
//                        cows++;
//                    }
//                }
//            }
//        }
        Game game;
        game.run(guessNumber, answer);
        cout << game.get_bulls() << " bulls, " << game.get_cows() << " cows.\n";
        if (game.get_bulls() == 4)
        {
            cout << "Congratulations! You have won!\n";
            break;
        }
    }
    cout << "Another game? ";
  }
}

