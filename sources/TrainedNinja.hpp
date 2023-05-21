#pragma once
#include "Ninja.hpp"

namespace ariel 
{
    class TrainedNinja: public Ninja
    {
        public:
        // Constructor
        TrainedNinja(std::string name , Point location);
    };
}