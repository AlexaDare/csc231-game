#include "steal.h"

// check player inventory
// entity then takes the item
// runs away



// curses item and runs away


Steal::Steal(Entity& attacker, Entity& defender)
    :attacker{attacker}, defender{defender} {}

void Steal::execute(Engine& engine) {
    attacker.add_to_inventory(defender.get_current_item()); // creates a copy of hero item
    defender.remove_item(defender.get_current_item_index()); // removes hero item from inventory
}
