#include "ZOOrkEngine.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"

#include <iostream>
#include <sstream>
#include <algorithm>

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start) {
    std::cout << "Welcome to Hilltop Manor!\n\n";

    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run() {
    while (!gameOver) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);

        if (words.empty()) {
            continue;
        }

        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go") {
            handleGoCommand(arguments);
        } else if ((command == "look") || (command == "inspect")) {
            handleLookCommand(arguments);
        } else if ((command == "take") || (command == "get")) {
            handleTakeCommand(arguments);
        } else if (command == "drop") {
            handleDropCommand(arguments);
        } else if (command == "quit") {
            handleQuitCommand(arguments);
        } else if (command == "inventory" || command == "inv") {
            player->listInventory();
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Go where?\n";
        return;
    }

    std::string direction;
    std::string arg = arguments[0];
    if (arg == "n" || arg == "north") direction = "north";
    else if (arg == "s" || arg == "south") direction = "south";
    else if (arg == "e" || arg == "east") direction = "east";
    else if (arg == "w" || arg == "west") direction = "west";
    else if (arg == "u" || arg == "up") direction = "up";
    else if (arg == "d" || arg == "down") direction = "down";
    else direction = arg;

    Room* currentRoom = player->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
    if (!passage) {
        std::cout << "You can't go that way.\n";
        return;
    }
    player->setCurrentRoom(passage->getTo());
    passage->enter();
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments) {
    Room* room = player->getCurrentRoom();

    if (arguments.empty()) {
        std::cout << room->getDescription() << "\n";

        // List items in the room
        const auto& items = room->getItems();
        if (!items.empty()) {
            std::cout << "You see:\n";
            for (const auto& item : items) {
                std::cout << "- " << item->getName() << "\n";
            }
        } else {
            std::cout << "There is nothing of interest here.\n";
        }

        // List available directions
        const auto& passages = room->getPassages();
        if (!passages.empty()) {
            std::cout << "Exits:\n";
            for (const auto& [dir, passage] : passages) {
                std::cout << "- " << dir << "\n";
            }
        }
    } else {
        std::string itemName = arguments[0];
        std::shared_ptr<Item> item = nullptr;

        for (const auto& it : room->getItems()) {
            if (it->getName() == itemName) {
                item = it;
                break;
            }
        }

        if (!item) {
            for (const auto& it : player->getInventory()) {
                if (it->getName() == itemName) {
                    item = it;
                    break;
                }
            }
        }

        if (item) {
            std::cout << item->getDescription() << "\n";
        } else {
            std::cout << "You don't see any '" << itemName << "' here.\n";
        }
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Take what?\n";
        return;
    }

    std::string itemName = arguments[0];
    Room* room = player->getCurrentRoom();

    std::shared_ptr<Item> item = room->getItem(itemName);
    if (!item) {
        std::cout << "There is no " << itemName << " here.\n";
        return;
    }

    player->addItem(item);
    room->removeItem(itemName);
    std::cout << "You take the " << itemName << ".\n";
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Drop what?\n";
        return;
    }

    std::string itemName = arguments[0];
    std::shared_ptr<Item> item = player->getItem(itemName);

    if (!item) {
        std::cout << "You don't have a " << itemName << ".\n";
        return;
    }

    Room* room = player->getCurrentRoom();

    player->removeItem(itemName);
    room->addItem(item);
    std::cout << "You drop the " << itemName << ".\n";
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments) {
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes") {
        std::cout << "Happy Halloween!\n";
        gameOver = true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        tokens.push_back(makeLowercase(token));
    }
    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}
