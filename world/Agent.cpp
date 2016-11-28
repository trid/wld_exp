//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "Agent.h"

void Agent::update(int timeDelta) {
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
            state = reactions[status];
        }
    }
}
