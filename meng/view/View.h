//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_VIEW_H
#define WLD_EXP_VIEW_H

#include <functional>
#include <memory>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

namespace MEng {
namespace View {

    using DrawablePtr = std::shared_ptr<sf::Drawable>;

    class View {
    private:
        std::vector<DrawablePtr> sprites;
    public:
        virtual void draw();
        void addDrawable(DrawablePtr drawablePtr);
    };

    using ViewPtr = std::shared_ptr<View>;
}}
#endif //WLD_EXP_VIEW_H
