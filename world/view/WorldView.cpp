//
// Created by dmitry.khovyakov on 11/29/2016.
//

#include "WorldView.h"
#include "view/TextureManager.h"
#include "../WorldState.h"

View::WorldView::WorldView(WorldState &worldState):
worldState(worldState)
{
    MEng::View::TextureManager &textureManager = MEng::View::TextureManager::getInstance();
    World &world = worldState.getWorld();

    auto& texture = textureManager.getTexture("res/img/grass.jpg");
    auto background = std::make_shared<sf::Sprite>();
    background->setTexture(texture);

    addDrawable(background);

    auto& homeTexture = textureManager.getTexture("res/img/home.png");
    auto& forestTexture = textureManager.getTexture("res/img/trees.png");
    auto& wellTexture = textureManager.getTexture("res/img/well.png");

    auto locationSprite = std::make_shared<sf::Sprite>();
    locationSprite->setTexture(homeTexture);
    Location& home = world.getLocation("home");
    locationSprite->setPosition(home.getX(), home.getY());
    addDrawable(locationSprite);

    locationSprite = std::make_shared<sf::Sprite>();
    Location& forest = world.getLocation("forest");
    locationSprite->setTexture(forestTexture);
    locationSprite->setPosition(forest.getX(), forest.getY());
    addDrawable(locationSprite);

    locationSprite = std::make_shared<sf::Sprite>();
    Location& well = world.getLocation("well");
    locationSprite->setTexture(wellTexture);
    locationSprite->setPosition(well.getX(), well.getY());
    addDrawable(locationSprite);

    for (auto& item: world.getAgents()) {
        std::shared_ptr<AgentView> ptr = std::make_shared<AgentView>(item);
        agentViews.push_back(ptr);
        addDrawable(ptr);
    }
}

void View::WorldView::draw() {
    for (auto item: agentViews) {
        item->updatePosition();
    }

    MEng::View::View::draw();
}
