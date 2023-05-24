#include "Team2.hpp"

namespace ariel
{

    Team2::Team2(Character *new_leader)
    : Team(new_leader)
    {
    }

    Team2::~Team2()
    {

    }

    void Team2::attack(Team *enemy)
    {
         if (enemy == nullptr)
        {
            throw std::invalid_argument("Enemy team is null");
        }

        if (!enemy->stillAlive())
        {
            throw std::runtime_error("The enemy is already dead");
        }
        
        if(leader == nullptr)
        {
            throw std::runtime_error("Leader is null");
        }
        if (!leader->isAlive())
        {
            
            Character *new_leader = closest_player(this);
            if(new_leader == nullptr)
            {
                cout << " No Enemy Found " << endl;
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
    int Team2::stillAlive()
    {
        int stillAlive=0;
        for (size_t i = 0; i< team.size(); i++)
        {
            if(team[i]->isAlive())
            {
                stillAlive++;
            }
        }
        return stillAlive;
    }
    void Team2::print()
    {

    }
    
}