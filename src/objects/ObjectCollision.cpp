#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "objects/Object.h"
#include "objects/Player.h"
#include "objects/StaticObject.h"




namespace {//begin namespace

    //-------------HIT FUNCTIONS-----------

    void playerTile(Object& player, Object& tile) {
        sf::Vector2f newPos;
        newPos = static_cast<Player&>(player).getCurrentPosition();
        newPos.y = static_cast<Player&>(player).getpreviousPosition().y;
        static_cast<Player&>(player).changePosition(newPos);
    }

    void tilePlayer(Object& tile, Object& player) {
        playerTile(player, tile);
    }

    //-----------END HIT FUNCTION------------

    using HitFunctionPtr = std::function<void(Object&, Object&)>;
    // typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    // std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(StaticObject))] = &playerTile;
        phm[Key(typeid(StaticObject), typeid(Player))] = &tilePlayer;

        //phm[Key(typeid(Ground), typeid(BlueBird))] = &GroundBird;
        //phm[Key(typeid(BlueBird), typeid(Ground))] = &BirdGround;

        //phm[Key(typeid(Ground), typeid(YellowBird))] = &GroundBird;
        //phm[Key(typeid(YellowBird), typeid(Ground))] = &BirdGround;

        //phm[Key(typeid(Ground), typeid(BlackBird))] = &GroundBird;
        //phm[Key(typeid(BlackBird), typeid(Ground))] = &BirdGround;

        //phm[Key(typeid(Obstacle), typeid(Obstacle))] = &ObstacleObstacle;

        //phm[Key(typeid(RedBird), typeid(Obstacle))] = &birdObstacle;
        //phm[Key(typeid(Obstacle), typeid(RedBird))] = &CircularObstacleBird;

        //phm[Key(typeid(YellowBird), typeid(Obstacle))] = &birdObstacle;
        //phm[Key(typeid(Obstacle), typeid(YellowBird))] = &CircularObstacleBird;


        //phm[Key(typeid(BlueBird), typeid(Obstacle))] = &birdObstacle;
        //phm[Key(typeid(Obstacle), typeid(BlueBird))] = &CircularObstacleBird;


        //phm[Key(typeid(BlackBird), typeid(Obstacle))] = &birdObstacle;
        //phm[Key(typeid(Obstacle), typeid(BlackBird))] = &CircularObstacleBird;

        //phm[Key(typeid(Ground), typeid(Obstacle))] = &groundObstacle;
        //phm[Key(typeid(Obstacle), typeid(Ground))] = &ObstacleGround;

        //// Circular Obstacle
        //phm[Key(typeid(Obstacle), typeid(CircularObstacle))] = &ObstacleObstacle;
        //phm[Key(typeid(CircularObstacle), typeid(Obstacle))] = &ObstacleObstacle;

        //phm[Key(typeid(CircularObstacle), typeid(CircularObstacle))] = &ObstacleObstacle;

        //phm[Key(typeid(RedBird), typeid(CircularObstacle))] = &birdCircularObstacle;
        //phm[Key(typeid(CircularObstacle), typeid(RedBird))] = &ObstacleBird;

        //phm[Key(typeid(YellowBird), typeid(CircularObstacle))] = &birdCircularObstacle;
        //phm[Key(typeid(CircularObstacle), typeid(YellowBird))] = &ObstacleBird;


        //phm[Key(typeid(BlueBird), typeid(CircularObstacle))] = &birdCircularObstacle;
        //phm[Key(typeid(CircularObstacle), typeid(BlueBird))] = &ObstacleBird;

        //phm[Key(typeid(BlackBird), typeid(CircularObstacle))] = &birdCircularObstacle;
        //phm[Key(typeid(CircularObstacle), typeid(BlackBird))] = &ObstacleBird;

        //phm[Key(typeid(Ground), typeid(CircularObstacle))] = &groundObstacle;
        //phm[Key(typeid(CircularObstacle), typeid(Ground))] = &ObstacleGround;

        return phm;
    }


    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

}//end namespace

void handleCollision(Object& object1, Object& object2) {

    auto collisionFunc = lookup(typeid(object1), typeid(object2));
    if (!collisionFunc)
        return;

    collisionFunc(object1, object2);
}