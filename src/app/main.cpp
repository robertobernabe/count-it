#include <iostream>
#include <vector>
#include <fmt/format.h>
#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <nlohmann/json.hpp>
#include <fmt/color.h>
#include <countit/countit.hpp>
#include <countit/system.hpp>

using namespace robertobernabe::countit;

int parse_args(CLI::App& app, int argc, char** argv)
{
    CLI11_PARSE(app, argc, argv)
}

int main(int argc, char** argv)
{
    System::set_locale_utf8();
    CLI::App app{ "countit\nA simple cli based tap counter" };
    auto countit = CountIt();
    auto add = app.add_subcommand("add", "Increment count of given counter");
    auto list = app.add_subcommand("list", "List and show specific counter");
    std::string name = "default";
    add->add_option("name", name, "Counter name");

    add->callback([&]() {
        countit.deserialize();
        countit.add_counter(name);
        fmt::print("Added counter: {}\n", name);
        fmt::print("Actual count: {}\n\n", countit.get_counter(name).get_count());
    });
    list->callback([&]() {
        countit.deserialize();
        auto counters = countit.get_all_counters();
        if (!counters.empty())
        {
            fmt::print("Available counters:\n");
            for (auto c : counters)
            {
                fmt::print(fg(c.get_color()), "{}: {}\n", c.get_name(), c.get_count());
            }
        }
        else
        {
            fmt::print("No counters there!\n");
        }
        exit(0);
    });

    auto result_code = parse_args(app, argc, argv);
    countit.serialize();
    return 0;
}