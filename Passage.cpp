//
// Created by Richard Skarbez on 5/7/23.
//

#include "Passage.h"
#include <utility>
#include "PassageDefaultEnterCommand.h"

// Returns the opposite direction of the input string (e.g., "north" -> "south")
std::string Passage::oppositeDirection(const std::string &s) {
    if (s == "north") return "south";
    if (s == "south") return "north";
    if (s == "east")  return "west";
    if (s == "west")  return "east";
    if (s == "up")    return "down";
    if (s == "down")  return "up";
    return "";  // unknown direction
}

// Creates two passages between rooms if bidirectional is true
void Passage::createBasicPassage(Room* from, Room* to,
                                const std::string &direction, bool bidirectional) {
    from->addPassage(direction, std::make_shared<Passage>(direction + "_passage", "A basic passage.", from, to));
    if (bidirectional) {
        to->addPassage(oppositeDirection(direction), std::make_shared<Passage>(oppositeDirection(direction) + "_passage", "A basic passage.", to, from));
    }
}

Passage::Passage(const std::string &n, const std::string &d, Room* from, Room* to)
        : Location(n, d), fromRoom(from), toRoom(to) {
    setEnterCommand(std::make_shared<PassageDefaultEnterCommand>(this));
}

Passage::Passage(const std::string &n, const std::string &d, std::shared_ptr<Command> c, Room* from,
                 Room* to)
        : Location(n, d, std::move(c)), fromRoom(from), toRoom(to) {}

void Passage::setFrom(Room* r) {
    fromRoom = r;
}

Room* Passage::getFrom() const {
    return fromRoom;
}

void Passage::setTo(Room* r) {
    toRoom = r;
}

Room* Passage::getTo() const {
    return toRoom;
}

bool Passage::canEnter() const {
    // By default, passage is enterable
    return true;
}

void Passage::enter() {
    // Call the base class enter, which executes the enterCommand
    Location::enter();
}
