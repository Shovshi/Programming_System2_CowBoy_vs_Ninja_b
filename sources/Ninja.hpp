#pragma once
#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {

        int speed;
        char type = 'N';

        public:
        // Constructors
        Ninja(std::string name, Point location ,int _hit , int speed);
        Ninja(Ninja &other);


        void move(Character *enemy);
        int getSpeed();
        void slash(Character *enemy);
    };
}