#pragma once

#include "action.h"

class Attack : public Action {
public:
    // constructor for attack intakes the defender
    explicit Attack(Entity& defender);
    // attacker uses current item on defender
    Result perform(Engine& engine, std::shared_ptr<Entity> attacker) override;

private:
    Entity& defender;
};