//
// Created by anova on 4/15/2024.
//

#pragma once

#include "action.h"
#include "door.h"
#include "engine.h"
#include "entity.h"

//forward declaration
class Door;

class OpenDoor : public Action {
public:
    OpenDoor(Door& door);
    Result perform(Engine& engine, std::shared_ptr<Entity>) override;
private:
    Door& door;
};