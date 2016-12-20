//
// Created by dmitry.khovyakov on 12/20/2016.
//

#include "StateMoving.h"

void Behaviour::StateMoving::start(Agent &agent) {
    agent.moveToLocation(agent.getDestination());
}

void Behaviour::StateMoving::act(Agent &agent) {

}

bool Behaviour::StateMoving::isFinished(Agent &agent) {
    return agent.arrived();
}
