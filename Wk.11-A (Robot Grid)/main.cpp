#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class robot;

// global varaibles
string robot_names[] = {"R2",    "IG-11", "IG-88", "Mouse Droid",
                        "MSE-6", "XG-9",  "VF-GH"};

// Creating a new class
// "class" keyword, then the name of the class
class robot {

  // variables are accessible
public:
  // data members (variables)
  string name;
  int battery_level;
  int grid_x; // horizontal location
  int grid_y; // vertical location

  // member functions
  // a constructor is called when a new variable is created.
  // a constructor is always named the same as the class, with no return type.
  robot(string given_name = "Robot", int given_battery_level = 10) {
    cout << "A new robot has been created!" << endl;
    name = given_name;
    battery_level = given_battery_level;
    grid_x = (rand() % 5) - 2;
    grid_y = (rand() % 5) - 2;
  }

  void status() {
    cout << "[" << name << ": " << battery_level << "]" << endl;
    cout << "[Position (x,y): " << grid_x << "," << grid_y << "]" << endl;
  }

  // progect goal
  // give robots position on -2 to +2 grid
  // give robots the ability to move nesw

  void move() {
    // north and south grid_y +/-, east and west grid_x +/-
    // 1. pick a direction
    // 2. try to move in that direction
    // 3. if we're at the end of the map, don't move

    while (battery_level > 0) {

      int direction = rand() % 4; // 0 = n, 1 = s, 2 = e, 3 = w

      // if going north...
      if (direction == 0 && grid_y < 2) {
        grid_y++; // go north

        break;
      } else if (direction == 1 && grid_y > -2) {
        grid_y--; // go south

        break;
      } else if (direction == 2 && grid_x > -2) {
        grid_x--; // go east

        break;
      } else if (direction == 3 && grid_x < 2) {
        grid_x++; // go west

        break;
      }
      // else {
      // cout << "[Error: Direction Promblem]" << endl;
      // cout << direction << endl;
      // break;
      // }
    }

    if (battery_level > 0) {
      battery_level -= 1;
    }
  }

  void say_hello(robot robots[]) {

    for (int i = 0; i < 10; i++) {

      if (&(robots[i]) == this) {
        continue;
      }

      if (robots[i].grid_x == grid_x && robots[i].grid_y == grid_y) {
        cout << name << " says hello to " << robots[i].name << endl;
      }
    }
  }

}; // don't forget semicolon

int main() {
  srand(time(0));
  cout << "Week 11" << endl;
  // unified modeling language (UML) for documentation complex systems.

  // create a new robot variable.
  robot artoo;
  // set up artoo
  artoo.name = "R2-D2";
  artoo.battery_level = 4;

  cout << "Welcome " << artoo.name << "!" << endl;
  cout << artoo.name << "'s battery level is " << artoo.battery_level << endl;

  robot threepio("C-3PO", 5); // constructor is called here
  threepio.status();

  // create a list of names
  // create a list of robot with random names and batter_levels
  // and then we'll have them move around

  robot robots[5];

  // randomize the robots
  for (int i = 0; i < 5; i++) {
    robots[i] = robot(robot_names[rand() % 7], rand() % 6 + 5);
  }

  for (int i = 0; i < 5; i++) {
    robots[i].status();
  }

  for (int i = 0; i < 10; i++) {
    cout << "-----------------------" << endl;
    for (int j = 0; j < 5; j++) {
      robots[j].move();
      robots[j].status();
      robots[j].say_hello(robots);
    }
  }
}