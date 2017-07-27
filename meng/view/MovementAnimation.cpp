//
// Created by TriD on 04.08.2015.
//

#include "MovementAnimation.h"
#include "../MessageManager.h"

using namespace MEng::View;

void MovementAnimation::update(int delta) {
    passed += delta;
    if (passed < time) {
        Point newPosition;
        newPosition.x = begin.x + distance.x * passed / time;
        newPosition.y = begin.y + distance.y * passed / time;
        image->setPosition(newPosition.asVector2f());
    }
}

bool MovementAnimation::isFinished() {
    return passed >= time;
}

void MovementAnimation::finalize() {
    image->setPosition(target.asVector2f());
    MEng::MessageParameters parameters;
    MEng::MessageManager::getInstance().enqueuMessage("movement_animation_finished", parameters);
}
