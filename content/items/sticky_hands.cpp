#include "sticky_hands.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "steal.h"
#include "vec.h"

StickyHands::StickyHands() // empty because 0 damage
    :Item{"sticky_hands"}, damage{1}{} // create an empty png part to name sticky_hands in items.txt

void StickyHands::use(Engine& engine, Entity& attacker, Entity& defender) {
    std::shared_ptr<Event> hit = engine.events.create_event<Hit>(defender, damage);
    hit->add_next(Steal{attacker, defender});
    defender.remove_item(defender.get_current_item_index());

//    std::shared_ptr<Event> steal = engine.events.create_event<Steal>(attacker, defender);
//    steal->add_next(Hit{defender, damage});

    //    engine.events.create_event<Hit>(defender, damage);
    //    engine.events.create_event<Steal>(attacker, defender);
}