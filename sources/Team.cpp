#include "Team.hpp"
#include <cmath>
#include <limits>

namespace ariel
{

    Team::Team(Character *leader)
    {
        if (leader == nullptr)
        {
            throw std::runtime_error("The leader is null");
        }
        if (leader->getIsPLaying())
        {
            throw std::runtime_error("This leader already in used");
        }

        this->leader = leader;
        this->team.push_back(leader);
        this->size = 1;
        leader->setIsPlaying(true);
    }

    Team::~Team()
    {
        // Deallocate memory for each character in the vector
        for (Character *character : team)
        {
            character->~Character();
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
        if (character->getIsPLaying())
        {
            throw runtime_error("This player already in used");
        }

        if (character)
        {
            team.push_back(character);
            character->setIsPlaying(true);
        }
        else
        {
            throw runtime_error("The player is null");
        }
    }

    Character *Team::closest_player(Team *enemy)
    {
        Character *closestPlayer;
        double minDistance = std::numeric_limits<double>::max();

        for (size_t i = 0; i < enemy->team.size(); i++)
        {
            if ((this->leader->distance(enemy->team[i])) < minDistance)
            {
                if ((enemy->team[i])->isAlive())
                {
                    minDistance = this->leader->distance(enemy->team[i]);
                    closestPlayer = enemy->team[i];
                }
            }
        }
        return closestPlayer;
    }
    Character *Team::closest_player_alive(Team *enemy)
    {
        Character *closestPlayerAlive = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (size_t i = 0; i < enemy->team.size(); i++)
        {
            if (enemy->team[i]->isAlive())
            {
                if ((this->leader->distance(enemy->team[i])) < minDistance)
                {
                    if ((enemy->team[i])->isAlive())
                    {
                        minDistance = this->leader->distance(enemy->team[i]);
                        closestPlayerAlive = enemy->team[i];
                    }
                }
            }
        }
        return closestPlayerAlive;
    }
    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("Enemy team is null");
        }

        if (!enemy->stillAlive())
        {
            throw std::runtime_error("The enemy is already dead");
        }
        if (!leader->isAlive())
        {
            Character *new_leader = closest_player(this);
            if(new_leader == nullptr)
            {
                cout << "Enemy Team Defeated "<<endl;
                return;
            }
            this->setLeader(new_leader);
        }
        for (Character *teammate : team)
        {
            Character *victim = closest_player_alive(enemy);
            if (victim == nullptr)
            {
                return;
            }
            if (teammate->getType() == 'C')
            {
                Cowboy *cow_boy = dynamic_cast<Cowboy *>(teammate);
                if (cow_boy->isAlive() && !cow_boy->hasboolets())
                {
                    cow_boy->reload();
                }
                else if (cow_boy->isAlive() && victim->isAlive())
                {
                    cow_boy->shoot(victim);
                }
            }
        }
        for (Character *teammate : team)
        {
            Character *victim = closest_player_alive(enemy);
            if(victim == nullptr)
            {
                cout <<"Enemy Team Defeated" <<endl;
                return;
            }
            if (teammate->getType() == 'N')
            {
                Ninja *ninja = dynamic_cast<Ninja *>(teammate);
                if (ninja->distance(victim) <= 1 && ninja->isAlive())
                {
                    ninja->slash(victim);
                }
                else
                {
                    ninja->move(victim);
                }
            }
        }
    }

int Team::stillAlive()
{
    int stillAlive = 0;

    for (Character *teammate : team)
    {
        if (teammate->getType() == 'C')
        {
            Cowboy *cow_boy = static_cast<Cowboy *>(teammate);
            if (cow_boy->isAlive())
            {
                stillAlive++;
            }
        }
        if (teammate->getType() == 'N')
        {
            Ninja *ninja = static_cast<Ninja *>(teammate);
            if (ninja->isAlive())
            {
                stillAlive++;
            }
        }
    }
    return stillAlive;
}

void Team::print()
{
    for (size_t i = 0; i < team.size(); i++)
    {
        team[i]->print();
    }
}
}