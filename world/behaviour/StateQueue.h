//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_STATEQUEUE_H
#define WLD_EXP_STATEQUEUE_H

#include "State.h"

namespace Behaviour {

    class StateQueue : public State {
    public:
        void act(Agent &agent) override;
    };

}

#endif //WLD_EXP_STATEQUEUE_H
