//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include <view/TextureManager.h>
#include "AgentView.h"
#include "../Agent.h"

void View::AgentView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

View::AgentView::AgentView(const Agent &agent) : agent(agent) {
    sf::Texture& texture = MEng::View::TextureManager::getInstance().getTexture("res/img/actor.png");
    sprite.setTexture(texture);
}

void View::AgentView::updatePosition() {
    sprite.setPosition(agent.getX(), agent.getY());
}
