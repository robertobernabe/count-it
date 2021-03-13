#include <iostream>
#include <fmt/format.h>
#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <nlohmann/json.hpp>
#include <countit/countit.hpp>

#include "json_data.hpp"

int main(int argc, char **argv)
{

    CLI::App app{"countit\nA simple cli based tap counter"};
    std::string name = "default";
    app.add_option("name", name, "Counter name");
    
    CLI11_PARSE(app, argc, argv)

    auto c = CountIt(name);
    fmt::print("{}: {}", c.get_name(), c.get_count());

    return 0;
}