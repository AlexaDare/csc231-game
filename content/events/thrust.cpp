#include "thrust.h"

constexpr int duration = 10; // number of frames
constexpr int delta = 3; // shift it by three frames

Thrust::Thrust(Sprite& sprite, Vec direction)
    :Event {duration}, sprite{sprite}, copy{sprite}, direction{direction} {
    // orient the weapon towards direction

    sprite.center = sprite.size /2; // middle of image
    sprite.shift.y -= sprite.size.y/*meant to be x?*/ / 4;

    if (direction == Vec{1,0}) { // right
        sprite.angle = 90;
    }
    else if (direction == Vec{-1,0}) { // left
        sprite.angle = -90;
    }
    else if (direction == Vec{0,1}) { // up
        sprite.angle = 0;
        this->direction = -1 * direction;
    }
    else if (direction == Vec{0,-1}) { // down
        sprite.angle = 180;
        sprite.shift.y += sprite.size.y;
        this->direction = -1 * direction;
    }
}

void Thrust::execute(Engine& engine) {
    // shift in pixels (16 per tiles)
    sprite.shift += direction * delta;
}

void Thrust::when_done(Engine& engine) {
    sprite = copy;
}