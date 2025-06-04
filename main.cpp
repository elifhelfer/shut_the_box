#include "shut_the_box.h"

int main(){

    int input {};

    std::cout << "---SHUT THE BOX---\n"; //TODO: menu with proper options (play, instructions, quit etc)
    std::cout << "Do you want to play with 9 or 12 boxes?\n";

    while(input != 9 && input != 12){
        std::cin >> input;
        if(input != 9 && input != 12) 
            std::cout << "invalid input. Try again (choose 9 or 12)\n";
        std::cin.clear();
    }

    Game game = Game(input); //TODO: fix gameState's

    game.run();

    return 0;
}