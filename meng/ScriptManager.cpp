//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "ScriptManager.h"

MEng::ScriptManager::ScriptManager() {
    state = luaL_newstate();
}

void MEng::ScriptManager::loadFile(const std::string &path) {
    luaL_dofile(state, path.c_str());
}

void MEng::ScriptManager::registerFunction(const std::string &name, lua_CFunction func) {
    lua_register(state, name.c_str(), func);
}
