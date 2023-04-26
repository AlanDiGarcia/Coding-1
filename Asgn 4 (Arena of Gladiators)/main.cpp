#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int number_of_glad = 5;
int max_num_of_dead = number_of_glad - 1;
int number_of_dead = 0;
bool champion_found = false;

string gladiator_names[] = {"Oprenus",   "Livonus",   "Markus",   "Romanus",
                            "Culvanus",  "Aegidus",   "Adrianus", "Veronus",
                            "Marcellus", "Coperenus", "Vesuvius", "Beronicus"};

class gladiator {

public:
  string name;
  bool dead;
  int health;
  int grid_x; // horizontal location
  int grid_y; // vertical location

  gladiator() {
    cout << "A new Gladiator has entered the arena!" << endl;
    name = gladiator_names[rand() % 12];
    health = rand() % 6 + 5;
    grid_x = (rand() % 7) - 3;
    grid_y = (rand() % 5) - 2;
    dead = false;
  }

  void status() {

    if (dead == false) {

      cout << endl;
      cout << "[" << name << ": " << health << "]" << endl;
      cout << "[Position (x,y): (" << grid_x << "," << grid_y << ")]" << endl;
    }
  }

  void move() {

    if (dead == false) {

      while (true) {

        int direction = rand() % 4; // 0 = n, 1 = s, 2 = e, 3 = w

        // if going north...
        if (direction == 0 && grid_y < 2) {
          grid_y++; // go north
          break;

        } else if (direction == 1 && grid_y > -2) {
          grid_y--; // go south
          break;

        } else if (direction == 2 && grid_x > -3) {
          grid_x--; // go east
          break;

        } else if (direction == 3 && grid_x < 3) {
          grid_x++; // go west
          break;
        }
      }
    }
  }

  void fight(gladiator gladiators[]) {

    if (dead == false) {

      for (int i = 0; i < 10; i++) {

        if (&(gladiators[i]) == this) {

          continue;
        }

        if (gladiators[i].grid_x == grid_x && gladiators[i].grid_y == grid_y) {

          if (gladiators[i].dead == false) {

            cout << name << " fights " << gladiators[i].name << endl;

          } else {

            cout << name << " fights " << gladiators[i].name << "'s Ghost"
                 << endl;
          }

          int winner = rand() % 2;

          if (winner == 1 && gladiators[i].dead == false) {

            health -= 1;
            cout << gladiators[i].name << " beat " << name << endl;

          } else if (winner == 0 && gladiators[i].dead == false) {

            gladiators[i].health -= 1;
            cout << name << " beat " << gladiators[i].name << endl;

          } else if (winner == 1 && gladiators[i].dead == true) {

            health -= 1;
            cout << gladiators[i].name << "'s Ghost beat " << name << endl;

          } else if (winner == 0 && gladiators[i].dead == true) {

            gladiators[i].health -= 1;
            cout << name << " beat " << gladiators[i].name << "'s Ghost"
                 << endl;
          }
        }
      }
    }
  }
  void death() {

    if (health <= 0 && dead == false) {

      cout << name << " has died" << endl;
      dead = true;
      number_of_dead++;
    }
  }
  void champion() {

    if (number_of_dead == max_num_of_dead && dead == false) {

      cout << name << " is the Champion of the Arena!" << endl;
      champion_found = true;
    }
  }
};

int main() {

  srand(time(0));
  gladiator gladiators[number_of_glad];

  while (champion_found == false) {

    for (int i = 0; i < number_of_glad; i++) {

      gladiators[i].status();
      gladiators[i].move();
      gladiators[i].fight(gladiators);
      gladiators[i].death();
      gladiators[i].champion();
    }
  }
}