#pragma once
#include <nlohmann/json.hpp>
#include <countit/countit.hpp>

namespace robertobernabe::countit
{
    void to_json(nlohmann::json& j, const TapCounter& c)
    {
        j = nlohmann::json{ { "name", c.get_name() }, { "count", c.get_count() } };
    }

    void from_json(const nlohmann::json& j, TapCounter& c)
    {
        c.set_name(j.at("name").get<std::string>());
        c.set_count(j.at("count").get<int>());
    }

}    // namespace ns