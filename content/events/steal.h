#pragma once

#include "engine.h"
#include "entity.h"

class Steal : public Event {
public:
    Steal(Entity& attacker, Entity& defender);
    void execute(Engine& engine) override;

protected:
    Entity& attacker, defender;
};
