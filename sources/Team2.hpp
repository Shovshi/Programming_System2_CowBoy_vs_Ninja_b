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
#include "Team.hpp"
using namespace std;

namespace ariel
{
    class Team2 : public Team{
    
    private:
    Character *leader;
    vector <Character> team2;

    public:
    Team2(Character *leader);
    ~Team2();
    void attack(Team *enemy);
    int stillAlive();
    void print();

    };
}