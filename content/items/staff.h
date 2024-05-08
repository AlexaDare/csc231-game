#pragma once

#include "item.h"

class Staff : public Item {
public:
    explicit Staff(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};