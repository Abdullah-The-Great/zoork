#include "Door.h"
#include "Player.h"
#include <iostream>

Door::Door(const std::string &name, const std::string &description,
           Room* from, Room* to, const std::string &requiredKeyName)
        : Passage(name, description, from, to), requiredKey(requiredKeyName) {}

bool Door::canEnter() const {
    Player* player = Player::instance();
    for (const auto& item : player->getInventory()) {
        if (item->getName() == requiredKey) {
            return true;  
        }
    }
    return false; 
}

void Door::enter() {
    if (canEnter()) {
        std::cout << "You unlock the door with the " << requiredKey << " and enter.\n";
        Passage::enter();
    } else {
        std::cout << "The door is locked. You need the " << requiredKey << " to open it.\n";
    }
}
