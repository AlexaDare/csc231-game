#include "hit.h"
#include "entity.h"
#include "die.h"

Hit::Hit(Entity& entity, int damage)
    :entity{entity}, damage{damage} {}


void Hit::execute(Engine& /*engine*/) { // can get rid of because not used
    entity.take_damage(damage); // reduce health
}

void Hit::when_done(Engine& /*engine*/) { // same as above, because do not need access
    if (!entity.is_alive()) {
        add_next(Die{entity}); // remove from game
    }
}
