#pragma once

#include "Macro.h"
#include "assets/GameResources.h"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <vector>

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<Action, ListType>;
    DataType m_data;

};

namespace
{
    //=======================================================================================================================
    //initilaize two lists with enum types for actions
    std::initializer_list<Action> warriorActions = { Action::Attack, Action::Death, Action::Idle, Action::Move, Action::TakeHit,
                                Action::Jump, Action::Falling/*,Action::Landing*/,  Action::SpellCast, Action::Crouch, Action::Shield };

    std::initializer_list<Action> otherActions = { Action::Attack, Action::Death, Action::Idle, Action::Move, Action::TakeHit };
    //=======================================================================================================================

    std::vector<sf::RectangleShape> getAnimation(const Characters& character)
    {        
        /*this function returns vector of sf::RectangleShapes 
          that holds the textures for the game characters*/

        auto actions = std::list<Action>();
        
        character == Characters::Warrior ? actions = warriorActions : actions = otherActions;

        auto animation = std::vector<sf::RectangleShape>();

        for (auto i : actions)
        {
            animation.emplace_back().setTexture(&GameResources::getInstance().getCharacterTexture(character, i));
            animation.back().setSize({90, 90});
            animation.back().setOrigin({ 90 / 2, 90 / 2 });
            animation.back().setPosition({ 600,400 });
        }

        return animation;
    }

    //=========================================================================
    AnimationData blueWarriorData()
        /*ordered all the position of the warrior animation from is texture
        return: struct which holds unordered_map the holds the data according to actions*/
    {
        auto warrior = AnimationData();

        warrior.m_data[Action::Idle] = { sf::IntRect{15,23, 26, 34} ,sf::IntRect{72,23, 26, 34}, sf::IntRect{129,23, 28, 34} ,
                                            sf::IntRect{184,22, 28, 34} , sf::IntRect{241,22, 28, 34} , sf::IntRect{296,22, 28, 34} };

        warrior.m_data[Action::Attack] = { sf::IntRect{8,79, 35, 35}, sf::IntRect{62,79, 35, 35} ,sf::IntRect{122,79, 35, 35},
                                                sf::IntRect{180,79, 35, 35} , sf::IntRect{235,79, 35, 35}  , sf::IntRect{291,79, 35, 35} ,
                                                sf::IntRect{348,79, 35, 35} , sf::IntRect{402,79, 35, 35} };

        warrior.m_data[Action::Move] = { sf::IntRect{16,135, 27, 34}, sf::IntRect{71,135, 27, 34} ,sf::IntRect{127, 135, 27, 34},
                                                   sf::IntRect{181,135, 27, 34} , sf::IntRect{239,135, 27, 34}  , sf::IntRect{294,135, 27, 34} ,
                                                   sf::IntRect{350,135, 27, 34} , sf::IntRect{406,135, 27, 34} };

        warrior.m_data[Action::Jump] = { sf::IntRect{7, 185, 40, 44}, sf::IntRect{63, 185, 40, 44}
        //from here on its flying
        //,sf::IntRect{119, 185, 40, 44},
        // sf::IntRect{175, 185, 40, 44} , sf::IntRect{231, 185, 40, 44}  , sf::IntRect{287, 185, 40, 44} ,
        , sf::IntRect{341, 185, 40, 44} , sf::IntRect{397, 185, 40, 44} , sf::IntRect{7, 238, 40, 44} ,
            //from here on its falling 
            //sf::IntRect{63, 238, 40, 44} , sf::IntRect{119, 238, 40, 44} , sf::IntRect{175, 238, 40, 44} ,
            // sf::IntRect{232, 238, 40, 44} ,
            //from here on its landing
            sf::IntRect{287,238, 40, 44} , sf::IntRect{341,238, 40, 44}, sf::IntRect{398,238, 40, 44} };

        warrior.m_data[Action::Falling] = { sf::IntRect{63, 238, 40, 44} , sf::IntRect{119, 238, 40, 44} , sf::IntRect{175, 238, 40, 44} ,
                                                  sf::IntRect{232, 238, 40, 44} };

        warrior.m_data[Action::TakeHit] = { sf::IntRect{7, 299, 40 , 40 }, sf::IntRect{62, 299, 40 , 40 }, sf::IntRect{118, 299, 40 , 40 },
                                                  sf::IntRect{173, 299, 40 , 40 } };


        warrior.m_data[Action::Death] = { sf::IntRect{7, 354, 40 , 40 }, sf::IntRect{64, 354, 40 , 40 }, sf::IntRect{121, 354, 40 , 40 },
                                                 sf::IntRect{175, 354, 40 , 40 }, sf::IntRect{230, 354, 40 , 40 }, sf::IntRect{286, 354, 40 , 40 },
                                                 sf::IntRect{341, 354, 40 , 40 }, sf::IntRect{393, 354, 45 , 40 }, sf::IntRect{2, 411, 45 , 40 },
                                                 sf::IntRect{58, 411, 45 , 40 }, sf::IntRect{114, 411, 45 , 40 }, sf::IntRect{170, 411, 45 , 40 } };


        warrior.m_data[Action::SpellCast] = { sf::IntRect{4 ,450 ,45 ,55 }, sf::IntRect{59 ,450 ,45 ,55 }, sf::IntRect{114 ,450 ,45 ,55 },
                                                 sf::IntRect{170 ,450 ,45 ,55 }, sf::IntRect{225 ,450 ,45 ,55 }, sf::IntRect{282 ,450 ,45 ,55 },
                                                 sf::IntRect{338 ,450 ,45 ,55 }, sf::IntRect{395 ,450 ,45 ,55 } };

        warrior.m_data[Action::Crouch] = { sf::IntRect{7 ,522 ,40 ,40 }, sf::IntRect{63 ,522 ,40 ,40 }, sf::IntRect{118 ,522 ,40 ,40 } };

        warrior.m_data[Action::Shield] = { sf::IntRect{7 ,576 ,40 ,40 }, sf::IntRect{63 ,576 ,40 ,40 }, sf::IntRect{118 ,576 ,40 ,40 } };

        return warrior;
    }

