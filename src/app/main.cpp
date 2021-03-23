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
#include <countit/version.hpp>

using namespace robertobernabe::countit;

int parse_args(CLI::App& app, int argc, char** argv)
{
    CLI11_PARSE(app, argc, argv)
}

int main(int argc, char** argv)
{
    System::set_locale_utf8();
    std::string app_version = fmt::format("countit {}", VERSION);
    std::string app_desc = fmt::format("{}\nA simple cli based tap counter", app_version);
    std::string name = "default";
    bool show_version = false;
    CLI::App app{ app_desc };
    auto countit = CountIt();
    app.add_flag("--version,-v", show_version, "Show version and exit.");
    auto add = app.add_subcommand("add", "Increment count of given counter");
    auto list = app.add_subcommand("list", "List and show specific counter");
    auto reset = app.add_subcommand("reset", "Reset a specific counter");
    auto remove = app.add_subcommand("remove", "Remove a specific counter");

    add->add_option("name", name, "Counter name");
    reset->add_option("name", name, "Counter name");
    remove->add_option("name", name, "Counter name");

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
    reset->callback([&]() {
        countit.deserialize();
        countit.reset_counter(name);
    });
    remove->callback([&]() {
        countit.deserialize();
        countit.remove_counter(name);
    });

    auto result_code = parse_args(app, argc, argv);
    if (show_version)
    {
        fmt::print("{}\n", app_version);
        exit(0);
    }

    countit.serialize();
    return 0;
}