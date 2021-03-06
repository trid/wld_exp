//
// Created by dmitry.khovyakov on 12/1/2016.
//

#ifndef WLD_EXP_SCRIPTEDSTATE_H
#define WLD_EXP_SCRIPTEDSTATE_H

#include "State.h"

namespace Behaviour {

class ScriptedState: public State {
private:
    std::string tableName;

public:
    ScriptedState(const std::string &tableName);

    void act(Agent &agent) override;

    void start(Agent& agent) override;

    bool isFinished() override;
};

}


#endif //WLD_EXP_SCRIPTEDSTATE_H
