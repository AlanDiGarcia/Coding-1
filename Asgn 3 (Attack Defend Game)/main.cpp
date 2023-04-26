#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Global Variables
int turns = 0;
int health = 25;
int health_max = 50;
int enemy_health = 0;
int enemy_health_max = 0;
int dice = 0;
int block = 0;
int attack = 0;
int enemy_attack = 0;
bool enemy_attack_rest = false;
int enemies = 0;
int loot = 0;
int health_potion_price = 5;
int health_potion_gain = 15;
int protection_potion_price = 7;
int protection_potion_gain = 1;
bool protection_potion = false;
int damage_potion_price = 8;
int damage_potion_gain = 1;
bool damage_potion = false;
int shop_chance;
bool continuing = true;
char play = 'p';
char letter = 'y';
string region = "easor";

void story_begins() {
  // Rules of the game
  cout << "Welcome to a totally original Roguelike!" << endl;
  cout << endl;
  cout << "The rules of the Game:" << endl;
  cout << "1. You will have " << health << " health." << endl;
  cout << "2. An enemy will attack you each turn." << endl;
  cout << "3. You can either block, flee, or attack." << endl;
  cout << "4. If you kill the enemy, you gain loot." << endl;
  cout << "5. If you block, you will receive less damage." << endl;
  cout << "6. You can continue your adventure or return home." << endl;
  cout << "7. If you lose all health, you die." << endl;
  cout << endl;
}

void play_question() {
  // Prompting the play question
  cout << "Do you wish to play? (y/n): ";
  cin >> play;
  cout << endl;
}

void introduction() {
  cout << endl;
  cout << "You feel the itch to start an adventure." << endl;
  cout << "Which region do you pick? (easor/middia/harnu): ";
  cin >> region;

  if (region == "easor" || region == "Easor") {
    cout << endl;
    cout << "The lands of Easor, known for there feeble Slimes." << endl;
    enemy_health = 3;
    enemy_health_max = 3;

  } else if (region == "middia" || region == "Middia") {
    cout << endl;
    cout << "The lands of Middia, known for there armored Goblins." << endl;
    enemy_health = 5;
    enemy_health_max = 5;

  } else if (region == "harnu" || region == "Harnu") {
    cout << endl;
    cout << "The lands of Harnu, known for there warrior Orcs." << endl;
    enemy_health = 8;
    enemy_health_max = 8;

  } else {
    cout << endl;
    cout << "You made a mistake, instead arriving to Hellsor, land of the "
            "Demons."
         << endl;
    enemy_health = 12;
    enemy_health_max = 12;
  }

  cout << endl;
}

int roll_die() {
  int dice = rand() % 6 + 1;
  return dice;
}

bool continue_adventure() {
  cout << endl;
  if (continuing == true) {
    do {
      cout << "Continue Adventure? (y/n): ";
      cin >> letter;
      if (letter == 'y') {
        cout << endl;
        return true;
      } else if (letter == 'n') {
        return false;
      } else {
        cout << "Error: Unrecognized Letter" << endl;
      }
    } while (true);
  }
  return false;
}

void ending() {

  cout << endl;
  if (health <= 0) {

    // Health reaches 0, lose game
    cout << "YOU DIED: you have lost all of your health!" << endl;
    cout << endl;
    cout << "you defeated " << enemies << " enemies" << endl;
    cout << "you lost " << loot << " loot" << endl;
    cout << "you played for " << turns << " turns" << endl;
    cout << endl;
    continuing = false;
  }

  if (health > 0 && continuing == false) {

    // Health above 0, win game
    cout << "You have returned from your adventure" << endl;
    cout << endl;
    cout << health << " health left" << endl;
    cout << "you defeated " << enemies << " enemies" << endl;
    cout << "you kept " << loot << " loot" << endl;
    cout << "you played for " << turns << " turns" << endl;
    cout << endl;
    continuing = false;
  }
}

void looting() {
  cout << endl;
  cout << "Enemy dropped loot!" << endl;
  loot = loot + roll_die();
  cout << "You have " << loot << " loot" << endl;
}

