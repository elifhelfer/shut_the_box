#include "shut_the_box.h"

void GameLogic::rollDice(){
    //check if 7 and up doors are closed
    currentRoll = 0;
    Dice dice = Dice();
    currentRoll += dice.roll();

    bool flag = false;

    for (int i=7; i<=box.getSize(); i++){
        if(box.isDoorOpen(i))
            flag = true;
    }
    if (flag){
        currentRoll+=dice.roll();
        std::cout << "Rolled 2 dice!\n";
    }
    else std::cout << "Rolled 1 die!\n";
}

void GameLogic::closeDoor(int door){
    currentRoll-=door;
    box.close(door);
}

bool GameLogic::isGameWon() const{
     if(box.getOpenDoors().size() == 0){
        return true;
     }
     return false;
}

InputResult GameLogic::handleInput(int input){
    if(!validadeInput(input)) //input is either too small, too big, or door isnt open
        return InputResult::InvalidMove;
    
    return InputResult::Success;
}

bool GameLogic::validadeInput(int input){
    return !(input < 0 || input > box.getSize() || !box.isDoorOpen(input) || input > currentRoll);
}

bool GameLogic::validChoiceExists(){
    for(int i=0; i<box.getOpenDoors().size(); i++){
        if(currentRoll < box.getOpenDoors()[i])
            continue;
        return true;
    }
    return false;
}

void GameLogic::gameOver(){
    int score {};
    for (int i=0; i<box.getOpenDoors().size(); i++){
        score += box.getOpenDoors()[i];
    }
    std::cout << "\n============GAME OVER===========\n";
    std::cout << "No more valid moves left, and there were " << currentRoll << " points unused.\n";
    std::cout << "Your score was: " << score << " points.\nReturning to menu.\n\n";
    
    return;
}