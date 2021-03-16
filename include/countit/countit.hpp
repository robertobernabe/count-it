#pragma once
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

    public:
        CountIt()
        {
            auto user_directory = stdfs::path(System::get_user_home_directory());
            auto storage_directory_path = user_directory / COUNTIT_FOLDER_NAME;
            stdfs::create_directories(storage_directory_path);
            storage_filepath = storage_directory_path / COUNTIT_STORAGE_FILE_NAME;
        };

        void add_counter(std::string name = "default")
        {
            auto c = TapCounter(name);
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

        void deserialize()
        {
            std::ifstream i(storage_filepath.string());
            std::string str((std::istreambuf_iterator<char>(i)), std::istreambuf_iterator<char>());
            nlohmann::json j = nlohmann::json::parse(str);
            std::cout << "file json: " << j << std::endl;
            counters = j.get<std::vector<TapCounter>>();
        }

        void serialize()
        {
            nlohmann::json j = counters;
            std::cout << "json: " << j << std::endl;

            std::ofstream o;
            std::lock_guard<std::mutex> lock(mutex);
            std::cout << "Saveing: " << storage_filepath.string() << std::endl;
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