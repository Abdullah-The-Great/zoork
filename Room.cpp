#include "Room.h"
#include "NullPassage.h"
#include <iostream>

Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c)
    : Location(n, d, std::move(c)) {}

void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}

void Room::removePassage(const std::string &direction) {
    auto it = passageMap.find(direction);
    if (it != passageMap.end()) {
        passageMap.erase(it);
    }
}

std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
    auto it = passageMap.find(direction);
    if (it != passageMap.end()) {
        return it->second;
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(this);
    }
}

void Room::addItem(std::shared_ptr<Item> item) {
    if (item) {
        items.push_back(item);
    }
}

void Room::removeItem(const std::string &itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            items.erase(it);
            return;
        }
    }
}

std::shared_ptr<Item> Room::getItem(const std::string &itemName) {
    for (const auto &item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

void Room::listItems() const {
    if (items.empty()) {
        std::cout << "There is nothing of interest here.\n";
    } else {
        std::cout << "You see:\n";
        for (const auto &item : items) {
            std::cout << "- " << item->getName() << "\n";
        }
    }
}
