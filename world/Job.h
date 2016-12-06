//
// Created by dmitry.khovyakov on 12/6/2016.
//

#ifndef WLD_EXP_JOB_H
#define WLD_EXP_JOB_H


#include <memory>

class Job {
public:
    virtual void update(int timeDelta) = 0;
};

using JobPtr = std::unique_ptr<Job>;

#endif //WLD_EXP_JOB_H
