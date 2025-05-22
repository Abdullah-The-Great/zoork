#ifndef ZOORK_BASICPASSAGE_H
#define ZOORK_BASICPASSAGE_H

#include "Passage.h"


class BasicPassage : public Passage {
public:
    BasicPassage(Room* from, Room* to, const std::string& direction, bool bidirectional = true);


    void enter() override;
};

#endif 
