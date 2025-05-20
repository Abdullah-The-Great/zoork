#ifndef ZOORK_PLAYER_H
#define ZOORK_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "NullRoom.h"
#include "Item.h"
#include <vector>
#include <string>

class Player : public Character {
public:
    static Player* instance() {
        if (!playerInstance) {
            playerInstance = new Player();
        }
        return playerInstance;
    }

    void setCurrentRoom(Room*);
    Room* getCurrentRoom() const;

    // Inventory management
    void addItem(Item* item);
    void removeItem(const std::string& itemName);
    Item* getItem(const std::string& itemName) const;
    void listInventory() const;

    // New getter for inventory access
    const std::vector<Item*>& getInventory() const { return inventory; }

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

private:
    static Player* playerInstance;
    Room* currentRoom;
    std::vector<Item*> inventory;

    Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you."),
               currentRoom(new NullRoom()) {}
};

#endif //ZOORK_PLAYER_H
