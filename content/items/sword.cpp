#include "sword.h"

#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"

Sword::Sword(int damage)
    :Item{"sword"}, damage{damage} {} // need to give it the name of the item

void Sword::use(Engine& engine, Entity& attacker, Entity& defender) { // not gonna hurt attacker // added attacker back 04/22/24
    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}