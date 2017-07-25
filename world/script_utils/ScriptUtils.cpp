//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "ScriptUtils.h"
#include "../behaviour/StateStorage.h"
#include "../behaviour/ScriptedState.h"
#include "../behaviour/StateQueue.h"

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

    int act(lua_State* state) {
        const char* action = lua_tostring(state, -2);
        Agent* agent = (Agent *) lua_topointer(state, -1);

        agent->doAction(action);
        return 0;
    }

    int createStateQueue(lua_State* state) {
        auto len = luaL_len(state, -1);

        std::vector<std::string> v;

        for (int i = 0; i < len; i++) {
            lua_pushnumber(state, i);
            lua_gettable(state, -2);
            const char* s = lua_tostring(state, -1);
            v.push_back(std::string(s));
            lua_pop(state, 2);
        }

        Agent* agent = (Agent *) lua_topointer(state, -2);
        agent->setState(std::make_shared<Behaviour::StateQueue>(v.begin(), v.end()));

        return 0;
    }
}