    //==================================================================================================
    AnimationData FlyingEyeData()
        /*ordered all the position of the FlyingEye animation from is texture
        return: struct which holds unordered_map the holds the data according to actions*/
    {
        auto flyingEye = AnimationData();

        flyingEye.m_data[Action::Attack] = { sf::IntRect{56, 54, 45, 40}, sf::IntRect{206, 54, 45, 40}, sf::IntRect{351, 54, 45, 40}, sf::IntRect{503, 54, 45, 40} };

        flyingEye.m_data[Action::Death] = { sf::IntRect{56, 54, 45, 45}, sf::IntRect{206, 54, 45, 45}, sf::IntRect{348, 54, 60, 48}, sf::IntRect{502, 54, 50, 48} };

        flyingEye.m_data[Action::Idle] = { sf::IntRect{56, 54, 45, 40}, sf::IntRect{207, 54, 45, 40}, sf::IntRect{356, 54, 45, 40}, sf::IntRect{505, 54, 45, 40} ,
                                                      sf::IntRect{655, 54, 45, 40}, sf::IntRect{804, 54, 45, 40}, sf::IntRect{957, 54, 45, 40}, sf::IntRect{1107, 54, 45, 40} };

        flyingEye.m_data[Action::Move] = { sf::IntRect{56, 54, 45, 40}, sf::IntRect{207, 54, 45, 40}, sf::IntRect{356, 54, 45, 40}, sf::IntRect{505, 54, 45, 40} ,
                                                  sf::IntRect{655, 54, 45, 40}, sf::IntRect{804, 54, 45, 40}, sf::IntRect{957, 54, 45, 40}, sf::IntRect{1107, 54, 45, 40} };

        flyingEye.m_data[Action::TakeHit] = { sf::IntRect{56, 54, 45, 40}, sf::IntRect{206, 54, 45, 40}, sf::IntRect{356, 54, 45, 40}, sf::IntRect{505, 54, 45, 40} };

        return flyingEye;
    }

