#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Game.h>

using namespace std;

const int ANSWER_LENGTH = 4;

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
    int *answer = new int[ANSWER_LENGTH];
    memcpy(answer,valid_numbers,sizeof(int)*ANSWER_LENGTH);
    return answer;
  }

//int* pre_process(string guess)
//{
//    bool isValid = true;
//
//    if (guess.length() != ANSWER_LENGTH)
//    {
//        cout << "Guess must be 4 digits.";
//        return NULL;
//    }
//
//    const char* chars = guess.data();
//    int *guessNumber = new int[ANSWER_LENGTH];
//    for (int i = 0; i < ANSWER_LENGTH; i++)
//    {
//        int curNum = chars[i] - 48;
//        if (curNum > 9 || curNum < 1)
//        {
//            cout << "Digit must be a 4-digit number within 1 to 9.";
//            isValid = false;
//            return NULL;
//        }
//        guessNumber[i] = curNum;
//    }
//
//    for(int i = 0; i < ANSWER_LENGTH; i++)
//    {
//        for(int j = i + 1; j < ANSWER_LENGTH; j++)
//        {
//            if(guessNumber[i] == guessNumber[j])
//            {
//                cout << "Digit must be a 4-digit number without duplication.";
//                isValid = false;
//                return NULL;
//            }
//        }
//    }
//    return guessNumber;
//}


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
    Game game(ANSWER_LENGTH);
    while (cout << "Your guess? ", getline(cin, guess))
    {
        game.run(guess);
        cout << game.get_bulls() << " bulls, " << game.get_cows() << " cows.\n";
        if (game.get_bulls() == ANSWER_LENGTH)
        {
            cout << "Congratulations! You have won!\n";
            break;
        }
    }
    cout << "Another game? ";
  }
}

