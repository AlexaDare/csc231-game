#pragma once

#include "event.h"

// forward declaration (declare the type)

class Entity;

Class Hit : public Event {
public:
    Hit(Entity& entity, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override; // basically checking if the person is dead
    // recommends making each event as small as possible
    // the smaller and more single purpose you make them, the more versatile they will be

private:
    Entity& entity;
    int damage;
};
