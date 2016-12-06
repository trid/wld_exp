//
// Created by dmitry.khovyakov on 12/6/2016.
//

#include "DrinkAction.h"

#include "../World.h"

void Behaviour::DrinkAction::doAction(Agent &agent, World &world) {
    world.refillWater(agent);
}
