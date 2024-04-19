//
// Created by anova on 4/19/2024.
//

#include "sword.h"
#include "engine.h"
#include "hit.h"


Sword::Sword(int damage)
    :Item{"sword"}, damage{damage} {} // need to give it the name of the item

void Sword::use(Engine& engine, Entity& /*attacker*/, Entity& defender) { // not gonna hurt attacker
    engine.events.create_event<Hit>(defender, damage);
}