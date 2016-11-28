//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_WORLD_H
#define WLD_EXP_WORLD_H

#include <string>
#include <unordered_map>
#include "Location.h"
#include "Agent.h"

class World {
private:
    std::unordered_map<std::string, Location> locations;

    void update(int timeDelta);

public:
    World();

    bool doAction(Agent& actor, const std::string& action);
};


#endif //WLD_EXP_WORLD_H
