//
// Created by anova on 4/15/2024.
//

#include "closedoor.h"
#include "entity.h"
#include "updatefov.h"

Result perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    engine.dungeon.neighbors(position); // neighbors lets know what tile is in each of the four directions
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed_any_doors{false};
    for (Vec neighbor : neighbors) {  // for each neighbor
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && tile.door->is_open()) {
            tile.door->close();
            closed_any_doors = true;
        }
    }

    if (closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure(); // do not lose our turn if no doors were around us
    }
}