//
// Created by dmitry.khovyakov on 12/1/2016.
//

#ifndef WLD_EXP_SCREEPTUTILS_H
#define WLD_EXP_SCREEPTUTILS_H

#include <lua/lua.hpp>

namespace ScriptUtils {

// General functions
int print(lua_State* luaState);

// State control functions
int registerState(lua_State* luaState);
int createStateQueue(lua_State* state);

// Agent actions
int act(lua_State* luaState);

}

#endif //WLD_EXP_SCREEPTUTILS_H
