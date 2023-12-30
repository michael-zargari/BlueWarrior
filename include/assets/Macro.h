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


/*================animation speed============
*------------- warrior-------------------
* move = 0.2
* 
*/




//velocity = מהירות(שינוי מקום בהינתן זמן מסויים)ל
/*In this answer I assume you are using C++ Object Oriented Programming. If you are using another language, then hopefully you are still able to make use of my answer.

Do what drumbumLOLcatz said, and do collision detecting. This link has some good examples in JavaScript, which is easy enough to understand and convert to any other language. And a quick Google search should bring up plenty of pages describing in depth collision detecting and how to implement it.
Do the same as 1

If your trying to set up a physics system that uses Gravity and acceleration, I recommend using a 2d Vector:

struct Vector2D {
    float x;
    float y;
}
A Vector can be used to represent a Location and Velocity (along with many other things). To set up a simple physics system you have a Vector for Position Vector2D Position = { 0, 0 };. 
Then you have a Vector represent Velocity Vector2D Velocity = { 1, 1 };, 
with each value hold the rate of change for that axis, and each time you update your objects add the Velocity Vector to the Position Vector, causing your object to move based off of velocity:

Position.x += Velocity.x;  // Increase the X position by the X velocity
Position.y += Velocity.y;  // Increase the Y position by the Y velocity
To add gravity, simply take a Gravity Vector Vector2 Gravity = { 0, 9.8 }; and add it to the Velocity Vector, increasing your fall speed.

As for making it natural? Well... You closest you could get visually to:

if (character touches object) {move accordingly}
Would be to create a method in your Character class that will check for collision with a given object.

if (character.touches(object)) {move accordingly}
The .touches() method should look something like drumbumLOLcatz's example. However, in that example, you can only check if they are touching. You wouldn't be able to tell which object is on which side of the other, which is on top, etc. That is fine for the case of a fireball, but when a player hits a block, you need to know what side it was on. What you might want to do is have the touches() method return a number, indicating what side the player is on. You could then have a switch to handle each direction.

switch character.touches(object)
{
case 1:  // Character is on top
    { move accordingly }
case 2:  // Character is on left
    { move accordingly }
...
{
In that way, you would be able to tell what side the character is on the object. I hope this was of some help to you.*/