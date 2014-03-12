#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();
        void run(int* guessNumber, int* answer);
        int get_bulls();
        int get_cows();
        virtual ~Game();
    protected:
    private:
        unsigned int bulls;
        unsigned int cows;
};

#endif // GAME_H
