//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_VIEW_H
#define WLD_EXP_VIEW_H

#include <memory>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

namespace MEng {
namespace View {


    class View {
    private:
        std::vector<sf::Sprite> sprites;
    public:
        virtual void draw();
    };

    using ViewPtr = std::shared_ptr<View>;
}}
#endif //WLD_EXP_VIEW_H
