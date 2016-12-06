//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "Agent.h"

#include "behaviour/State.h"

void Agent::update(int timeDelta) {
    if (state) {
        state->act(*this);
    }
    updTime += timeDelta;
    if (updTime >= 1000) {
        food -= foodConsumption;
        water -= waterConsumption;

        if (food < 25) {
            addStatus("hungry");
        }
        if (water < 25) {
            addStatus("thirsty");
        }
    }
}

void Agent::addStatus(const std::string &status) {
    if (statuses.find(status) == statuses.end()) {
        auto s = statuses.insert(status);

        if (currentStatus.get() != noStatus && reactions.find(status) != reactions.end()) {
            currentStatus = *s.first;

            if (state->getSuspendType() == Behaviour::SuspendType::Save || state->getSuspendType() == Behaviour::SuspendType::Reset) {
                suspendedBehaviours.push(state);
            }

            state = reactions[status];
        }
    }
}

float Agent::getX() const {
    return x;
}

float Agent::getY() const {
    return y;
}

Agent::Agent(World &world) : currentStatus(noStatus), world(world) {

}

bool Agent::isWorking() const {
    return working;
}

const std::string &Agent::getWorkType() const {
    return workType;
}

void Agent::addItems(const std::string &type, int count) {
    if (itemsType != type) {
        items = 0;
    }
    items += count;
}