#include "staff.h"

#include "animation.h"
#include "hit.h"
#include "raise.h"

Staff::Staff (int damage)
    :Item{"staff_red"}, damage{damage} {}

void Staff::use(Engine& engine, Entity&, Entity& defender) {
    auto raise = engine.events.create_event<Raise>(sprite);
    std::shared_ptr<Event> fire = std::make_shared<Animation>("fire", defender.get_position());
    fire->add_next(Hit{defender, damage});
    raise->add_next(fire);
}

// basically copy of sword and shown in class - maybe not copied correctly :~(