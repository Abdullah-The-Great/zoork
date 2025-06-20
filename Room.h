#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "Location.h"
#include <map>
#include <vector>
#include <memory>

class Passage;

class Room : public Location {
public:
    Room(const std::string &, const std::string &);
    Room(const std::string &, const std::string &, std::shared_ptr<Command>);

    void addPassage(const std::string &, std::shared_ptr<Passage>);
    void removePassage(const std::string &);
    std::shared_ptr<Passage> getPassage(const std::string &);


    void addItem(std::shared_ptr<Item>);
    void removeItem(const std::string &);
    std::shared_ptr<Item> getItem(const std::string &);
    void listItems() const;


    const std::vector<std::shared_ptr<Item>> &getItems() const { return items; }
    const std::map<std::string, std::shared_ptr<Passage>> &getPassages() const { return passageMap; }

protected:
    std::map<std::string, std::shared_ptr<Passage>> passageMap;
    std::vector<std::shared_ptr<Item>> items;
};

#endif //ZOORK_ROOM_H
