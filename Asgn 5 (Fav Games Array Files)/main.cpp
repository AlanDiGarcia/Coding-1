#include <fstream>
#include <iostream>
using namespace std;

// Global Variables
string fav_games[25];
bool bulkadd_bool = false;
char input_char = 'n';
int index = 0;
int index_edit_num;
string input;

// The instructions to the program
void intro(string &input) {
  cout << endl;
  cout << "Type 'quit' to exit the program." << endl;
  cout << "Type 'add' to add games." << endl;
  cout << "Type 'show' to show games." << endl;
  cout << "Type 'edit' to edit games." << endl;
  cout << "Type 'remove' to remove games." << endl;
  cout << "Type 'save' to save into a file." << endl;
  cout << "Type 'load' to show the file." << endl;
  cout << endl;
  cout << "Enter: ";
  // get input
  cin >> input;
  cin.ignore();
}

// Error message that pops up in the intro
void intro_error() {
  cout << endl;
  cout << "Error: Command Not Recongnized" << endl;
  cout << endl;
}

// Add to array and index
void add(string fav_games[], int &index, string input) {

  cout << endl;
  cout << "What games would you like to add?" << endl;
  cout << "Enter 'quit' to stop" << endl;
  cout << endl;

  while (true) {

    getline(cin, fav_games[index]);

    if (fav_games[index] == "quit") {
      break;
    }

    index++;

    cout << endl;
  }
}

// Show the array
void show(string fav_games[], int &index) {
  cout << endl;
  cout << "Your favorite games: " << endl;

  for (int i = 0; i < index; i++) {

    cout << i + 1 << ". " << fav_games[i] << endl;
  }

  cout << endl;
}

// Edit the array
void edit(string input, string fav_games[], int &index, int &index_edit_num) {

  cout << endl;
  cout << "Which spot in the list do you wish to edit?" << endl;

  cin >> index_edit_num;
  cin.ignore();

  cout << endl;
  cout << "This is what will change: " << fav_games[index_edit_num - 1] << "."
       << endl;

  getline(cin, fav_games[index_edit_num - 1]);

  cout << endl;
}

// Remove something from the array
void remove(string fav_games[], int index_edit_num) {

  cout << endl;
  cout << "Which spot in the list do you wish to delete?" << endl;

  cin >> index_edit_num;
  cin.ignore();

  cout << endl;
  cout << "This is what was deleted: " << fav_games[index_edit_num - 1] << "."
       << endl;

  fav_games[index_edit_num - 1] = "";

  cout << endl;
}

// Load the file
void load() {
  string line;

  cout << endl;

  // create the file variable
  ifstream file("save.txt");

  // check to see if the file is open
  if (file.is_open()) {

    while (getline(file, line)) {

      cout << line << endl;
    }
  } else {

    cout << "File could not be loaded" << endl;
  }

  file.close();

  cout << endl;
}

// Save array onto the file
void save(int &index, string fav_games[]) {

  string input;

  cout << endl;

  // create the file variable
  ofstream file;

  file.open("save.txt");

  for (int i = 0; i < index; i++) {

    // add input to file, then start a new line.
    file << fav_games[i] << endl;
  }

  file.close();

  cout << endl;
}

int main() {

  while (true) {
    intro(input);

    // test the input
    if (input == "quit") {
      cout << "Shutting Down";
      break; // or return 0
    }

    else if (input == "add") {
      add(fav_games, index, input);
    }

    else if (input == "show") {
      show(fav_games, index);
    }

    else if (input == "edit") {
      edit(input, fav_games, index, index_edit_num);
    }

    else if (input == "remove") {
      remove(fav_games, index_edit_num);
    }

    else if (input == "load") {
      load();
    }

    else if (input == "save") {
      save(index, fav_games);
    }

    else {
      intro_error();
    }
  }
}