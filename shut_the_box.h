#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

enum class GameState { menu, running, quit };

enum class InputResult {
    Success,
    InvalidMove
};

class Dice{
    public:
        inline static int roll() { return (std::rand() % 6 + 1); };
};

class Box{
    public:
        Box(int doorAmnt);
        void close(int door);
        void print() const;
        bool isDoorOpen(int door) const;
        inline const std::vector<int> getOpenDoors() const { return openDoors; };
        inline const int getSize() {return size;};
    
    private:
        std::vector<std::string> doors;
        std::vector<int> openDoors;
        int size;
};

class GameLogic{
    public:
        GameLogic(int doorAmnt) : box(doorAmnt), currentRoll(0) {};
        void closeDoor(int door); 
        void rollDice();
        bool isGameWon() const;
        inline int getCurrentRoll() const { return currentRoll; } ;
        const void printBox() const { box.print(); };
        InputResult handleInput(int input);
        bool validChoiceExists();
        void gameOver();

    private:
        bool validadeInput(int input);
        Box box;
        int currentRoll;
};

class GameApp{
    public:
        GameApp();
        void run();

    private:
        void menu();
        void gameLoop();
        int readInput();

        GameLogic currentGame;
        GameState gameState;

};