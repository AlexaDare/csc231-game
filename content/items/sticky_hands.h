#pragma once

#include "item.h"

class StickyHands : public Item {
public:
    explicit StickyHands();
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

protected:
    int damage;
};