#pragma once

#include "entity.h"
#include <memory>

namespace Monsters {
    void make_demon_tiny(std::shared_ptr<Entity>& monster);
    void make_masked_orc(std::shared_ptr<Entity>& monster); // required for assignment
    void make_muddy(std::shared_ptr<Entity>& monster);
    void make_orc_shaman(std::shared_ptr<Entity>& monster);
    void make_skeleton(std::shared_ptr<Entity>& monster);
    void make_wizard(std::shared_ptr<Entity>& monster);

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);
}