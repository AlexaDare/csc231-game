#pragma once

#include "action.h"
#include "entity.h"
#include "vec.h"

class Move : public Action {
public:
    Move(Vec movement);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
private:
    Vec movement;
};