//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_LOCATION_H
#define WLD_EXP_LOCATION_H

#include <set>
#include <string>

namespace LocationNames{
    const std::string Home = "home";
    const std::string Well = "well";
    const std::string Forest = "forest";
}

class Location {
private:
    std::set<std::string> actions;

    int x;
    int y;
public:
    Location(int x, int y) : x(x), y(y) {}
    Location(Location&& location);

    void addActions(std::initializer_list<std::string> initializerList) {
        actions.insert(initializerList.begin(), initializerList.end());
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    const std::set<std::string> &getActions() const {
        return actions;
    }
};


#endif //WLD_EXP_LOCATION_H
