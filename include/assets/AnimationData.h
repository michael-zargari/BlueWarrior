#pragma once

#include "Macro.h"

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
    AnimationData skeletoWarriorData()
    {
        //def init
        auto skeletonData = AnimationData{};

        auto initAction = [&](int dataAmount, Action action, sf::Vector2i start, sf::Vector2i size, sf::Vector2i diff)
        {
            for (int i = 0; i < dataAmount; i++)
                skeletonData.m_data[action].emplace_back(start, size);
        };

        //Run Settings: size{ 60,60 }, start { 30,70 }, diff = 130
        initAction(8, Action::Run_Right, sf::Vector2i{ 30, 70 }, sf::Vector2i{ 60, 60 }, sf::Vector2i{ 130, 0 });

        //Attack1 Settings: size{ 60,62 }, start { 20,65 }, diff = 120
        initAction(8, Action::Run_Right, sf::Vector2i{ 20, 65 }, sf::Vector2i{ 60, 62 }, sf::Vector2i{ 120, 0 });

        return skeletonData;
    }
}
