#include "wander.h"

#include "action.h"
#include "engine.h"
#include "entity.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"
#include "tile.h"
#include "vec.h"

Result Wander::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position(); // on slides
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);

    // randomizing which monster will go first
    shuffle(std::begin(neighbors), std::end(neighbors));

    // move onto empty floor tile that is found
    for (const Vec& neighbor : neighbors) {
        Tile& t = engine.dungeon.get_tile(neighbor);
        if (!t.is_wall() && !t.has_entity()) {
            Vec movement = neighbor - position;
            return alternative(Move{movement});
        }
    }

    return alternative(Rest{});
}