    //==================================================================================================
    AnimationData goblinData()
    {
        auto goblin = AnimationData();

        goblin.m_data[Action::Attack] = { sf::IntRect{56, 54, 40, 50}, sf::IntRect{208, 54, 40, 50}, sf::IntRect{357, 54, 40, 50}, sf::IntRect{507, 54, 40, 50},
                                                sf::IntRect{657, 54, 40, 50}, sf::IntRect{807, 54, 40, 50}, sf::IntRect{930, 54, 90, 50}, sf::IntRect{1080, 54, 90, 50} };

        goblin.m_data[Action::Death] = { sf::IntRect{56, 54, 45, 40}, sf::IntRect{205, 62, 45, 40}, sf::IntRect{356, 62, 45, 40}, sf::IntRect{508, 64, 55, 40} };

        goblin.m_data[Action::Idle] = { sf::IntRect{56, 54, 40, 50}, sf::IntRect{208, 54, 40, 50}, sf::IntRect{357, 54, 40, 50}, sf::IntRect{507, 54, 40, 50} };

        goblin.m_data[Action::Move] = { sf::IntRect{55, 54, 40, 50}, sf::IntRect{205, 54, 40, 50}, sf::IntRect{357, 54, 40, 50}, sf::IntRect{506, 54, 40, 50},
                                                sf::IntRect{658, 54, 40, 50}, sf::IntRect{808, 54, 40, 50}, sf::IntRect{957, 54, 40, 50}, sf::IntRect{1107, 54, 40, 50} };

        goblin.m_data[Action::TakeHit] = { sf::IntRect{56, 54, 40, 50}, sf::IntRect{208, 54, 40, 50}, sf::IntRect{357, 54, 40, 50}, sf::IntRect{507, 54, 40, 50} };

        return goblin;
    }

    //==================================================================================================
    AnimationData mushroomData()
    {
        auto mushroom = AnimationData();

        mushroom.m_data[Action::Attack] = { sf::IntRect{56, 54, 40, 50}, sf::IntRect{208, 54, 40, 50}, sf::IntRect{354, 54, 40, 50}, sf::IntRect{503, 54, 40, 50},
                                                sf::IntRect{653, 54, 40, 50}, sf::IntRect{803, 54, 40, 50}, sf::IntRect{926, 54, 90, 50}, sf::IntRect{1076, 54, 90, 50} };

        mushroom.m_data[Action::Death] = { sf::IntRect{56, 54, 45, 40}, sf::IntRect{205, 62, 45, 40}, sf::IntRect{356, 62, 45, 40}, sf::IntRect{508, 64, 55, 40} };

        mushroom.m_data[Action::Idle] = { sf::IntRect{56, 54, 40, 50}, sf::IntRect{208, 54, 40, 50}, sf::IntRect{357, 54, 40, 50}, sf::IntRect{507, 54, 40, 50} };

        mushroom.m_data[Action::Move] = { sf::IntRect{55, 54, 40, 50}, sf::IntRect{205, 54, 40, 50}, sf::IntRect{357, 54, 40, 50}, sf::IntRect{506, 54, 40, 50},
                                                sf::IntRect{658, 54, 40, 50}, sf::IntRect{808, 54, 40, 50}, sf::IntRect{957, 54, 40, 50}, sf::IntRect{1107, 54, 40, 50} };

        mushroom.m_data[Action::TakeHit] = { sf::IntRect{56, 54, 40, 50}, sf::IntRect{208, 54, 40, 50}, sf::IntRect{342, 54, 40, 50}, sf::IntRect{498, 54, 40, 50} };

        return mushroom;
    }

    //==================================================================================================
    AnimationData skeletonData()
    {
        auto skeleton = AnimationData();

        skeleton.m_data[Action::Attack] = { sf::IntRect{58, 42, 50, 60}, sf::IntRect{207, 42, 50, 60}, sf::IntRect{347, 42, 50, 60}, sf::IntRect{499, 42, 50, 60},
                                                sf::IntRect{648, 42, 50, 60}, sf::IntRect{800, 42, 50, 60}, sf::IntRect{966,42, 85, 60}, sf::IntRect{1115, 42, 85, 60} };

        skeleton.m_data[Action::Death] = { sf::IntRect{58, 42, 50, 60}, sf::IntRect{205, 42, 55, 60}, sf::IntRect{352, 42, 55, 60}, sf::IntRect{502, 42, 55, 60} };

        skeleton.m_data[Action::Idle] = { sf::IntRect{58, 42, 50, 60}, sf::IntRect{207, 42, 50, 60}, sf::IntRect{358, 42, 50, 60}, sf::IntRect{508, 42, 50, 60} };

        skeleton.m_data[Action::Move] = { sf::IntRect{58, 42, 50, 60}, sf::IntRect{207, 42, 50, 60}, sf::IntRect{358, 42, 50, 60}, sf::IntRect{508, 42, 50, 60} };

        skeleton.m_data[Action::TakeHit] = { sf::IntRect{58, 42, 50, 60}, sf::IntRect{207, 42, 50, 60}, sf::IntRect{347, 42, 55, 60}, sf::IntRect{502, 42, 50, 60} };

        return skeleton;
    }

}
