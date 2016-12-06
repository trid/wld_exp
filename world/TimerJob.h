//
// Created by dmitry.khovyakov on 12/6/2016.
//

#ifndef WLD_EXP_TIMERJOB_H
#define WLD_EXP_TIMERJOB_H

#include <functional>

#include "Job.h"

class Agent;
class World;

class TimerJob: public Job {
private:
    int timer;
    std::function<void(Agent&, World&)> updateFunction;
    Agent& agent;
    World& world;

    int currentTime;
public:
    TimerJob(int timer, const std::function<void(Agent &, World &)> &updateFunction, Agent &agent, World &world);

    void update(int timeDelta) override;
};


#endif //WLD_EXP_TIMERJOB_H
