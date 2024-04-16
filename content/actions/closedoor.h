//
// Created by anova on 4/15/2024.
//

#pragma once

#include "action.h"
#include "engine.h"

class CloseDoor : public Action {
public:
//    CloseDoor(Vec position); no longer need
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

    // no longer need
//private:
//    Vec position;
};
