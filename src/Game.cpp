#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stdio.h>
#include "Game.h"

using namespace std;

Game::Game(int length)
{
    this->length = length;
    answer = generate_answer();
}

Game::~Game()
{
    //dtor
}

void Game::run(string guess)
{
    bulls = 0;
    cows = 0;
    int* guessNumber = pre_process(guess);
    if(guessNumber == NULL) cout<<"exception";
    for (int i = 0; i < 4; i++)
    {
        if(guessNumber[i] == answer[i])
            bulls++;
        else
        {
            for (int j = 0; j < 4; j++) {
                if (guessNumber[i] == answer[j]) {
                    cows++;
                }
            }
        }
    }
}

string Game::result()
{
    char result[4];
    sprintf(result,"%dB%dC",bulls,cows);
    return result;
}

bool Game::over()
{
    return bulls == length;
}

int* Game::generate_answer()
  {
    int valid_numbers [9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        int j = rand()%10;
        int temp = valid_numbers[i];
        valid_numbers[i] = valid_numbers[j];
        valid_numbers[j] = temp;
    }
    int *answer = new int[length];
    memcpy(answer,valid_numbers,sizeof(int)*length);
    return answer;
  }

int* Game::pre_process(string guess)
{

    if (guess.length() != length)
    {
        cout << "Guess must be 4 digits.";
        return NULL;
    }

    const char* chars = guess.data();
    int *guessNumber = new int[length];
    for (unsigned int i = 0; i < length; i++)
    {
        int curNum = chars[i] - 48;
        if (curNum > 9 || curNum < 1)
        {
            cout << "Digit must be a 4-digit number within 1 to 9.";
            return NULL;
        }
        guessNumber[i] = curNum;
    }

    for(unsigned int i = 0; i < length; i++)
    {
        for(unsigned int j = i + 1; j < length; j++)
        {
            if(guessNumber[i] == guessNumber[j])
            {
                cout << "Digit must be a 4-digit number without duplication.";
                return NULL;
            }
        }
    }
    return guessNumber;
}
