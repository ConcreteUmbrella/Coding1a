#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
int attack;
int block;
int health = 10;
bool gameQuit = false;
int totalTreasure = 0;

void story() {
  cout << "You awaken in a field.\n";
  cout << "With nothing but grassland for miles, you have no clue where you "
          "are.\n";
  cout << "You have " << health << " health.\n";
}

bool askYesNo(string question = "Would you like to go adventuring?") {
  while (true) {
    cout << question << "(y/n)\n";
    char input;
    cin >> input;

    if (input == 'y') {
      return true;
    }
    if (input == 'n') {
      return false;
    }
  } // end of while(true) loop
} // end of askYN function

int rollDie(int sides = 6, int min = 1) { return rand() % sides + min; }

void adventure() {
  block = rollDie();
  attack = rollDie();

  if (block >= attack) {
    totalTreasure = totalTreasure + rollDie();
    cout
        << "You were attacked on your journey, but you blocked successfully.\n";
    cout << "Your remaining health is " << health << ".\n";
    cout << "Your total treasure is now " << totalTreasure << ".\n";

  } else {
    health -= attack;
    if (health <= 0) {
      health = 0;
    }
    cout << "You were attacked and took damage. Get better.\n";
    cout << "Your remaining health is " << health << ".\n";
  }

  if (health > 0) {
    if (askYesNo("Would you like to keep adventuring?") == true) {
    } else {
      cout << "Your final health is " << health << ".\n";
      cout << "Your total treasure is " << totalTreasure << ".\n";
      cout << "The game is over. You survived!\n";
      gameQuit = true;
      return;
    }
  } else {
    cout << "You've Died. End of Game.\n";
    return;
  }
}

int main() {
  srand(time(0));
  int block;
  int attack;
  story();
  if (askYesNo() == true) {
    cout << "Off we go!\n";
  } else {
    cout << "You wait in the field until you succumb to your hunger and "
            "perish.\n";
    return;
  }
  while (health > 0 && gameQuit == false) {
    adventure();
  } // end of while loop

} // end of main