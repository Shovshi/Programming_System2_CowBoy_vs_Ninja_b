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
    
    int size;

    public:
    vector <Character*> team;
    Team(Character *leader);
    Team();
    ~Team();
    void add(Character *character);
    void attack(Team *enemy);
    int stillAlive();
    void print();
    void setLeader(Character *character);
    Character* closest_player(Team *enemy);
    Character* closest_player_alive(Team *enemy);
    Character *leader;

    };
}