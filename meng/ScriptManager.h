//
// Created by dmitry.khovyakov on 12/1/2016.
//

#ifndef WLD_EXP_SCRIPTMANAGER_H
#define WLD_EXP_SCRIPTMANAGER_H

#include "utils/Singleton.h"

#include <string>

#include <lua/lua.hpp>

namespace MEng {

class ScriptManager: public MEng::Utils::Singleton<ScriptManager> {
private:
    lua_State* state;
public:
    ScriptManager();

    void loadFile(const std::string& path);
    void registerFunction(const std::string &name, lua_CFunction func);
};

}

#endif //WLD_EXP_SCRIPTMANAGER_H
