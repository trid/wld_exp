//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_STATEQUEUE_H
#define WLD_EXP_STATEQUEUE_H

#include "State.h"

namespace Behaviour {

    class StateQueue : public State {
    private:
        using StatesList = std::vector<std::string>;
    public:
        StateQueue(StatesList::iterator begin, StatesList::iterator end) {};

        void act(Agent &agent) override;

        void start(Agent& agent) override;

        bool isFinished() override;
    };

}

#endif //WLD_EXP_STATEQUEUE_H
