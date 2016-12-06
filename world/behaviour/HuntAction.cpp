//
// Created by dmitry.khovyakov on 12/6/2016.
//

#include "HuntAction.h"

#include "../TimerJob.h"
#include "../World.h"

void Behaviour::HuntAction::doAction(Agent &agent, World &world) {
    auto cutWoodFunction = [](Agent& ag, World&) {
        ag.addItems(ItemTypes::Food, 1);
    };

    world.addJob(std::make_unique<TimerJob>(1000, cutWoodFunction, agent, world));
}
