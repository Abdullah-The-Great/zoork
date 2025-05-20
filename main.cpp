#include "ZOOrkEngine.h"
#include "Room.h"
#include "Passage.h"
#include <memory>

int main() {
    auto foyer = std::make_shared<Room>("Foyer", "A dimly lit entrance hall.");
    auto kitchen = std::make_shared<Room>("Kitchen", "A cluttered space filled with old cookware.");
    auto library = std::make_shared<Room>("Library", "Dusty tomes fill the wooden shelves.");
    auto garden = std::make_shared<Room>("Garden", "Overgrown weeds and flowers.");
    auto basement = std::make_shared<Room>("Basement", "It's dark and smells like mildew.");
    auto attic = std::make_shared<Room>("Attic", "Broken toys and spiderwebs litter the corners.");
    auto hallway = std::make_shared<Room>("Hallway", "A long corridor with creaky floorboards.");
    auto bedroom = std::make_shared<Room>("Bedroom", "A cozy room with a large bed.");
    auto bathroom = std::make_shared<Room>("Bathroom", "Cracked tiles and a stained mirror.");
    auto study = std::make_shared<Room>("Study", "A desk and an old typewriter sit silently.");

    // Connect rooms with passages
    foyer->addPassage("north", std::make_shared<Passage>("foyer_to_hallway", "A normal passageway.", foyer.get(), hallway.get()));
    hallway->addPassage("south", std::make_shared<Passage>("hallway_to_foyer", "A normal passageway.", hallway.get(), foyer.get()));

    hallway->addPassage("east", std::make_shared<Passage>("hallway_to_kitchen", "A normal passageway.", hallway.get(), kitchen.get()));
    hallway->addPassage("west", std::make_shared<Passage>("hallway_to_library", "A normal passageway.", hallway.get(), library.get()));
    kitchen->addPassage("west", std::make_shared<Passage>("kitchen_to_hallway", "A normal passageway.", kitchen.get(), hallway.get()));
    library->addPassage("east", std::make_shared<Passage>("library_to_hallway", "A normal passageway.", library.get(), hallway.get()));

    hallway->addPassage("north", std::make_shared<Passage>("hallway_to_bedroom", "A normal passageway.", hallway.get(), bedroom.get()));
    bedroom->addPassage("south", std::make_shared<Passage>("bedroom_to_hallway", "A normal passageway.", bedroom.get(), hallway.get()));

    bedroom->addPassage("east", std::make_shared<Passage>("bedroom_to_bathroom", "A normal passageway.", bedroom.get(), bathroom.get()));
    bathroom->addPassage("west", std::make_shared<Passage>("bathroom_to_bedroom", "A normal passageway.", bathroom.get(), bedroom.get()));

    bedroom->addPassage("west", std::make_shared<Passage>("bedroom_to_study", "A normal passageway.", bedroom.get(), study.get()));
    study->addPassage("east", std::make_shared<Passage>("study_to_bedroom", "A normal passageway.", study.get(), bedroom.get()));

    kitchen->addPassage("down", std::make_shared<Passage>("kitchen_to_basement", "A dark stairwell.", kitchen.get(), basement.get()));
    basement->addPassage("up", std::make_shared<Passage>("basement_to_kitchen", "A dark stairwell.", basement.get(), kitchen.get()));

    attic->addPassage("down", std::make_shared<Passage>("attic_to_bedroom", "A narrow ladder.", attic.get(), bedroom.get()));
    bedroom->addPassage("up", std::make_shared<Passage>("bedroom_to_attic", "A narrow ladder.", bedroom.get(), attic.get()));

    library->addPassage("north", std::make_shared<Passage>("library_to_garden", "A creaky door leading outside.", library.get(), garden.get()));
    garden->addPassage("south", std::make_shared<Passage>("garden_to_library", "A creaky door leading inside.", garden.get(), library.get()));

    // Start game
    ZOOrkEngine engine(foyer);
    engine.run();

    return 0;
}
