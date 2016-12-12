//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_STATE_H
#define WLD_EXP_STATE_H

#include <memory>

#include "../Agent.h"

namespace Behaviour {

    enum class SuspendType {
        End = 0,
        Save,
        Reset,
        NonSuspendable
    };

    class State {
    public:
        virtual void act(Agent& agent) = 0;
        virtual SuspendType getSuspendType() { return SuspendType::Save; }
        virtual bool isFinished() = 0;
    };

    using StatePtr = std::shared_ptr<State>;
}

#endif //WLD_EXP_STATE_H
