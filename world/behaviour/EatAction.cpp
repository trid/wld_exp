//
// Created by dmitry.khovyakov on 12/6/2016.
//

#include "EatAction.h"

#include "../World.h"

void Behaviour::EatAction::doAction(Agent &agent, World &world) {
    world.refillFood(agent);
}
