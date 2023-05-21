#include "Team.hpp"

namespace ariel
{

    Team::Team(Character *leader)
    {
        this->leader = leader;
    }

    Team::~Team()
    {
        // Deallocate memory for each character in the vector
        for (Character* character : team)
        {
            delete character;
        }

        // Clear the vector
        team.clear();
    }

    void Team::add(Character *character)
    {
        if(character)
        {
            team.push_back(character);
        }
    }

    void Team::attack(Team *enemy)
    {
    }
    int Team::stillAlive()
    {
        return 0;
    }
    void Team::print()
    {
    }

}