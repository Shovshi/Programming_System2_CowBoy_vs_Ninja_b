#pragma once
#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character{
    
    private:
    Point location;
    int _hit;
    std:: string name;
    char type;

    public:
    
    // Constructors
    Character(Point location , int hit , std::string name, char type);
    Character(Character &other);
    Character();

    // Class functions
    bool isAlive();
    double distance(Character *other);
    void hit(int num);
    std::string getName();
    Point getLocation();
    void setLocation(Point curr);
    std::string print();
    void setHit(int num);
    int getHit();
    char getType();
    };
}