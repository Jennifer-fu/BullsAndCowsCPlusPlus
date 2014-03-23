#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{
    public:
        Game(int length);
        void run(string guess);
        string result();
        bool over();
        virtual ~Game();
    protected:
    private:
        unsigned int bulls;
        unsigned int cows;
        unsigned int length;
        int* answer;
        int* generate_answer();
        int* pre_process(string guess);
};

#endif // GAME_H
