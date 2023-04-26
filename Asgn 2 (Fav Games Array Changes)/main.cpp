#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  string fav_games[100];
  bool bulkadd_bool = false;
  char input_char = 'n';
  int index = 0;

  while (true) {
    cout << "What would you like to do?" << endl;
    cout << "Type 'quit' to exit the program." << endl;
    cout << "Type 'add' to add a game, no spaces." << endl;
    cout << "Type 'bulkadd' to add multiple games simultaneously" << endl;
    cout << "Type 'show' to show your favorite games." << endl;
    cout << "Type 'edit' to edit a spot in the list." << endl;
    cout << "Type 'editrecent' to edit the most recently added item." << endl;
    cout << "Type 'find' to find a game in the list." << endl;
    cout << "Type 'delete' to delete a game from the list." << endl;

    // get input
    int index_edit_num;
    string input;
    cin >> input;

    // test the input
    if (input == "quit") {
      cout << "Shutting Down";
      break; // or return 0
    }

    else if (input == "add") {
      cout << endl;
      cout << "What game would you like to add?" << endl;
      cin >> input;
      fav_games[index] = input;
      index++;
      cout << endl;
    }

    else if (input == "show") {
      cout << endl;
      cout << "Your favorite games: " << endl;

      for (int i = 0; i < index; i++) {
        cout << i + 1 << ". " << fav_games[i] << endl;
      }

      cout << endl;
    }

    else if (input == "edit") {
      cout << endl;
      cout << "Which spot in the list do you wish to edit?" << endl;
      cin >> index_edit_num;
      cout << endl;

      cout << "This is what will change: " << fav_games[index_edit_num - 1]
           << "." << endl;
      cin >> input;
      fav_games[index_edit_num - 1] = input;
      cout << endl;
    }

    else if (input == "editrecent") {
      cout << endl;
      cout << "This is what will change: " << fav_games[index - 1] << "."
           << endl;
      cin >> input;
      fav_games[index - 1] = input;
      cout << endl;
    }

    else if (input == "find") {
      cout << endl;
      cout << "What game do you want to find?" << endl;
      cin >> input;

      for (int i = 0; i < index; i++) {

        if (input == fav_games[i]) {
          cout << endl;
          cout << "Found!" << endl;
          cout << "This inhabits the number " << i + 1 << " spot in the index."
               << endl;
          cout << endl;
          cout << "What do you wish to change " << fav_games[i] << " into?"
               << endl;
          cin >> input;
          fav_games[i] = input;
          break;
        }

        if (i + 1 == index) {
          cout << "I have looked through the list and did not find: " << input
               << endl;
        }
      }

      cout << endl;
    }

    else if (input == "bulkadd") {
      cout << endl;
      bulkadd_bool = true;
      cout << "Bulkadd, adds games continously." << endl;
      cout << "Type 'stop' to end the bulkadd." << endl;

      do {
        cout << endl;
        cout << "Add a game: " << endl;
        cin >> input;

        if (input == "stop") {
          bulkadd_bool = false;
          break;
        }

        fav_games[index] = input;
        index++;

      } while (bulkadd_bool == true);

      cout << endl;
    }

    else if (input == "delete") {
      cout << endl;
      cout << "Which spot in the list do you wish to delete?" << endl;
      cin >> index_edit_num;
      cout << endl;

      cout << "This is what was deleted: " << fav_games[index_edit_num - 1]
           << "." << endl;
      fav_games[index_edit_num - 1] = "";
      cout << endl;
    }

    else {
      cout << endl;
      cout << "Error: Command Not Recongnized" << endl;
      cout << endl;
    }
  }
}