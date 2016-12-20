//
// Created by dmitry.khovyakov on 12/20/2016.
//

#ifndef WLD_EXP_STATEMOVING_H
#define WLD_EXP_STATEMOVING_H

#include "State.h"

namespace Behaviour {

class StateMoving: public State {
public:
    void start(Agent &agent) override;

    void act(Agent &agent) override;

    bool isFinished(Agent &agent) override;
};

}


#endif //WLD_EXP_STATEMOVING_H
