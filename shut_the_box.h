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
        void print();
        bool isDoorOpen(int doorNmbr);
    
    private:
        std::vector<std::string> doors;
        std::vector<int> openDoors = {};
};

class Game{
    public:
        Game(int doorAmnt) : box(doorAmnt){};
        void run();
        void handleInput(); 
        void printMenu();
        void printInstructions();

    private:
        Box box;
        int currentRoll;
        std::vector<int> openDoors();
        GameState gameState = GameState::menu;

};