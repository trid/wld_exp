//
// Created by dmitry.khovyakov on 11/25/2016.
//

#ifndef WLD_EXP_SINGLETON_H
#define WLD_EXP_SINGLETON_H

namespace MEng {
namespace Utils {

template<typename T>
class Singleton {
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }
};

}}

#endif //WLD_EXP_SINGLETON_H
