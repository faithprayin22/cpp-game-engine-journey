#ifndef TEXTGAME_H
#define TEXTGAME_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//declare functions
void runScene();
void emptyRoom();

//Class Game (inventory)
class Game
{
    private: // It's private so only this class can access these variables
        std::vector<std::string> inventory; // Your backpack of items -- this is a list (grows and shrinks with added/subtracted items)
        int currentScene;                // Which part of the game your are in
        int previousScene;
        std::vector<int> visitedRooms;

    public:
        void runScene();
        void emptyRoom();
        void clutterRoom();
        void keyRoom();
        void doorRoom();
        int getCurrentScene() const { return currentScene; }
        void typewriterEffect(const std::string& text, int delayMs = 15);
        bool hasVisitedRoom(int roomNumber);
        void markRoomAsVisited(int roomNumber);
        Game(): currentScene(1), previousScene(1) {}

        void addItem(const std::string & item) {
        inventory.push_back(item);
        std::cout << "\nYou found: " << item << std::endl;
        }

    bool hasItem(const std::string & item) {
        return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
    }

    void showInventory() {
    std::cout << "Inventory: ";
    if (inventory.empty()) {
        std::cout << "Empty";
    } else {
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << inventory[i];
            if (i < inventory.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
    }

};

#endif // TEXTGAME_H
