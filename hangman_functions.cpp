#include <iostream>
#include <vector>
#include "hangman_functions.h"
using namespace std;
//define functions

void greet() {

cout << "========================\n";
cout << "Hangman: The Hangining\n";
cout << "========================\n";
cout << "Instructions: Save the homie by guessing the correct letters to solve the keyword!\n";
}

void display_misses(int misses) {

if(misses == 0) {
    cout << "+---+ \n";
    cout << "|   | \n";
    cout << "    | \n";
    cout << "    | \n";
    cout << "    | \n";
    cout << "    | \n";
    cout<<" ========= \n";
}
else if(misses == 1) {
    cout << " +---+ \n";
    cout << " |   | \n";
    cout << " O   | \n";
    cout << "     | \n";
    cout << "     | \n";
    cout << "     | \n";
    cout<<" ========= \n";
}
else if(misses == 2) {
    cout << " +---+ \n";
    cout << " |   | \n";
    cout << " O   | \n";
    cout << " |   | \n";
    cout << "     | \n";
    cout << "     | \n";
    cout<<" ========= \n";
}
else if(misses == 3) {
    cout << " +---+ \n";
    cout << " |   | \n";
    cout << " O   | \n";
    cout << "/|   | \n";
    cout << "     | \n";
    cout << "     | \n";
    cout<<" ========= \n";
}
else if(misses == 4) {
    cout << " +---+ \n";
    cout << " |   | \n";
    cout << " O   | \n";
    cout << "/|\  | \n";
    cout << "     | \n";
    cout << "     | \n";
    cout<<" ========= \n";
}
else if(misses == 5) {
    cout << " +---+ \n";
    cout << " |   | \n";
    cout << " O   | \n";
    cout << "/|\\  | \n";
    cout << "/    | \n";
    cout << "     | \n";
    cout<<" ========= \n";
}
else if(misses == 6) {
    cout << " +---+ \n";
    cout << " |   | \n";
    cout << " O   | \n";
    cout << "/|\\  | \n";
    cout << "/ \\  | \n";
    cout << "     | \n";
    cout<<" ========= \n";
}
}

void display_status(vector<char> incorrect, string answer) {
cout << "Incorrect Guesses \n";

    for(int i = 0; i<incorrect.size(); i++) {
        cout << incorrect[i]<< " ";
    }
    cout << "\nKeyword: \n";

    for(int i = 0; i<answer.length(); i++) {
        cout << answer[i]<< " ";
    }
}

void end_game(string answer, string codeword) {

if(answer == codeword) {
    cout<<"Yeah, buddy! The homie has been saved!\n";
    cout<<"Praise the Lord!\n";
}
else {
    cout<<"Oh, crud! You didn't save the homie!\n";
}
}
