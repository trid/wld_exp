//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "World.h"

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::filesystem;

void World::update(int timeDelta) {

}

bool World::doAction(Agent &actor, const std::string &action) {
    return false;
}

World::World() {
    locations.emplace(std::piecewise_construct, std::forward_as_tuple("forest"), std::forward_as_tuple(250, 0));
    locations.at("forest").addActions({"hunt", "cut_wood"});
    locations.emplace(std::piecewise_construct, std::forward_as_tuple("home"), std::forward_as_tuple(230, 400));
    locations.at("home").addActions({"eat"});
    locations.emplace(std::piecewise_construct, std::forward_as_tuple("well"), std::forward_as_tuple(20, 200));
    locations.at("well").addActions({"drink"});

    boost::filesystem::path p("res/agents");
    for (directory_entry &x: directory_iterator(p)) {
        addAgent(x.path().string());
    }
}

void World::addAgent(const std::string &path) {
    agents.emplace_back();
    auto& agent = agents.back();

    boost::property_tree::ptree pt;
    boost::property_tree::read_json(path, pt);

    agent.name = pt.get<std::string>("name");
    agent.maxWeight = pt.get<int>("maxWeight");
    agent.foodConsumption = pt.get<float>("foodConsumption");
    agent.waterConsumption = pt.get<float>("waterConsumption");

    agent.x = locations.at("home").getX();
    agent.y = locations.at("home").getY();
}

Location &World::getLocation(const std::string &name) {
    return locations.at(name);
}

const std::vector<Agent> &World::getAgents() const {
    return agents;
}
