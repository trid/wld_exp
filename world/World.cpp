//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "World.h"
#include "behaviour/StateStorage.h"
#include "behaviour/CutWoodAction.h"
#include "behaviour/DrinkAction.h"
#include "behaviour/EatAction.h"
#include "behaviour/HuntAction.h"

#include <cmath>

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::filesystem;

void World::update(int timeDelta) {
    for (auto& agent: agents) {
        agent.update(timeDelta);
    }

    for (auto& job: jobs) {
        job->update(timeDelta);
    }
}

bool World::doAction(Agent &actor, const std::string &action) {
    const std::set<std::string> &actions = locations.at(actor.location).getActions();
    if (actions.find(action) != actions.end()){

    }
    else {
        return false;
    }
}

World::World() {
    locations.emplace(std::piecewise_construct, std::forward_as_tuple("forest"), std::forward_as_tuple(250, 0));
    locations.at("forest").addActions({"hunt", "cut_wood"});
    locations.emplace(std::piecewise_construct, std::forward_as_tuple("home"), std::forward_as_tuple(230, 400));
    locations.at("home").addActions({"eat"});
    locations.emplace(std::piecewise_construct, std::forward_as_tuple("well"), std::forward_as_tuple(20, 200));
    locations.at("well").addActions({"drink"});

    path p("res/agents");
    for (directory_entry &x: directory_iterator(p)) {
        addAgent(x.path().string());
    }

    actions.emplace(std::make_pair(Behaviour::ActionTypes::CutWood, std::make_unique<Behaviour::CutWoodAction>()));
    actions.emplace(std::make_pair(Behaviour::ActionTypes::Drink, std::make_unique<Behaviour::DrinkAction>()));
    actions.emplace(std::make_pair(Behaviour::ActionTypes::Eat, std::make_unique<Behaviour::EatAction>()));
    actions.emplace(std::make_pair(Behaviour::ActionTypes::Hunt, std::make_unique<Behaviour::HuntAction>()));
}

void World::addAgent(const std::string &path) {
    agents.emplace_back(*this);
    auto& agent = agents.back();

    boost::property_tree::ptree pt;
    boost::property_tree::read_json(path, pt);

    agent.name = pt.get<std::string>("name");
    agent.maxWeight = pt.get<int>("maxWeight");
    agent.foodConsumption = pt.get<float>("foodConsumption");
    agent.waterConsumption = pt.get<float>("waterConsumption");

    agent.x = locations.at("home").getX();
    agent.y = locations.at("home").getY();

    agent.speed = pt.get<float>("speed", 10.f);

    agent.onIdle = Behaviour::StateStorage::getInstance().getState(pt.get<std::string>("onIdle"));
}

Location &World::getLocation(const std::string &name) {
    return locations.at(name);
}

const std::vector<Agent> &World::getAgents() const {
    return agents;
}

void World::refillFood(Agent &agent) {
    agent.food = 100;
}

void World::refillWater(Agent &agent) {
    agent.water = 100;
}

void World::addJob(JobPtr &&job) {
    jobs.push_back(std::move(job));
}

void World::moveToLocation(Agent& agent, const std::string& locationName) {
    Location& loc = locations.at(locationName);
    float agentX = agent.getX();
    float agentY = agent.getY();
    float locationX = loc.getX();
    float locationY = loc.getY();

    float dist = sqrtf((locationX - agentX) * (locationX - agentX) + (locationY - agentY) * (locationY - agentY));
    float agentXN = agentX / dist;
    float agentYN = agentY / dist;

    agent.dx = agent.speed * agentXN;
    agent.dy = agent.speed * agentYN;
}

bool World::isOnLocation(Agent& agent, const ::std::string& locationName) {
    auto& loc = locations.at(locationName);
    float agentX = agent.getX();
    float agentY = agent.getY();

    if (loc.getX() > agentX || agentX > loc.getX() + 32) return false;
    if (loc.getY() < agentY || agentY > loc.getY() + 32) return false;

    return true;
}
