//
// Created by anova on 4/15/2024.
//

#include "opendoor.h"

#include "action.h"
#include "door.h"
#include "engine.h"
#include "sound.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Door& door)
    :door{door} {}

Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity>) {
    door.open();
    engine.events.create_event<UpdateFOV>();
    engine.events.create_event<Sound>("door-open");
    return success();
}