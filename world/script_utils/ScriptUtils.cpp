//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "ScriptUtils.h"
#include "../behaviour/StateStorage.h"
#include "../behaviour/ScriptedState.h"

#include <iostream>

namespace ScriptUtils {

    int print(lua_State* state) {
        char const *str = lua_tostring(state, 1);
        std::cout << "LUA: " << str;
        return 0;
    }

    int registerState(lua_State* state) {
        const char* stateName = lua_tostring(state, -2);
        const char* tableName = lua_tostring(state, -1);

        Behaviour::StateStorage::getInstance().addState(stateName, std::make_shared<Behaviour::ScriptedState>(std::string(tableName)));
        return 0;
    }
}