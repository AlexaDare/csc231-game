#include "move.h"

#include "closedoor.h"
#include "door.h"
#include "engine.h"
#include "entity.h"
#include "opendoor.h"
#include "tile.h"
#include "updatefov.h"


Move::Move(Vec movement)
    :movement{movement} {}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec new_position = entity->get_position() + movement;
    Tile& t = engine.dungeon.get_tile(new_position);
    if (t.is_wall() || t.has_entity()) {
        return failure(); // no moving into a wall or other entities
    }
    else if (t.has_door() && !t.door->is_open()) {
        t.door->open(); // open doors entity runs into
        // try using and getting return alternative(OpenDoor{t.door}) to work later
    }
    else { // must be an empty tile that we can move onto
        entity->change_direction(movement);
        entity->move_to(new_position);
        return success();
    }
}











// Results
    // You do not produce Results directly, use helper functions!
    // success()
    // Action worked, Entity finished with turn
    // failure()
    // Couldn't perform Action, give Entity another turn
    // alternative(AnotherAction{})
    // Couldn't perform Action, do this one instead!

    // If new position is wall
    // return failure()
    // If new position is door
    // return alternative(OpenDoor{})

// x, y direction
    // 1, 0 right
    //-1, 0 left
    // 0, 1 up
    // 0, -1 down
