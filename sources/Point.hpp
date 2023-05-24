#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Point{
    
    private:
    double x;
    double y;

    public:
    Point(double x , double y);
    Point(Point &other);
    Point();
    double distance(Point other);
    std::string print();
    static Point moveTowards(Point source , Point dest , double dis);
    double getX();
    double getY();
    };
}