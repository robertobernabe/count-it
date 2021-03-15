#include <iostream>
#include <vector>
#include <fmt/format.h>
#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <nlohmann/json.hpp>
#include <countit/countit.hpp>

#include "json_data.hpp"

int main(int argc, char** argv)
{
    CLI::App app{ "countit\nA simple cli based tap counter" };
    std::string name = "default";
    app.add_option("name", name, "Counter name");

    CLI11_PARSE(app, argc, argv)
    auto list = std::vector<robertobernabe::countit::CountIt>();
    auto c = robertobernabe::countit::CountIt(name);
    fmt::print("{}: {}\n", c.get_name(), c.get_count());
    list.push_back(c);

    nlohmann::json j = list;
    std::cout << "json: " << j << std::endl;
    // auto c2 = j.get<robertobernabe::countit::CountIt>();
    // fmt::print("{}: {}\n", c2.get_name(), c2.get_count());
    return 0;
}