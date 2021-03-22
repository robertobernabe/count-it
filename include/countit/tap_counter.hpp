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
        bool is_empty{ false };

    public:
        TapCounter(std::string name) : name(name), color(fmt::color::white){};
        TapCounter() : name("default"), color(fmt::color::white){};

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

        void set_is_empty(bool value = true)
        {
            is_empty = value;
        }

        bool get_is_empty() const
        {
            return is_empty;
        }

        void operator++(int)
        {
            count++;
        }

        bool operator==(const TapCounter& other)
        {
            if (name == other.get_name() && count == other.get_count())
            {
                return true;
            }
            return false;
        }

        bool operator!=(const TapCounter& other)
        {
            if (name != other.get_name() || count != other.get_count())
            {
                return true;
            }
            return false;
        }
    };
};