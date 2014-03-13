#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game(int length);
        void run(std::string guess);
        int get_bulls();
        int get_cows();
        virtual ~Game();
    protected:
    private:
        unsigned int bulls;
        unsigned int cows;
        unsigned int length;
        int* answer;
        int* generate_answer();
        int* pre_process(std::string guess);
};

#endif // GAME_H
