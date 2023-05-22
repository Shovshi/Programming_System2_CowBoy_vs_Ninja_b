#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"

namespace ariel
{
    Ninja::Ninja(std::string name, Point location, int _hit, int speed) : Character(location, _hit, name , 'N'), speed(speed)
    {
    }

    Ninja::Ninja(Ninja &other) : Character(other) , speed(other.getSpeed()) , type(other.type)
    {
    }

    void Ninja::move(Character *target)
    {
        if (!isAlive())
            return;

        int toMove = speed;
        Point source_location = getLocation();
        Point target_location = target->getLocation();
        double dis = source_location.distance(target_location);

        if (toMove >= dis)
        {
            setLocation(target_location);
        }
        else
        {
            double dx = target_location.getX() - source_location.getX();
            double dy = target_location.getY() - source_location.getY();

            double ratio = toMove / dis;

            double newX = source_location.getX() + (dx * ratio);
            double newY = source_location.getY() + (dy * ratio);

            Point newLocation = Point(newX, newY);
            setLocation(newLocation);
        }
    }

    void Ninja::slash(Character *target)
    {
        if(isAlive && getLocation().distance(target->getLocation()) < 1)
        {            
            int curr = target->getHit();
            if(curr - 40 < 0)
            {
                target->setHit(0);
            }
            target->setHit(curr - 40);
        }
    }

    int Ninja::getSpeed()
    {
        return speed;
    }
}