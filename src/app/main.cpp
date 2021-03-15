#include <iostream>
#include <vector>
#include <fmt/format.h>
#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <nlohmann/json.hpp>

#include <countit/countit.hpp>

using namespace robertobernabe::countit;

void configure_parser(CLI::App& app, CountIt& countit)
{
    std::string name = "default";
    app.add_option("name", name, "Counter name");

    auto list_callback = [&](int count) {
        for (auto c : countit.get_all_counters())
        {
            fmt::print("{}: {}\n", c.get_name(), c.get_count());
        }
    };

    auto flag_list = app.add_flag("--list", list_callback, "List all available counters");
}

int parse_args(CLI::App& app, int argc, char** argv)
{
    CLI11_PARSE(app, argc, argv)
}

int main(int argc, char** argv)
{
    CLI::App app{ "countit\nA simple cli based tap counter" };
    auto countit = CountIt();
    countit.add_counter();
    configure_parser(app, countit);
    parse_args(app, argc, argv);

    countit.serialize();
    return 0;
}