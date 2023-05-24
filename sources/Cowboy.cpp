#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

namespace ariel
{
    Cowboy::Cowboy(std::string name, Point location) : Character(location, 110, name, 'C', false)
    {
        this->ballsNum = 6;
    }

    Cowboy::Cowboy()
    {
    }

    Cowboy::~Cowboy()
    {
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::runtime_error("The enemy is null");
        }
        if (!enemy->isAlive())
        {
            throw std::runtime_error("The enemy is dead");
        }
        if (!this->isAlive())
        {
            throw std::runtime_error("This player is dead");
        }
        if (this == enemy)
        {
            throw std::runtime_error("No self harm");
        }
        int enemyHit = enemy->getHit();
        if (isAlive() && hasboolets())
        {
            ballsNum -= 1;
            enemyHit -= 10;
            if (enemyHit < 0)
            {
                enemy->setHit(0);
            }
            enemy->setHit(enemyHit);
        }
    }

    bool Cowboy::hasboolets()
    {
        if (getBallsNum() > 0)
        {
            return true;
        }
        return false;
    }

    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw std::runtime_error("The player is dead");
        }
        ballsNum = 6;
    }

    int Cowboy::getBallsNum()
    {
        return ballsNum;
    }

    char Cowboy::getType()
    {
        return type;
    }

    std::string Cowboy::print()
    {
        std::string output = "Character Details:'C'\n";
        if (getHit() > 0)
        {
            output += "Name: " + getName() + "\n";
            output += "Hit Points: " + std::to_string(getHit()) + "\n";
            output += "Location: " + getLocation().print() + "\n";
        }

        else
        {
            output += "(Name: " + getName() + ")" + "\n";
            output += "Location: " + getLocation().print() + "\n";
        }
        return output;
    }
}