#include "Game.h"

Game::Game()
{
    bulls = 0;
    cows = 0;
}

Game::~Game()
{
    //dtor
}

void Game::run(int* guessNumber, int* answer)
{
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

int Game::get_bulls()
{
    return bulls;
}

int Game::get_cows()
{
    return cows;
}
