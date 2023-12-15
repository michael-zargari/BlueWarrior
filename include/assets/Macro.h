#pragma once

//window settings
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 800;

//MainMenu data
const int NUM_OF_OPTIONS = 4;


//enum classes
enum class Characters {Warrior, FlyingEye, Goblin, Mushroom, Skeleton};
enum class Action { Attack, Death, Idle, Move, TakeHit, Jump, Falling/*,Landing*/,  SpellCast, Crouch, Shield  };