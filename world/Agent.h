//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_AGENT_H
#define WLD_EXP_AGENT_H


#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

const std::string noStatus = "";

namespace Behaviour {
    class State;
    using StatePtr = std::shared_ptr<State>;
}

class Agent {
    friend class World;
private:
    float food;
    float water;
    int items;
    int maxWeight;
    float foodConsumption;
    float waterConsumption;

    std::string name;

    Behaviour::StatePtr state;
    std::unordered_set<std::string> statuses;
    std::reference_wrapper<const std::string> currentStatus;

    int updTime = 0;

    std::unordered_map<std::string, Behaviour::StatePtr> reactions;

    void addStatus(const std::string& status);
public:

    void update(int timeDelta);
};


#endif //WLD_EXP_AGENT_H
