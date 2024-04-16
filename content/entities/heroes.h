#pragma once

#include "entity.h"
#include <memory>

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero); // added on 04/08/24

    std::unique_ptr<Action> behavior(Engine& engine, Entity& /*entity*/);
}
