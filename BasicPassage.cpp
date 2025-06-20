#include "BasicPassage.h"
#include <iostream>


BasicPassage::BasicPassage(Room* from, Room* to, const std::string& direction, bool bidirectional)
    : Passage(from->getName() + "_to_" + to->getName(),
              "A basic passage.", from, to) {

    from->addPassage(direction, std::shared_ptr<Passage>(this));
    if (bidirectional) {
        std::string opposite = oppositeDirection(direction);
        to->addPassage(opposite, std::shared_ptr<Passage>(new BasicPassage(to, from, opposite, false)));
    }
}


void BasicPassage::enter() {
    std::cout << "You pass through a basic passage from " << getFrom()->getName()
              << " to " << getTo()->getName() << ".\n";
}

