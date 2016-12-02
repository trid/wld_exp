//
// Created by dmitry.khovyakov on 12/1/2016.
//

#ifndef WLD_EXP_SCREEPTUTILS_H
#define WLD_EXP_SCREEPTUTILS_H

#include <lua/lua.hpp>

namespace ScriptUtils {
int print(lua_State* luaState);
int registerState(lua_State* luaState);
}

#endif //WLD_EXP_SCREEPTUTILS_H
