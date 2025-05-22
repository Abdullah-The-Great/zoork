#include "ZOOrkEngine.h"
#include "Room.h"
#include "Passage.h"
#include "Item.h"
#include <memory>

int main() {
    // Create Halloween-themed rooms in Hilltop Manor
    auto foyer = std::make_shared<Room>("foyer", "A creepy entrance hall with cobwebs and flickering candlelight.");
    auto kitchen = std::make_shared<Room>("kitchen", "A dusty kitchen with rusty pots and strange smells.");
    auto library = std::make_shared<Room>("library", "Shelves full of ancient, dusty spellbooks.");
    auto garden = std::make_shared<Room>("garden", "An overgrown graveyard with crooked tombstones.");
    auto basement = std::make_shared<Room>("basement", "Dark and damp, you hear faint whispers.");
    auto attic = std::make_shared<Room>("attic", "Full of broken toys and eerie shadows.");
    auto hallway = std::make_shared<Room>("hallway", "A long hallway lit by flickering sconces.");
    auto bedroom = std::make_shared<Room>("bedroom", "An old bedroom with a creaky bed and torn curtains.");
    auto bathroom = std::make_shared<Room>("bathroom", "A cracked mirror and a rusty clawfoot tub.");
    auto study = std::make_shared<Room>("study", "A desk cluttered with potion bottles and strange artifacts.");

    // Add Halloween-themed items with all lowercase names
    foyer->addItem(std::make_shared<Item>("pumpkin", "A carved pumpkin with a flickering candle inside."));
    foyer->addItem(std::make_shared<Item>("witch-hat", "A tall, pointed black hat with a purple band."));
    foyer->addItem(std::make_shared<Item>("rusty-key", "An old rusty key covered in strange symbols."));

    kitchen->addItem(std::make_shared<Item>("cauldron", "A large iron cauldron bubbling with green liquid."));
    kitchen->addItem(std::make_shared<Item>("bottle-of-bat-wings", "A dusty bottle filled with dried bat wings."));
    kitchen->addItem(std::make_shared<Item>("cursed spoon", "A silver spoon that feels cold to the touch."));

    library->addItem(std::make_shared<Item>("ancient-spellbook", "A leather-bound book filled with arcane writings."));
    library->addItem(std::make_shared<Item>("crystal-ball", "A cloudy crystal ball glowing faintly."));
    library->addItem(std::make_shared<Item>("witches' broom", "A broomstick with twigs tied to the end."));

    garden->addItem(std::make_shared<Item>("grave-marker", "A cracked tombstone with a faded name."));
    garden->addItem(std::make_shared<Item>("black-cat-statue", "A stone statue of a black cat with glowing eyes."));
    garden->addItem(std::make_shared<Item>("spider", "A large, hairy spider crawling across the ground."));

    basement->addItem(std::make_shared<Item>("ghost-lantern", "An old lantern that glows with an eerie light."));
    basement->addItem(std::make_shared<Item>("chains", "Rusty chains hanging from the ceiling."));
    basement->addItem(std::make_shared<Item>("skull", "A human skull with mysterious carvings."));

    attic->addItem(std::make_shared<Item>("ragged-doll", "A torn doll with button eyes."));
    attic->addItem(std::make_shared<Item>("old-photo", "A faded photo of a haunted family."));
    attic->addItem(std::make_shared<Item>("dusty-trunk", "A large wooden trunk covered in dust."));

    hallway->addItem(std::make_shared<Item>("candelabra", "A silver candelabra holding half-melted candles."));
    hallway->addItem(std::make_shared<Item>("portrait", "A portrait of a stern-looking witch."));
    hallway->addItem(std::make_shared<Item>("mirror-shard", "A sharp piece of a broken mirror."));

    bedroom->addItem(std::make_shared<Item>("tattered-cloak", "A black cloak with holes and tears."));
    bedroom->addItem(std::make_shared<Item>("locked-diary", "A diary bound in worn leather, locked tight."));
    bedroom->addItem(std::make_shared<Item>("lantern", "An old lantern flickering with a ghostly flame."));

    bathroom->addItem(std::make_shared<Item>("broken-razor", "A rusty razor with a cracked handle."));
    bathroom->addItem(std::make_shared<Item>("moldy-towel", "A towel damp with mildew."));
    bathroom->addItem(std::make_shared<Item>("spiderweb", "A thick spiderweb covering the corner."));

    study->addItem(std::make_shared<Item>("potion-bottle", "A small bottle filled with glowing purple liquid."));
    study->addItem(std::make_shared<Item>("quill-pen", "A black feather quill pen dripping with ink."));
    study->addItem(std::make_shared<Item>("cursed-amulet", "An amulet that seems to pulse with dark energy."));

    // Connect rooms with passages as before, using lowercase room names
    foyer->addPassage("north", std::make_shared<Passage>("foyer_to_hallway", "A creaky wooden door.", foyer.get(), hallway.get()));
    hallway->addPassage("south", std::make_shared<Passage>("hallway_to_foyer", "A creaky wooden door.", hallway.get(), foyer.get()));

    hallway->addPassage("east", std::make_shared<Passage>("hallway_to_kitchen", "A narrow archway.", hallway.get(), kitchen.get()));
    hallway->addPassage("west", std::make_shared<Passage>("hallway_to_library", "A darkened archway.", hallway.get(), library.get()));
    kitchen->addPassage("west", std::make_shared<Passage>("kitchen_to_hallway", "A narrow archway.", kitchen.get(), hallway.get()));
    library->addPassage("east", std::make_shared<Passage>("library_to_hallway", "A darkened archway.", library.get(), hallway.get()));

    hallway->addPassage("north", std::make_shared<Passage>("hallway_to_bedroom", "A heavy oak door.", hallway.get(), bedroom.get()));
    bedroom->addPassage("south", std::make_shared<Passage>("bedroom_to_hallway", "A heavy oak door.", bedroom.get(), hallway.get()));

    bedroom->addPassage("east", std::make_shared<Passage>("bedroom_to_bathroom", "A creaky door.", bedroom.get(), bathroom.get()));
    bathroom->addPassage("west", std::make_shared<Passage>("bathroom_to_bedroom", "A creaky door.", bathroom.get(), bedroom.get()));

    bedroom->addPassage("west", std::make_shared<Passage>("bedroom_to_study", "A narrow door.", bedroom.get(), study.get()));
    study->addPassage("east", std::make_shared<Passage>("study_to_bedroom", "A narrow door.", study.get(), bedroom.get()));

    kitchen->addPassage("down", std::make_shared<Passage>("kitchen_to_basement", "A creaky staircase.", kitchen.get(), basement.get()));
    basement->addPassage("up", std::make_shared<Passage>("basement_to_kitchen", "A creaky staircase.", basement.get(), kitchen.get()));

    attic->addPassage("down", std::make_shared<Passage>("attic_to_bedroom", "A narrow ladder.", attic.get(), bedroom.get()));
    bedroom->addPassage("up", std::make_shared<Passage>("bedroom_to_attic", "A narrow ladder.", bedroom.get(), attic.get()));

    library->addPassage("north", std::make_shared<Passage>("library_to_garden", "A rusted gate leading outside.", library.get(), garden.get()));
    garden->addPassage("south", std::make_shared<Passage>("garden_to_library", "A rusted gate leading inside.", garden.get(), library.get()));

    // Start game
    ZOOrkEngine engine(foyer);
    engine.run();

    return 0;
}
