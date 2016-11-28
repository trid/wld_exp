//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_STATE_H
#define WLD_EXP_STATE_H

#include "memory"
#include "view/View.h"

namespace MEng {

    class State {
    protected:
        View::ViewPtr viewPtr;
    public:
        virtual void update(int timeDelta) = 0;
    };

    using StatePtr = std::shared_ptr<State>;
}

#endif //WLD_EXP_STATE_H
