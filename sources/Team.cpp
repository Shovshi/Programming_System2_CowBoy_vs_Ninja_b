#include "Team.hpp"
#include <cmath>
#include <limits>

namespace ariel
{

    Team::Team(Character *leader)
    {
        this->leader = leader;
        this->team.push_back(leader);
        this->size = 1;
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

    void Team::setLeader(Character *character)
    {
        this->leader = character;
    }


    void Team::add(Character *character)
    {
        if (team.size() >= 10)
        {
            throw runtime_error("The team is full");
        }

        if(character)
        {
            team.push_back(character);
        }
        else
        {
            throw runtime_error("The player is null");
        }
    }

    Character* Team::closest_player(Character *curr_player)
    {
        Character *closestPlayer;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *teammate : team)
        {
            if (teammate->isAlive())
            {
                double distance = curr_player->distance(*teammate);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestPlayer = teammate;
                }
            }
            else
            {
                throw runtime_error("The team not exist");
            }
        }

        return closestPlayer;
    }


    void Team::attack(Team *enemy)
    {
        if (!enemy->leader)
        {
            Character *new_leader = closest_player(enemy->leader);
            enemy->setLeader(new_leader);
        }
        Character *victim = closest_player(leader);

        for (Character *teammate : team)
        {
            if (teammate->getType() == 'C')
            {
                Cowboy *cow_boy = static_cast<Cowboy*>(teammate);
                if (cow_boy->hasboolets())
                {
                    cow_boy->shoot(victim);
                }
                else
                {
                    cow_boy->reload();
                }
            }
            if (teammate->getType() == 'N')
            {
                Ninja *ninja = static_cast<Ninja*>(teammate);
                if (ninja)
                {
                    
                }
                else
                {
                    
                }
            }
            
        }
              
    }

    int Team::stillAlive()
    {
        return team.size();
    }

    void Team::print()
    {
        for (Character *character : team)
        {
            character->print(); 
        }
    }

}