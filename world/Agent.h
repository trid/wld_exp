//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_AGENT_H
#define WLD_EXP_AGENT_H


#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

class World;

const std::string noStatus = "";

namespace Behaviour {
    class State;
    using StatePtr = std::shared_ptr<State>;
}

namespace ItemTypes {
    const std::string Wood = "wood";
    const std::string Food = "food";
}

namespace ReactionType {
    const std::string Hungry = "hungry";
    const std::string Thirsty = "thirsty";
}

class Agent {
    friend class World;
private:
    float food{100};
    float water{100};
    int items;
    int maxWeight;
    float foodConsumption;
    float waterConsumption;

    float x;
    float y;
    float dx{0.0f};
    float dy{0.0f};
    float speed;

    bool working;
    std::string workType;

    std::string itemsType;

    std::string name;
    std::string location;
    std::string destination;

    World& world;

    Behaviour::StatePtr state;
    Behaviour::StatePtr onIdle;

    std::queue<Behaviour::StatePtr> suspendedBehaviours;

    std::unordered_set<std::string> statuses;
    std::reference_wrapper<const std::string> currentStatus;

    int updTime = 0;

    std::unordered_map<std::string, Behaviour::StatePtr> reactions;

    void addStatus(const std::string& status);
public:
    Agent(World &world);

    void update(int timeDelta);

    float getX() const;
    float getY() const;

    bool isMoving() { return dx != 0.0f || dy != 0.0f; }


    bool isWorking() const;

    void addItems(const std::string& type, int count);

    const std::string &getWorkType() const;

    void doAction(const std::string& action);

    void setState(Behaviour::StatePtr state) { this->state = state; }

    void moveToLocation(const std::string& location);

    const std::string &getDestination() const { return destination; }
    void setDestination(const std::string &destination);

    bool arrived();
};


#endif //WLD_EXP_AGENT_H
