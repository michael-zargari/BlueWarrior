#pragma once

//window settings
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 800;

//MainMenu data
const int NUM_OF_OPTIONS = 4;

//characters size
const int CHAR_SIZE = 90;


//enum classes
enum class Characters {Warrior, FlyingEye, Goblin, Mushroom, Skeleton};
enum class Action { Attack, Death, Idle, Move, TakeHit, Jump, Falling/*,Landing*/,  SpellCast, Crouch, Shield  };


/* notes for me
* created gravity, need to work on collision detection.
* after that need to work on jump and fall methods/
* then on the attack.
* 
* after all this on enemys and game logic.
*/
