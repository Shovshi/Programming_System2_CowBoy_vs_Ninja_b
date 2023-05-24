#include "Point.hpp"
#include <cmath>
#include <sstream>
#include <string>

namespace ariel
{

    // Constructors
    Point::Point(double x , double y)
    {
        this->x = x;
        this->y = y;
    }

    Point::Point(Point &other)
    {
        x = other.getX();
        y = other.getY();
    }

    Point::Point()
    {
        x = 0.0;
        y = 0.0;
    }

    double Point::distance(Point other)
    {
        double dx = other.getX()- x;
        double dy = other.getY() - y;
        return std::sqrt(dx*dx + dy*dy);
    }

    std::string Point::print()
    {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }

    Point Point::moveTowards(Point source , Point dest , double dis)
    {
        if (dis < 0)
        {
           throw std::invalid_argument("The distance is negative");
        }
        double d = source.distance(dest);
        if (d <= dis)
        {
            return dest;
        }
        else
        {
            double ratio = dis / d;
            double newX = source.getX() + ratio * (dest.getX() - source.getX());
            double newY = source.getY() + ratio * (dest.getY() - source.getY());
            return Point(newX, newY);
        }
    }

    // Getters
    double Point::getX()
    {
        return x;
    }
    double Point::getY()
    {
        return y;
    }
}