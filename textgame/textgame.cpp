#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include "textgame.h"

void Game::runScene() {
    switch(currentScene) {
    case 1:
        emptyRoom();
        break;
    case 2:
        clutterRoom();
        break;
    case 3:
        keyRoom();
        break;
    case 4:
        doorRoom();
        break;
    }
}
void Game::typewriterEffect(const std::string & text, int delayMs) {
    for (size_t i = 0; i < text.length(); ++i) {
        std::cout << text[i] << std::flush; // print  character and flush output

        // check for key press
        if (_kbhit()) { // windows function
            char key = _getch(); //get key press
            if (key == ' ' || key == '\r' || key == '\n') { //space, enter, or newline
                //print the rest of the text instantly
                std::cout << text.substr(i + 1) << std::flush;
                break; // exit the loop
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}
bool Game::hasVisitedRoom(int roomNumber) {
    return std::find(visitedRooms.begin(), visitedRooms.end(), roomNumber) != visitedRooms.end();
    }
void Game::markRoomAsVisited(int roomNumber) {
    if (!hasVisitedRoom(roomNumber)) {
        visitedRooms.push_back(roomNumber);
    }
}

void Game::emptyRoom() {

    if (!hasVisitedRoom(1)) {
        typewriterEffect("You awake in an empty room, a small window illuminates a cracked wooden door.\n");
        typewriterEffect("Your eyes adjust to the darkened environment quickly, the room is vacant, a torn rag\n");
        typewriterEffect("comforts you as a blanket.\n\n");
        markRoomAsVisited(1); //marked room as visited
    } else {
        typewriterEffect("You're back in the empty room.\n\n");
        }

    std::string playerChoice;
    while (true) {
        typewriterEffect("Do you go through the door? (Yes/No)\n\n");
        std::cin >> playerChoice;

        if (playerChoice == "Yes" || playerChoice == "yes") {
            typewriterEffect("\nYou enter through the cracked doorway.\n");
            currentScene = 2; //Go to the cluttered room (scene 2)
            break;
        }
        else if (playerChoice == "No" || playerChoice == "no") {
            typewriterEffect("\nYou choose to remain put. \n");
            break; // exit loop, remain at scene 1
        }
        else {
            typewriterEffect("You have to choose 'Yes' or 'No'.\n");
        }
    }
}
void Game::clutterRoom() {

    std::string nextRoom;
    std::string playerChoice;
    std::string secondaryChoice;
    if (!hasVisitedRoom(2)) {
    typewriterEffect("You entered into a room filled with busted boards and broken tables.\n");
    typewriterEffect("You look around and you see two doors, one on either side of you.\n");
    markRoomAsVisited(2);
    } else {
        typewriterEffect("You're back in the cluttered room.\n\n");
    }

    while (true) {
        typewriterEffect("Do you enter through the door to your left or to your right? (Left/Right)\n\n");
        std::cin >> nextRoom;

        if (nextRoom == "Right" || nextRoom == "right") {
            typewriterEffect("\nYou stumble over to the door on your right, the door knob breaks off\n");
            typewriterEffect("years old rust. The door creaks open, breaking cobwebs as it swings open.\n\n");
            previousScene = currentScene;
            currentScene = 3;
            break;
        } else if (nextRoom == "Left" || nextRoom == "left") {
        typewriterEffect("\nYou walk across broken boards and table legs, minding each step.\n");
        typewriterEffect("You nearly trip onto the door from a hidden board, possibly from a broken\n");
        typewriterEffect("pallet of some sort. The door crashes open and you barge into the next room.\n\n");
        previousScene = currentScene;
        currentScene = 4;
        break;
        }
        else if (nextRoom == "Back" || nextRoom == "back") {
            typewriterEffect("\nDo you wish to turn around and head back to the empty room? (Yes/No)\n\n");
            std::cin >> secondaryChoice;
        } if (secondaryChoice == "Yes" || secondaryChoice == "yes") {
            currentScene = 1;
            break;
            } else if (secondaryChoice == "No" || secondaryChoice == "no") {
                typewriterEffect("\nYou remain in the cluttered room.\n\n");
        }
    }
}
void Game::keyRoom() {

    std::string nextRoom;
    std::string playerChoice;
    if (!hasVisitedRoom(3)) {
    typewriterEffect("You enter a dusty, dilapidated room. A small table\n");
    typewriterEffect("surrounded by rubble encompasses a corner covered in cobwebs.\n");
    typewriterEffect("Inspecting the table you find an old rusty key.\n\n");
    markRoomAsVisited(3);
    } else {
        typewriterEffect("You're back in the room with the key.\n\n");
    }
    if (!hasItem("rusty key")) { // only ask if they don't have it
        std::string keyPickUp;
        while(true) {
            typewriterEffect("Do you pick it up? (Yes/No)\n\n");
            std::cin >> keyPickUp;

            if (keyPickUp == "Yes" || keyPickUp == "yes") {
                addItem("rusty key"); // adds 'rusty key' to inventory
                break;
            } else if (keyPickUp == "No" || keyPickUp == "no") {
            typewriterEffect("\nYou did not pick up the key.\n\n");
            break;
            }
        }
    } else {
        typewriterEffect("The table is empty - you already have the rusty key.");
        }

    while (true) {

        typewriterEffect("\nDo you wish to head back?\n\n");
        std::cin >> playerChoice;
        if (playerChoice == "Yes" || playerChoice == "yes") {
            typewriterEffect("\nYou turned around, heading back into the cluttered room.\n\n");
            currentScene = 2;
            break;
        } else if (playerChoice == "No" || playerChoice == "no") {
        typewriterEffect("\nYou decided to remain put.\n\n");
        }
        else {
            typewriterEffect("\nYou must choose to stay or to leave. (Yes/No)\n\n");
        }
    }
}
void Game::doorRoom() {
    std::string playerChoice;

    if (!hasVisitedRoom(4)) {
    typewriterEffect("You enter into a room with only a door. You walk up\n");
    typewriterEffect("to the door, but there is a metal padlock locked around\n");
    typewriterEffect("door handle. You pull and tug but it does not break free.\n\n");
    markRoomAsVisited(4);
    } else {
        typewriterEffect("You're back in the room with the door.\n\n");
    }

    if (hasItem("rusty key")) {
        typewriterEffect("Wait! You remembered about the rusty key in your pocket.\n\n");
        typewriterEffect("You pull it out and examine it.\n");
        typewriterEffect("Do you want to use the key?\n\n");

        std::string useKey;
        std::cin >> useKey;

        if (useKey == "Yes" || useKey == "yes") {
            typewriterEffect("\nYou insert the rusty key into the padlock.\n");
            typewriterEffect("The key snaps in the socket as the padlock \n");
            typewriterEffect("clangs to the ground. The door opens slowly.\n");
            typewriterEffect("You see stairs leading up to another level.\n\n");
            typewriterEffect("Congrats! Thank you for playing this short demo!");
            currentScene = 0; // set scene to zero, ending the game
            return; // Exit the function
        }
        else if (useKey == "No" || useKey == "no") {
            typewriterEffect("\nYou put the key back in your pocket.\n\n");
        }
        else {
        typewriterEffect("\nIt looks like there must be a key somewhere.\n\n");
        }
    }
    typewriterEffect("Option: (Back)\n");
    std::cin >> playerChoice;
    if (playerChoice == "Back" || playerChoice == "back") {
        typewriterEffect("\nYou turned around back to the cluttered room.\n\n");
        currentScene = previousScene;
    } else {
        typewriterEffect("\nYou can only go back.\n\n");
    }
}
