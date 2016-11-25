//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_APPLICATION_H
#define WLD_EXP_APPLICATION_H

#include <vector>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "utils/Singleton.h"
#include "State.h"

namespace MEng {

    using States = std::vector<StatePtr>;

    class Application: public Utils::Singleton<Application> {
    private:
        States states;

        sf::Clock clock;
    public:
        void run();

        void pushState(StatePtr state);
    };

}

#endif //WLD_EXP_APPLICATION_H
