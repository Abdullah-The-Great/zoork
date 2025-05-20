#ifndef ZOORK_BASICPASSAGE_H
#define ZOORK_BASICPASSAGE_H

#include "Passage.h"

// BasicPassage inherits from Passage and may customize behavior
class BasicPassage : public Passage {
public:
    BasicPassage(Room* from, Room* to, const std::string& direction, bool bidirectional = true);

    // Override enter() if Passage declares virtual enter()
    void enter() override;
};

#endif //ZOORK_BASICPASSAGE_H
