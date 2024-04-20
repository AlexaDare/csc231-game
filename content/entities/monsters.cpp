#include "monsters.h"

#include "action.h"
#include "closedoor.h"
#include "engine.h"
#include "entity.h"
#include "move.h"
#include "opendoor.h"
#include "randomness.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {
    void make_demon_tiny(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("demon_tiny");
        monster->set_max_health(10);
        monster->behavior = behavior;
    }

    void make_masked_orc(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("masked_orc");
        monster->set_max_health(10);
        monster->behavior = behavior;
    }

    void make_muddy(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("muddy");
        monster->set_max_health(5);
        monster->behavior = behavior;
    }

    void make_orc_shaman(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("orc_shaman");
        monster->set_max_health(15);
        monster->behavior = behavior;
    }

    void make_skeleton(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("skeleton");
        monster->set_max_health(10);
        monster->behavior = behavior;
    }

    void make_wizard(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("wizard");
        monster->set_max_health(20);
        monster->behavior = behavior; // they are gonna steal your weapons
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        // hero in sight, so monster will follow
        if (entity.is_visible() && engine.hero) {
            auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                      engine.hero->get_position());
            if (path.size() > 1) {
                auto movement = path.at(1) - path.at(0);
                return std::make_unique<Move>(movement);
            }
        }
        // hero out of sight
        else if (probability(70)) { // more likely to wander than 66
            return std::make_unique<Wander>();
        }
        // rest if not wandering
        else {
            return std::make_unique<Rest>();
        }
    }
}