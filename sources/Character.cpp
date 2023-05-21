#include "Character.hpp"
#include <cmath>

namespace ariel
{

    // Constructors
    Character::Character(Point location , int hit , std::string name)
    {
        this->location = location;
        this->_hit = hit;
        this->name = name;
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

    // Class functions
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
        if (_hit > 0)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character &other)
    {
        double dx = location.getX() - other.getLocation().getX();
        double dy = location.getY() - other.getLocation().getY();
        return std::sqrt(dx*dx + dy*dy);
    }

    void Character::hit(int num)
    {
        if (num > _hit)
        {
            _hit  = 0;
        }
        _hit = _hit - num;
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
    