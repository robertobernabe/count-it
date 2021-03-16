#pragma once
#include <string>
#include <fmt/color.h>
#include <nlohmann/json.hpp>

namespace robertobernabe::countit
{
    class TapCounter
    {
    private:
        int count{ 1 };
        std::string name{};
        fmt::color color{};

    public:
        TapCounter(std::string name) : name(name), color(fmt::color::white){};
        TapCounter() : name("default"), color(fmt::color::red){};

        fmt::color get_color() const
        {
            return color;
        }

        void set_color(fmt::color value)
        {
            color = value;
        }

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