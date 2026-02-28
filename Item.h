#pragma once
#include <string>

// Forward declaration of Player prevents circular dependency
class Player;

class Item {
public:
    virtual ~Item() = default;

    // Returns true if the item should be removed from the ground entirely
    virtual bool onPickup(Player& player) = 0;

    // Returns the symbol to draw on the map if it's on the floor
    virtual char getSymbol() const = 0;

    virtual std::string getName() const = 0;

    // Virtual method for equipping. Does nothing by default.
    // Weapons will override this to interact with the player's hands.
    virtual void onEquip(Player& player) {}
};