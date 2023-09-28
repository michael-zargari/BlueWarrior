#pragma once

//window settings
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 800;

//MainMenu data
const int NUM_OF_OPTIONS = 4;


//enum classes
enum class Characters {Warrior, FlyingEye, Goblin, Mushroom, Skeleton};
enum class WarriorAction { Idle, Attack, Running, Jump, Falling/*,Landing*/, TakeHit, Death, SpellCast, Crouch, Shield };
enum class FlyingEyeAction {Attack, Death, Flight, TakeHit};
enum class GoblinAction {Attack, Death, Idle, Run, TakeHit};
enum class MushroomAction {Attack, Death, Idle, Run, TakeHit};
enum class SkeletonAction {Attack, Death, Idle, Shield, TakeHit, Walk};