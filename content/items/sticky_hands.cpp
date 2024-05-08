#include "sticky_hands.h"

#include "engine.h"
#include "entity.h"
#include "steal.h"

StickyHands::StickyHands() // empty because 0 damage
    :Item{"sticky_hands"}, damage{0}{} // create an empty png part to name sticky_hands in items.txt

void StickyHands::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Steal>(attacker, defender);
}