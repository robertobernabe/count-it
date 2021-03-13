#pragma once
#include <iostream>
#include <string>

namespace robertobernabe::countit
{
    class CountIt
    {

    private:
        int count{1};
        std::string name{};

    public:
        CountIt(std::string name) : name(name){};

        int get_count()
        {
            return count;
        }

        void set_count(int value)
        {
            count = value;
        }

        std::string get_name()
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