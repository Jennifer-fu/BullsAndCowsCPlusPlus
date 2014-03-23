#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <Game.h>
#include <InvalidInputException.h>

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
    check_length(guess);
    check_digits(guess);
    int *guessNumber = change_to_int_array(guess);
    check_duplication(guessNumber);
    return guessNumber;
}

void Game::check_length(string guess)
{
       if (guess.length() != length)
    {
        InvalidInputException exception("Guess must be 4 digits.");
        throw exception;
    }
}

void Game::check_digits(string guess)
{
    const char* chars = guess.data();
    for (unsigned int i = 0; i < length; i++)
    {
        int curNum = chars[i] - 48;
        if (curNum > 9 || curNum < 1)
        {
            InvalidInputException exception("Digit must be a 4-digit number within 1 to 9.");
            throw exception;
        }
    }
}

int* Game::change_to_int_array(string guess)
{
    const char* chars = guess.data();
    int *guessNumber = new int[length];
    for (unsigned int i = 0; i < length; i++)
    {
        guessNumber[i] = chars[i] - 48;
    }
    return guessNumber;
}

void Game::check_duplication(int* guessNumber)
{
    for(unsigned int i = 0; i < length; i++)
    {
        for(unsigned int j = i + 1; j < length; j++)
        {
            if(guessNumber[i] == guessNumber[j])
            {
                InvalidInputException exception("Digit must be a 4-digit number without duplication.");
                throw exception;
            }
        }
    }
}
