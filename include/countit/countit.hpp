#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <mutex>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include "tap_counter.hpp"
#include "json_data.hpp"
#include "system.hpp"

namespace robertobernabe::countit
{
    class CountIt
    {
    private:
        std::mutex mutex;
        std::vector<TapCounter> counters{};
        const std::string COUNTIT_FOLDER_NAME = ".countit";
        const std::string COUNTIT_STORAGE_FILE_NAME = "storage.json";
        stdfs::path storage_filepath{};

        const fmt::color colors[6] = { fmt::color::red,   fmt::color::blue,   fmt::color::green,
                                       fmt::color::white, fmt::color::yellow, fmt::color::chocolate };

        fmt::color get_random_color()
        {
            srand(time(0));
            auto index = rand() % 6;
            return colors[index];
        }

    public:
        CountIt()
        {
            auto user_directory = stdfs::path(System::get_user_home_directory());
            auto storage_directory_path = user_directory / COUNTIT_FOLDER_NAME;
            stdfs::create_directories(storage_directory_path);
            storage_filepath = storage_directory_path / COUNTIT_STORAGE_FILE_NAME;
        };

        bool storage_file_exists()
        {
            return stdfs::exists(storage_filepath);
        }

        void add_counter(std::string name = "default")
        {
            auto e = get_counter(name);
            if (e.get_is_empty())
            {
                auto c = TapCounter(name);
                c.set_color(get_random_color());
                counters.push_back(c);
            }
            else
            {
                increment_counter(name);
            }
        }

        void increment_counter(std::string name = "default")
        {
            for (auto& c : counters)
            {
                if (c.get_name() == name)
                {
                    c++;
                }
            }
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
            auto e = TapCounter();
            e.set_is_empty();
            return e;
        }

        std::vector<TapCounter> get_all_counters()
        {
            return counters;
        }

        void deserialize()
        {
            if (stdfs::exists(storage_filepath))
            {
                std::ifstream i(storage_filepath.string());
                std::string str((std::istreambuf_iterator<char>(i)), std::istreambuf_iterator<char>());
                nlohmann::json j = nlohmann::json::parse(str);
                counters = j.get<std::vector<TapCounter>>();
            }
        }

        void serialize()
        {
            nlohmann::json j = counters;
            std::ofstream o;
            std::lock_guard<std::mutex> lock(mutex);
            fmt::print("Save: {}\n", storage_filepath.string());
            o.open(storage_filepath.string());
            o << std::setw(4) << j << "\n";
            o.close();
            if (o.bad())
            {
                throw std::runtime_error("Could not write to file.");
            }
        }
    };
};