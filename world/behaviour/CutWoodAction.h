//
// Created by dmitry.khovyakov on 12/6/2016.
//

#ifndef WLD_EXP_CUTWOODACTION_H
#define WLD_EXP_CUTWOODACTION_H

#include "Action.h"

namespace Behaviour {

class CutWoodAction: public Action {
public:
    void doAction(Agent &agent, World &world) override;
};

}

#endif //WLD_EXP_CUTWOODACTION_H
