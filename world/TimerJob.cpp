//
// Created by dmitry.khovyakov on 12/6/2016.
//

#include "TimerJob.h"

void TimerJob::update(int timeDelta) {
    currentTime += timeDelta;
    if (currentTime <= timer) {
        updateFunction(agent, world);
    }
}

TimerJob::TimerJob(int timer, const std::function<void(Agent &, World &)> &updateFunction, Agent &agent, World &world)
        : timer(timer), updateFunction(updateFunction), agent(agent), world(world) {}

