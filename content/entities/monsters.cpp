#include "monsters.h"

#include "action.h"
#include "closedoor.h"
#include "engine.h"
#include "entity.h"
#include "move.h"
#include "opendoor.h"
#include "randomness.h"
#include "rest.h"
#include "steal.h"
#include "sticky_hands.h"
#include "tile.h"
#include "vec.h"
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

    // making thieving wizard that matches the hero
    void make_wizard(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("wizard");
        monster->set_max_health(20);
        monster->add_to_inventory(std::make_shared<StickyHands>()); // giving sticky hands
        monster->behavior = steal_behavior; // they are going to steal the hero's current weapon
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
        return nullptr; // added 05.01.2024
    }

    std::unique_ptr<Action> steal_behavior(Engine& engine, Entity& entity) {
        // hero in sight, run to hero and steals
        if (entity.is_visible() && engine.hero && !engine.hero->stolen) { // add not_stolen to hero - check
            auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                      engine.hero->get_position());
            if (path.size() > 1) {
                auto movement = path.at(1) - path.at(0);
                return std::make_unique<Move>(movement);
            } else {
                engine.hero->stolen = true;
            }
        }
        // runs away with item even when hero is visible
        else if (entity.is_visible() && engine.hero && engine.hero->stolen) {
            // need to add running away
        }
        // when hero out of sight
        else if (probability(66)) {
            return std::make_unique<Wander>();
        }
        // if no hero and not wandering, the monster can rest
        else {
            return std::make_unique<Rest>();
        }

        // calculate the direction to move away from hero
        // function run_away to take in engine.hero->get_position()
        // if they are to the left you want to move right
        // need to consider if wall - move to available tile to move to instead

        //        Result Wander::perform(Engine& engine, std::shared_ptr<Entity> entity) {
        //            Vec position = entity->get_position(); // on slides
        //            std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
        //
        //            // randomizing which monster will go first
        //            shuffle(std::begin(neighbors), std::end(neighbors));
        //
        //            // move onto empty floor tile that is found
        //            for (const Vec& neighbor : neighbors) {
        //                Tile& t = engine.dungeon.get_tile(neighbor);
        //                if (!t.is_wall() && !t.has_entity()) {
        //                    Vec movement = neighbor - position;
        //                    return alternative(Move{movement});
        //                }
        //            }
        //
        //            return alternative(Rest{});
        //        }
        return nullptr;
    }
}