void shop_options() {

  cout << "You entered the shop, full with colored potions" << endl;
  // cout << "You reason that you can spend loot for potions" << endl;
  // cout << endl;

  cout << "Shopkeeper invites you to buy one of his potions" << endl;
  cout << endl;

  // cout << "'Do you wish to buy a potion?'" << endl;
  // cout << "'I sell many a potion to adventurers'" << endl;
  // cout << endl;

  // cout << "'I am willing to sell some of my Health potions, for a price'"
  //      << endl;
  // cout << endl;

  do {
    cout << "Buy a Protection, Health, Damage potion? (p/h/d) or leave? (n): ";
    cin >> letter;

    if (letter == 'h') {

      // losing money in exchange for health
      loot = loot - health_potion_price;
      health = health + health_potion_gain;

      if (health > health_max) {
        health = health_max;
      }

      cout << "You have " << loot << " loot" << endl;
      cout << "You have " << health << " health" << endl;
      cout << endl;

      cout << "You thank the shopkeeper and continue on your journey" << endl;
      cout << endl;
      break;

    } else if (letter == 'p' && protection_potion == false &&
               loot >= protection_potion_price) {

      // losing money for +1 in Block
      loot = loot - protection_potion_price;
      protection_potion = true;

      cout << "You thank the shopkeeper and continue on your journey" << endl;
      cout << endl;
      break;

    } else if (letter == 'd' && damage_potion == false &&
               loot >= damage_potion_price) {

      // losing money for +1 in Attack
      loot = loot - damage_potion_price;
      damage_potion = true;

      cout << "You thank the shopkeeper and continue on your journey" << endl;
      cout << endl;
      break;

    } else if (letter == 'n') {

      // cout << "'I understand, well hopefully I see you again'" << endl;
      // cout << endl;

      cout << "You leave the potion shop, and continue on your journey" << endl;
      cout << endl;
      break;

    } else {

      cout << "You stand around thinking about the options" << endl;

      if (letter == 'p') {

        cout << "You already have protection enhancements activated" << endl;

      } else if (letter == 'd') {

        cout << "You already have damage enhancements activated" << endl;
      }
      cout << endl;
    }
  } while (true);
}

void shop() {

  // Prompt to enter the shop
  cout << "You find a tiny shop out in the distance" << endl;

  do {

    cout << "Do you wish to enter? (y/n): ";
    cin >> letter;
    cout << endl;

    if (letter == 'y') {

      cout << "You decide to enter the strange shop" << endl;
      cout << endl;
      shop_options();

      break;

    } else if (letter == 'n') {

      cout << "You decide to continue on your journey" << endl;
      cout << endl;

      break;

    } else {

      cout << "You hesitated to enter the shop" << endl;
      cout << endl;
    }

  } while (true);
}

void adventure() {

  do {

    // turns increasing
    turns++;

    cout << "Turn " << turns << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    if (enemy_attack == 4 || enemy_attack == 5 || enemy_attack == 6) {
      enemy_attack_rest = true;
      cout << "Enemy rests after doing a heavy attack." << endl;
      enemy_attack = 0;
    } else if (enemy_attack_rest == true) {
      enemy_attack_rest = false;
    }

    if (enemy_attack_rest == false) {
      // Enemy Attacking
      enemy_attack = roll_die();
      cout << "Enemy attacks with " << enemy_attack << " damage." << endl;
    }

    do {

      // Prompting for Block, Flee, or Attack
      cout << "Do you wish to Block, Flee, or Attack? (b/f/a): ";
      cin >> letter;
      cout << endl;

      if (letter == 'b') {
        // Player Blocking

        block = roll_die();

        if (protection_potion == true) {
          block = block + protection_potion_gain;
        }

        cout << "You block with " << block << " defense." << endl;

        // Attack Block logic start
        if (enemy_attack > block) {

          // Attack beats block
          health = health - (enemy_attack - block);

          cout << "Partial Block: you lose " << enemy_attack - block
               << " health." << endl;
          cout << health << " health left" << endl;
          cout << endl;

          break;

        } else if (enemy_attack <= block) {

          // Block beats attack
          cout << "Full Block: you lose no health." << endl;
          cout << health << " health left" << endl;
          cout << endl;

          break;
        }

      } else if (letter == 'a') {

        // Player Attacking

        attack = roll_die();

        if (damage_potion == true) {
          attack = attack + damage_potion_gain;
        }

        health = health - enemy_attack;
        enemy_health = enemy_health - attack;

        cout << "You attack with " << attack << " damage." << endl;
        cout << health << " health left" << endl;
        cout << "Enemy has " << enemy_health << " health left" << endl;
        cout << endl;

        break;

      } else if (letter == 'f') {

        cout << "You flee before getting hit" << endl;

        continuing = false;

        break;

      } else {

        cout << "Error: Wrong Letter" << endl;
      }
    } while (true);

    if (health <= 0) {
      continuing = false;
    }

    if (continuing == false) {
      break;
    }

  } while (enemy_health > 0);

  if (continuing == true) {

    shop_chance = roll_die();

    // defeated enemy count increasing
    enemies++;

    enemy_health = enemy_health_max;

    looting();

    if (loot >= health_potion_price) {

      if (shop_chance == 3 || shop_chance == 6) {

        turns++;

        cout << "Turn " << turns << endl;
        cout << "------------------------------------------" << endl;
        cout << endl;

        shop();
      }
    }
  }

  continuing = continue_adventure();
}

int main() {

  // Seeding the rand() fuction
  srand(time(0));
  story_begins();
  play_question();

  if (play == 'n') {
    // Player No Play

    cout << "Shutting Game Down" << endl;

  } else if (play == 'y') {
    // Player Plays

    introduction();

    do {

      adventure();

    } while (continuing == true);

  } else {
    // Player picks wrong Char

    cout << "Error: Wrong Character!" << endl;
  }

  ending();
}