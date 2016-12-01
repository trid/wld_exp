//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "ScreeptUtils.h"

#include <iostream>

namespace ScriptUtils {

    int print(lua_State* state) {
        char const *str = lua_tostring(state, 1);
        std::cout << "LUA: " << str;
        return 0;
    }

}