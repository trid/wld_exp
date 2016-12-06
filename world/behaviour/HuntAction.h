//
// Created by dmitry.khovyakov on 12/6/2016.
//

#ifndef WLD_EXP_HUNTACTION_H
#define WLD_EXP_HUNTACTION_H

#include "Action.h"

namespace Behaviour {

class HuntAction: public Action {
public:
    void doAction(Agent &agent, World &world) override;
};

}


#endif //WLD_EXP_HUNTACTION_H
