#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "textgame.h"



int main()
{
    Game myGame; //Creates the game object
    while (myGame.getCurrentScene() != 0) {
        myGame.runScene();

        //Ask if they want to continue
        if (myGame.getCurrentScene() != 0) {
        std::cout << "\nPress Enter to Continue...\n\n";
        std::cin.ignore();
        std::cin.get();
        }
    }
    std::cout << "Thanks for playing!";
    return 0;
}
