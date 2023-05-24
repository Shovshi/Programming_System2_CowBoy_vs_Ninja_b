#include "Character.hpp"
#include "Team.hpp"
#include <vector>
#include <cmath>

namespace ariel
{

    // Constructors
    Character::Character(Point location, int hit, std::string name, char type , bool isPlaying)
    {
        this->location = location;
        this->_hit = hit;
        this->name = name;
        this->type = type;
        this->isPlaying = isPlaying;
    }

    Character::Character(Character &other)
    {
        this->location = other.location;
        this->_hit = other._hit;
        this->name = other.name;
    }

    Character::Character()
    {
    }

    Character::~Character()
    {
    }

    // Class functions
    bool Character::getIsPLaying()
    {
        return isPlaying;
    }

    void Character::setIsPlaying(bool val)
    {
        this->isPlaying = val;
    }

    char Character::getType()
    {
        return type;
    }

    std::string Character::print()
    {
        std::string output = "Character Details:\n";
        if (_hit > 0)
        {
            output += "Name: " + name + "\n";
            output += "Hit Points: " + std::to_string(_hit) + "\n";
            output += "Location: " + location.print() + "\n";
        }

        else
        {
            output += "(Name: " + name + ")" + "\n";
            output += "Location: " + location.print() + "\n";
        }
        return output;
    }

    bool Character::isAlive()
    {
        if (this->getHit() > 0)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character *other)
    {
        return location.distance(other->getLocation());
    }

    void Character::hit(int num)
    {
        if(num < 0)
        {
            throw std::invalid_argument("The hit number is negative");
        }
        if (num > _hit)
        {
             this->setHit(0);
        }
        this->setHit(this->getHit()-num);
    }

    std::string Character::getName()
    {
        return name;
    }
    Point Character::getLocation()
    {
        return location;
    }

    void Character::setLocation(Point curr)
    {
        location = curr;
    }

    void Character::setHit(int num)
    {
        _hit = num;
    }

    int Character::getHit()
    {
        return _hit;
    }

}
