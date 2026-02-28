#pragma once
#include "Item.h"
#include "Player.h"
#include <string>

// The base class for all junk/lore items
class UnusableItem : public Item {
public:
    virtual ~UnusableItem() = default;

    // When picked up, they go into the inventory and stay there.
    bool onPickup(Player& player) override {
        player.addToInventory(this);
        return false; // False = Do NOT delete from memory
    }

    // Since they are unusable, if the player ever tries to equip them, 
    // nothing happens. (This overrides the virtual method in Item.h)
    void onEquip(Player& player) override {
        // Do nothing! It's an unusable item.
    }
};

// --- The 3 Required Unusable Items ---

class Book : public UnusableItem {
public:
    char getSymbol() const override { return 'B'; }
    std::string getName() const override { return "Old Book"; }
};

class Key : public UnusableItem {
public:
    char getSymbol() const override { return 'K'; }
    std::string getName() const override { return "Rusty Key"; }
};

class Bone : public UnusableItem {
public:
    char getSymbol() const override { return '%'; }
    std::string getName() const override { return "Monster Bone"; }
};