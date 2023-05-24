#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

namespace ariel
{
    Cowboy::Cowboy(std::string name , Point location): Character(location , 110 , name , 'C')
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
        int enemyHit = enemy->getHit();
        if (isAlive() && hasboolets())
        {          
            ballsNum -=1; 
            enemyHit = enemyHit -10;
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
        ballsNum += 6;
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