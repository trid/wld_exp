//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "Location.h"

Location::Location(Location &&location) {
    x = location.x;
    y = location.y;

    actions = std::move(location.actions);
}
