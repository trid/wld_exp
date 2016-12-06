//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_WORLD_H
#define WLD_EXP_WORLD_H

#include <string>
#include <unordered_map>
#include <vector>

#include "Location.h"
#include "Agent.h"

#include "behaviour/Action.h"
#include "Job.h"

class World {
private:
    std::unordered_map<std::string, Location> locations;
    std::unordered_map<std::string, Behaviour::ActionPtr> actions;
    std::vector<Agent> agents;
    std::vector<JobPtr> jobs;

    void addAgent(const std::string& path);
public:
    World();

    Location& getLocation(const std::string &name);

    bool doAction(Agent& actor, const std::string& action);
    void update(int timeDelta);

    const std::vector<Agent> &getAgents() const;

    void refillFood(Agent& agent);
    void refillWater(Agent& agent);
};


#endif //WLD_EXP_WORLD_H
