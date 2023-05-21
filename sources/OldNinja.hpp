#pragma once
#include "Ninja.hpp"

namespace ariel 
{
    class OldNinja: public Ninja
    {
        public:
        // Constructor
        OldNinja(std::string name , Point location);
    };
}