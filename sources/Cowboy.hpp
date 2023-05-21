#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {

    char type = 'C';
    int ballsNum;

    public:
    // Constructors
    Cowboy(std::string name , Point location);
    Cowboy();
    ~Cowboy();


    void shoot(Character *enemy);
    bool hasboolets();
    void reload();
    char getType();
    int getBallsNum();
    std::string print();

    };
}