//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_WORLDSTATE_H
#define WLD_EXP_WORLDSTATE_H


#include "../meng/State.h"
#include "World.h"

class WorldState: public MEng::State {
private:
    World world;

    void registerScripts();
public:
    WorldState();

    World &getWorld();

    void update(int timeDelta) override;
};


#endif //WLD_EXP_WORLDSTATE_H
