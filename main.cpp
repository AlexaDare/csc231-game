#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        // right here is where to add on character // added on 04/08/24
        Heroes::make_wizard(hero);

        for (int i = 0; i < 4; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_demon_tiny(monster);
        }

        for (int i = 0; i < 11; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_muddy(monster);
        }

        for (int i = 0; i < 2; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_orc_shaman(monster);
        }

        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_skeleton(monster);
        }

        for (int i = 0; i < 2; ++i) { // create one monster
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_wizard(monster);
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
