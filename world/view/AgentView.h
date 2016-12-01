//
// Created by dmitry.khovyakov on 12/1/2016.
//

#ifndef WLD_EXP_AGENTVIEW_H
#define WLD_EXP_AGENTVIEW_H

#include <memory>
#include <sfml/Graphics.hpp>

class Agent;

namespace View {

class AgentView: public sf::Drawable {
private:
    const Agent& agent;

    sf::Sprite sprite;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    AgentView(const Agent &agent);

    void updatePosition();
};

using AgentViewPtr = std::shared_ptr<AgentView>;
}

#endif //WLD_EXP_AGENTVIEW_H
