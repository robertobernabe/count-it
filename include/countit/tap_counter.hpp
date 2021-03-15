#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace robertobernabe::countit
{
    class TapCounter
    {
    private:
        int count{ 1 };
        std::string name{};

    public:
        TapCounter(std::string name) : name(name){};
        TapCounter() : name("default"){};

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