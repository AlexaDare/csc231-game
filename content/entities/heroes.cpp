#include "heroes.h"

#include "action.h" // include because of behavior
#include "closedoor.h"
#include "engine.h" // include because calling engine input
#include "move.h"
#include "rest.h" // include because including rest
//#include "vec.h"

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("wizard");
        hero->set_max_health(10);
        //        hero->behavior = behavior; // not yet 04/08/2024
        hero->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& /*entity*/) {
        std::string key = engine.input.get_last_keypress();
        if (key == "R") {
            return std::make_unique<Rest>();
        }
        else if (key == "C") {
            return std::make_unique<CloseDoor>();
        }
        else if (key == "Up" || key == "W") {
            return std::make_unique<Move>(Vec{0, 1});
        }
        else if (key == "Left" || key == "A") {
            return std::make_unique<Move>(Vec{-1, 0});
        }
        else if (key == "Down" || key == "S") {
            return std::make_unique<Move>(Vec{0, -1});
        }
        else if (key == "Right" || key == "D") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        // when you say you are pointing to something, but do not allocate it, it will
        // crash, so add this to the end "return nullptr;"
        return nullptr;
    }
}

