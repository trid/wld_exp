//
// Created by dmitry.khovyakov on 11/29/2016.
//

#ifndef WLD_EXP_WORLDVIEW_H
#define WLD_EXP_WORLDVIEW_H

#include <vector>

#include "../../meng/view/View.h"
#include "AgentView.h"

class WorldState;

namespace View {

    class WorldView: public MEng::View::View {
    private:
        WorldState& worldState;
        std::vector<AgentViewPtr> agentViews;
    public:
        WorldView(WorldState &worldState);

        void draw() override;
    };

}

#endif //WLD_EXP_WORLDVIEW_H
