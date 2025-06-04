#include "shut_the_box.h"

int Dice::roll(){
    srand(time(NULL));
    return (rand() % 6 + 1);
}

Box::Box(int doorAmnt){
    for (int i=0; i<doorAmnt; i++){
        doors.push_back("|" + std::to_string(i+1) + "|");
        openDoors.push_back(i+1);
    }
}

void Box::close(int doorNmbr){
    if (doorNmbr <= doors.size() && doorNmbr > 0){
        doors[doorNmbr-1] = ("[" + std::to_string(doorNmbr) + "]");
        openDoors.erase(openDoors.begin() + doorNmbr-1);
    }
    else 
        std::cout << "invalid door number!\n";
}

void Box::print(){
    for (int i = 0; i<doors.size(); i++){
        std::cout << doors[i] << " ";
    }
    std::cout << "\n";
}

bool Box::isDoorOpen(int doorNmbr){
        auto it = find(openDoors.begin(), openDoors.end(), doorNmbr);
        if (it != openDoors.end())
            return true;
        else return false;
}

void Game::run(){
    int input {};

    while(gameState == GameState::running){
        std::cin.clear();
        currentRoll = Dice::roll();
        std::cout << "Dice rolled. Balance: " << currentRoll << "\n";
        
        std::cout << "Which door will you close? ('Enter' to end round)\n";
        std::cin >> input;

    }
    

}

// int input = {};

//     std::cout << "---SHUT THE BOX---\n"; //TODO: menu with proper options (play, instructions, quit etc)
//     std::cout << "Do you want to play with 9 or 12 boxes?\n";
//     while(input != 9 && input != 12){
//         std::cin >> input;
//         std::cout << "\n";
//         std::cin.clear();
//     }

//     Game game = Game(input); //TODO: fix gameState's