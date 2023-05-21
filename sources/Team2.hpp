#pragma once
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    class Team2{
    
    private:
    Character *leader;
    vector <Character> team2;

    public:
    Team2(Character *leader);
    ~Team2();
    void add(Character *character);
    void attack(Team2 *enemy);
    int stillAlive();
    void print();

    };
}