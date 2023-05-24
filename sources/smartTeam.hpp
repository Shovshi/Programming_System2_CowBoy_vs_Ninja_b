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
    class smartTeam : public Team{
    
    private:
    vector <Character> smarteam;

    public:
    smartTeam(Character *leader);
    ~smartTeam();
    void attack(Team *enemy);
    int stillAlive();
    void print();

    };
}