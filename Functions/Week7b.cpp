/*
return type
parameters
passing by value vs reference
calling a function
defining a function
overloading functions
*/

#include <iostream>
#include <string>            // for string variables (optional in repl.it)
#include <ctime>
#include <cstdlib>
using namespace std;

// global variables exist in every function, 
// because they were defined outside of any function.

// make an array of string variables with a size of 10.
string inventory[10];
int nextEmptySpot = 0;

// add function
void add() {
    cout << "what did you just pick up?\n";
    string input;
    cin >> input;

    inventory[nextEmptySpot++] = input;
}


// show function "here are the items in your inventory:"
void show() {
  cout << "here are the items in your inventory:\n";
    for(int i = 0; i < nextEmptySpot; i++) {
        cout << inventory[i] << "\n";
    }
}


// edit function
    // "what item would you like to replace?"
        // get input
        // look for input with for loop
            // if found, "what do you want to replace it with?"
                // get input
                // assign input to that spot in the array.
                // return out of function.
            // else "couldn't find that, try again?
                // if yes, start function over
                // if no, return out of function.
void edit() {
    while(true) {
        cout << "what item would you like to replace?\n";
        string input;
        cin >> input;
    
        for(int i = 0; i < nextEmptySpot; i++) {
            if(inventory[i] == input) {
                cout << "what do you want to replace " << inventory[i] << " with?\n";
                cin >> input;
    
                inventory[i] = "input";
                return;
            }
    
            // how do we know if we didn't find it?
            if(i + 1 == nextEmptySpot) {
                cout << "I couldn't find it, would you like to try again? (y/n)\n";
                char input;
                cin >> input;
    
                if(input != 'y') {
                    return;        // quit the function, unless they type 'y'.
                }
            }
        } // end of for loop
    } // end of while(true)
}

void show(string array[]) {
    for(int i = 0; i < 3; i++) {
        cout << array[i] << "\n";
    }
}

void add(string array[]) {
    cout << "adding 4th game...\n";
    array[3] = "Kirby";
}


// this is a function
int main() {
    srand(time(0));

    // string favGames[] = {"Mario", "Zelda", "Half-Life"};

    add();
    add();
    add();
    show();
    edit();
    
    // show(favGames);
    // add(favGames);
    // show(favGames);

    

    return 0;        // end of the program.
}