#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {

  // All variables
  int turns = 0;
  int health = 10;
  int attack = 0;
  int block = 0;
  string play = "p";
  string letter = "y";

  // Seeding the rand() fuction
  srand(time(0));

  // Introduction to the game
  cout << "Welcome to a totally original Roguelike!\n\n";

  cout << "The rules of the Game:\n";
  cout << "1. You will have 10 health.\n";
  cout << "2. An enemy will attack you each turn.\n";
  cout << "3. You will block each turn.\n";
  cout << "4. If you survive the 4 turns, you win!\n" << endl;

  // Prompting the play question
  cout << "Do you wish to play? (y/n): ";
  cin >> play;
  cout << endl;

  // Play question logic start
  if (play == "n") {

    // Player picks no play
    cout << "Why not? :( " << endl;

  } else if (play == "y") {

    // Player picks to play

    // Actions of the game (Atk,Blk)
    do {

      // Attacking
      attack = rand() % 5;
      cout << "Enemy attacks with " << attack << " damage." << endl;

      // Prompting for block
      cout << "Type anything to Block: " << endl;
      cin >> letter;
      cout << endl;

      // Blocking
      block = rand() % 5;
      cout << "You block with " << block << " defense." << endl;

      // Attack Block logic start
      if (attack > block) {

        // Attack beats block
        health -= attack;
        cout << "Unsuccessful Block: you lose " << attack << " health." << endl;
        cout << health << " health left" << endl << endl;

      } else if (attack <= block) {

        // Block beats attack
        cout << "Successful Block: you lose no health." << endl << endl;
      }

      if (health <= 0) {

        // Health reaches 0, lose game
        cout << "YOU DIED: you have lost all of your health!" << endl;
      }

      // turns increasing
      turns++;

    } while (health > 0 && turns < 4);

    if (health > 0) {

      // Health above 0, win game
      cout << "Congradulations: you have won the game!" << endl;
      cout << health << " health left" << endl << endl;
    }

  } else {

    // Player picks wrong Char
    cout << "Error: wrong character!" << endl;
  }
}