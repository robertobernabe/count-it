#pragma once
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "tap_counter.hpp"
#include "json_data.hpp"

namespace robertobernabe::countit
{
    class CountIt
    {
    private:
        std::vector<TapCounter> counters{};

    public:
        CountIt(){};

        void add_counter(std::string name = "default")
        {
            auto c = TapCounter();
            counters.push_back(c);
        }

        void increment_counter(std::string name = "default")
        {
        }

        TapCounter get_counter(std::string name = "default")
        {
            for (auto c : counters)
            {
                if (c.get_name() == name)
                {
                    return c;
                }
            }
        }

        std::vector<TapCounter> get_all_counters()
        {
            return counters;
        }

        void serialize()
        {
            nlohmann::json j = counters;
            std::cout << "json: " << j << std::endl;
        }
    };
};