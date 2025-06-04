#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

enum class GameState { menu, running, win, lose };


class Dice{
    public:
        static int roll();
};

class Box{
    public:
        Box(int doorAmnt);
        void close(int doorNmbr);
        void print() const;
        bool isDoorOpen(int doorNmbr) const;
        const std::vector<int>& getOpenDoors() const;
    
    private:
        std::vector<std::string> doors;
        std::vector<int> openDoors;
};

class Game{
    public:
        Game(int doorAmnt) : box(doorAmnt){};
        void run();
        void handleInput(); 

    private:
        Box box;
        int currentRoll;
        GameState gameState = GameState::running;

};