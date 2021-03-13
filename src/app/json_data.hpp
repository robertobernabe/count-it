#pragma once
#include <nlohmann/json.hpp>
#include <countit/countit.hpp>

namespace robertobernabe::countit
{
    void to_json(nlohmann::json &j, const CountIt &c)
    {
        j["name"] = c.get_name();
        //j = nlohmann::json{{"name", c.get_name()}, {"count", c.get_count()}};
    }

    void from_json(const nlohmann::json &j, CountIt &c)
    {
        //j.at("name").get_to(c.set_name);
        //j.at("count").get_to(c.set_count);
    }
} // namespace ns