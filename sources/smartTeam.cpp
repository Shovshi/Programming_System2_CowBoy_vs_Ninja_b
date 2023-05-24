#include "smartTeam.hpp"
#include <algorithm>

namespace ariel
{

    smartTeam::smartTeam(Character *new_leader)
        : Team(new_leader)
    {
    }

    smartTeam::~smartTeam()
    {
    }

    void smartTeam::attack(Team *enemy)
    {
         if (enemy == nullptr) {
        throw std::invalid_argument("Enemy team is null");
    }

    if (!enemy->stillAlive()) {
        throw std::runtime_error("The enemy is already dead");
    }

    if (leader == nullptr) {
        throw std::runtime_error("Leader is null");
    }

    if (!leader->isAlive()) {
        Character* new_leader = closest_player(this);
        if (new_leader == nullptr) {
            cout << "No Enemy Found" << endl;
            return;
        }
        this->setLeader(new_leader);
    }

    // Sort the enemy team based on distance from the current team's leader
    Team* sortedEnemyTeam = sort_enemy_team(enemy);

    for (Character* teammate : team) {
        Character* victim = sortedEnemyTeam->closest_player_alive(this);
        if (victim == nullptr) {
            delete sortedEnemyTeam;  // Clean up allocated memory
            return;
        }

        if (teammate->getType() == 'C') {
            Cowboy* cow_boy = dynamic_cast<Cowboy*>(teammate);
            if (cow_boy->isAlive() && !cow_boy->hasboolets()) {
                cow_boy->reload();
            }
            else if (cow_boy->isAlive() && victim->isAlive()) {
                cow_boy->shoot(victim);
            }
        }

        if (teammate->getType() == 'N') {
            Ninja* ninja = dynamic_cast<Ninja*>(teammate);
            if (ninja->distance(victim) <= 1 && ninja->isAlive()) {
                ninja->slash(victim);
            }
            else {
                ninja->move(victim);
            }
        }
    }

    delete sortedEnemyTeam;  // Clean up allocated memory
    }

    Team *smartTeam::sort_enemy_team(Team *team)
    {
        if (team == nullptr)
        {
            throw std::invalid_argument("Team is null");
        }

        // Get the leader of the current team
        Character *currentLeader = leader;
        if (currentLeader == nullptr)
        {
            throw std::runtime_error("Current team leader is null");
        }

        // Create a copy of the enemy team
        Team *sortedTeam = new Team();
        *sortedTeam = *team;

        // Sort the enemy team based on distance from the current leader
        std::sort(sortedTeam->team.begin(), sortedTeam->team.end(), [currentLeader](Character *a, Character *b)
                  {
        double dist_a = a->distance(currentLeader);
        double dist_b = b->distance(currentLeader);
        return dist_a < dist_b; });

        return sortedTeam;
    }

int smartTeam::stillAlive()
{
    int stillAlive = 0;
    for (size_t i = 0; i < team.size(); i++)
    {
        if (team[i]->isAlive())
        {
            stillAlive++;
        }
    }
    return stillAlive;
}
void smartTeam::print()
{
}
}