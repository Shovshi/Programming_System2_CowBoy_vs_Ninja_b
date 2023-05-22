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
    class Team{
    
    private:
    Character *leader;
    vector <Character*> team;
    int size;

    public:
    Team(Character *leader);
    ~Team();
    void add(Character *character);
    void attack(Team *enemy);
    int stillAlive();
    void print();
    void setLeader(Character *character);
    Character* closest_player(Character *player);

    };
}