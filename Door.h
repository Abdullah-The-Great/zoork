#ifndef ZOORK_DOOR_H
#define ZOORK_DOOR_H

#include "Passage.h"

class Door : public Passage {
public:
    Door(const std::string &name, const std::string &description,
         Room* from, Room* to, const std::string &requiredKeyName);

    bool canEnter() const override;
    void enter() override;

private:
    std::string requiredKey; 
};

#endif 
