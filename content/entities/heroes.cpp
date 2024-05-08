#include "heroes.h"

#include "action.h" // include because of behavior
#include "closedoor.h"
#include "engine.h" // include because calling engine input
#include "move.h"
#include "rest.h" // include because including rest
//#include "vec.h"
#include "sword.h"

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero) { // making a wizard hero
        hero->set_sprite("wizard");
        hero->set_max_health(30); // setting health
        hero->add_to_inventory(std::make_shared<Sword>(5)); // put in parentheses how much damage it makes
        hero->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) { //added entity back 04.22.24
        std::string key = engine.input.get_last_keypress();
        if (key == "R") { // rest
            return std::make_unique<Rest>();
        }
        else if (key == "C") { // close door
            return std::make_unique<CloseDoor>();
        }
        else if (key == "Up" || key == "W") { // move up
            return std::make_unique<Move>(Vec{0, 1});
        }
//        else if (key == "Up" && key == "Left" || key == "W" && key == "A") { // move up and left
//            return std::make_unique<Move>(Vec{-1, 1}); // does not seem to work
//        }
        else if (key == "Left" || key == "A") { // move left
            return std::make_unique<Move>(Vec{-1, 0});
        }
        else if (key == "Down" || key == "S") { // move down
            return std::make_unique<Move>(Vec{0, -1});
        }
        else if (key == "Right" || key == "D") { // move right
            return std::make_unique<Move>(Vec{1, 0});
        }
        else if (!key.empty() && std::isdigit(key.at(0))){
            int item_num = std::stoi(key) - 1; // "1" -> index 0
            entity.select_item(item_num);
        }
        // when you say you are pointing to something, but do not allocate it, it will
        // crash, so add this to the end "return nullptr;"
        return nullptr;
    }
}

