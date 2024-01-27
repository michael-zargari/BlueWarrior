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
* start to work on collisions by doing those action:
* - by creating the class StaticObject that for now fill act as a tile - after we need to change that.
* - created member of tile in play state.
* - in both moving and static object classes created the method getGlobalBonds to get the floatRect of the object/
* - created collision table
* next time: to improve the collision.
* 
* after that need to work on jump and fall methods/
* then on the attack.
* 
* after all this on enemys and game logic.
* 
* NOTICE: find some time to organize all the objects methods - NOW THIS IS NOT DESIGN AS OOP!!!!!!!
*/
