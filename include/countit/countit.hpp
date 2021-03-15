#pragma once
#include <iostream>
#include <string>

namespace robertobernabe::countit
{
    class CountIt
    {
    private:
        int count{ 1 };
        std::string name{};

    public:
        CountIt(std::string name) : name(name){};
        CountIt() : name("default"){};

        int get_count() const
        {
            return count;
        }

        void set_count(int value)
        {
            count = value;
        }

        std::string get_name() const
        {
            return name;
        }

        void set_name(std::string value)
        {
            name = value;
        }

        void operator++(int)
        {
            count++;
        }
    };
};