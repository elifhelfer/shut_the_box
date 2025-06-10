#include "shut_the_box.h"

void GameApp::menu(){
    int userOption {};

    std::cout << "-----SHUT THE BOX------\n";
    std::cout << "(1) Play game\n";
    std::cout << "(2) Show instructions\n";
    std::cout << "(3) Quit\n";
    std::cout << "-----------------------\n";
    
    do{
        userOption = readInput();

        if(userOption == 1){
            std::cout << "-----CONFIGURATION-----\n";
            std::cout << "How many doors? [9 or 12]\n" << std::flush;
            std::cout << "-----------------------\n";

            userOption = readInput();

            while(!(userOption == 12 || userOption == 9)){
                std::cout << "Invalid option! Only 9 or 12 doors\n" << std::flush;
                userOption = readInput();
            }

            currentGame = GameLogic(userOption);
            gameState = GameState::running;
            return;
        }
        else if(userOption == 2){
            std::cout << "======INSTRUCTIONS======\n";
            std::cout << "The box's doors start open. The player rolls 2 dice (or 1, if doors 7 and up are closed) and has to close doors that are <= than the sum of the dice rolls.\n";
            std::cout << "For the turn to end, the player has to use up all of their dice roll points. If there are no allowed moves using the players current balance, they lose. If they manage to close all doors, they win.\n";
            std::cout << "========================\n\n";
        }

        else if(userOption == 3){
            std::cout << "Quitting...\n";
            gameState = GameState::quit;
        }
    } while (userOption > 3 && userOption < 1);
}

GameApp::GameApp() : currentGame(9), gameState(GameState::menu){
}

void GameApp::run(){
    srand(time(NULL));

    while(gameState != GameState::quit){
        if (gameState == GameState::menu)
            menu();

        if(gameState == GameState::running)
            gameLoop();

        //win and lose?
    }
}

void GameApp::gameLoop(){

    while(!currentGame.isGameWon()){ //OVERALL LOOP
        std::cout << "\n======TURN START======\n";
        currentGame.rollDice();

        int input {};

        while(true){ // TURN LOOP
            std::cout << "Your dice total is: " << currentGame.getCurrentRoll() << "\n";
            currentGame.printBox();

            if(!currentGame.validChoiceExists()){   //if dice rolled are impossible to use, loses game
                currentGame.gameOver();
                gameState = GameState::menu;
                return;
            }

            std::cout << "Enter a valid door number: \n";
            std::cout << "-----------------------\n";
            input = 0;
            input = readInput();
            std::cout << "-----------------------\n";

            InputResult result = currentGame.handleInput(input);

            if(result == InputResult::InvalidMove){
                std::cout << "==========================\n";
                std::cout << "Invalid move! Try again!\n";
                std::cout << "==========================\n";
                continue;
            }

            if (result == InputResult::Success){
                currentGame.closeDoor(input);

                if(currentGame.getCurrentRoll() == 0){
                    std::cout << "All of dice total used. Ending turn.\n";
                    break;
                }

                if (!currentGame.validChoiceExists()){ // if with the rest of the dice roll you can keep closing doors, keep doing it. else, gameover
                    currentGame.gameOver();
                    gameState = GameState::menu;
                    return;
                }
            }
        }
    }
    // game is won
    std::cout << "\n\n============YOU WIN===========\n";
    std::cout << "You successfully closed all doors! Hooray! Yippie! Yay!\n";
    std::cout << "Returning to menu.\n\n";
}

int GameApp::readInput(){
    int input = -1;
    bool valid= false;
    do
    {
        std::cin >> input;
        if (std::cin.good())
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            std::cin.clear();
            //and empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input; please re-enter." << std::endl;
        }
    } while (!valid);

    return (input);
}
