#include "Player.h"
#include <iostream>

Player* Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(Item* item) {
    if (item) {
        inventory.push_back(item);
        std::cout << "You take the " << item->getName() << ".\n";
    }
}

void Player::removeItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == itemName) {
            inventory.erase(it);
            return;
        }
    }
}

Item* Player::getItem(const std::string& itemName) const {
    for (auto item : inventory) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

void Player::listInventory() const {
    if (inventory.empty()) {
        std::cout << "You have nothing in your inventory.\n";
    } else {
        std::cout << "You are carrying:\n";
        for (auto item : inventory) {
            std::cout << "- " << item->getName() << "\n";
        }
    }
}
