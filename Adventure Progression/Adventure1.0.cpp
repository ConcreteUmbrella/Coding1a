#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0)); //seeding the random # gen.

  int health = 10;
  int block;
  int attack;
  int turns = 0;

  cout << "Welcome to 'NonDescript Adventure Game'!.\n";

  cout << "You're being attacked!.\n";
  
  int loopCount = 0;
  while(loopCount < 4 && health > 0) {
    loopCount += 1;
    turns += 1;
    block = rand() % 4;
    attack = rand () % 4;
    cout << "Their attack: "<< attack <<"\n";
    cout << "Your block: " << block <<".\n"; 
    if (block >= attack) {
      cout << "You've blocked successfully!\n";
    }
    else {
      health -= attack;
      cout << "You've been hit for " << attack << " health!\n";
      cout << "You have " << health << " remaining.\n";
    }
  }
  if (health > 0) {
    cout << "Congrats! You didn't die! Your final health was " << health <<".\n";
  }
  else {
    cout << "Oops, you died. Better luck next time!";
  }
}