#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(0));

  string favGames[100];   //creating an array of the type string
                          //named 'favGames with a size of 100
  int index = 0;
  while(true) {
    cout << "What would you like to do?\n";
    cout << "Type 'quit' to quit.\n";
    cout << "Type 'add' to add a game.\n";
    cout << "Type 'show' to show the array of games.\n";
    cout << "Type 'editlast' to change the last game input.\n";
    cout << "Type 'edit' to change any game input.\n";
    cout << "Type 'bulkadd' to quickly add games.\n";

    string input;
    cin >> input;

    if(input == "quit") {
      cout << "Thanks for playing!\n";
      break;
    }
    if(input == "add") {
      cout << "What game would you like to add?\n";
      cin >> input;
      favGames[index] = input;
      index++;                    //make the index point at the next spot in the array.
      
    }
    if(input == "show") {
      cout << "Here are your favorite games:\n";
      for(int i = 0; i < index; i++) {
        cout << favGames[i] << "\n";
      }
    }
    if(input == "editlast") {
      cout << "Please re-enter last game name.\n";
      cin >> input;
      favGames[index - 1] = input;
    }
    if(input == "edit") {
      cout << "What game would you like to edit?\n";
      cin >> input;
      for(int i = 0; i < index; i++) {
        if(favGames[i] == input) {
          cout << "Found it!\n";
          cout << "What would you like to change this to?\n";
          cin >> input;
          favGames[i] = input;
         }
        
      }
    }
    if(input == "bulkadd") {
      cout << "Please add your games. Press enter after each entry.\n";
      cout << "When you're done, type 'quit'.\n";
      while(true) {
        cin >> input;
        favGames[index] = input;
        index++;
        if(input == "quit") {
          cout << "Entries catalogued.\n";
          index -= 1;        //Kept saving 'quit' as an entry. This removes the last entry
          break;            // which was always 'quit'
        }
        
      }
    }
  }   //end of favGames while loop

}