#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
// functions not quite as fast as usual cout <<
// return type, name, (input) {code}
// defining a function that returns nothing,
// named "welcome" with no input perameters.
void welcome() { cout << "Hello World!\n";
  }

// overloading a function.
//this function has one input: a string variable named "message".
void welcome(string message) { 
  cout << message << "\n";
  }



//return type is int
//don't forget to include ctime and cstdlib, also to use srand in main()
//make an input parameter named 'sides' to change the max rando amount
//sides has a default value of 6, so that if we don't give an amount, sides = 6
int rollDie(int sides = 6, int min = 1) {
  return rand() % sides + min;
}

// build a function that asks for specific user input (y/n)... and loops until it gets it.
//let's make it return a boolean
bool askYN(string question = "Keep playing?") {
  while(true) {
    cout << question << "(y/n)\n";
    char input;
    cin >> input;

    if(input == 'y') {
      return true;
    }
    if (input == 'n') {
      return false;
    }
  }//end of while(true) loop
}//end of askYN function


int main() {
  srand(time(0));
  // calling the welcome() function
  welcome();
  welcome("Howdy");


  //int roll = rollDie();
  cout << "Your die roll is " << rollDie() << ".\n";


  cout << "Your die roll is " << rollDie(1000,1000) << ".\n";


  if (askYN() == true) {
    cout << "Let's play again!\n";
  }
  else {
    cout << "Thanks for playing!\n";
    return;
  }

  if(askYN("Should we go left?")) {
    cout << "Here we go to the left.\n";
  }
  else {
    cout << "Alright, it's your funeral...\n";
  }
  if(askYN("Should we turn the lights on?")) {
    cout << "The lights are turned on.\n";
  }
  else {
    cout << "The lights remain off";
  }
}