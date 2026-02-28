#pragma once
#include "Item.h"
#include "Player.h"

class Weapon : public Item {
protected:
    int damage;

public:
    // Constructor forces all weapons to set a damage value
    Weapon(int dmg) : damage(dmg) {}

    virtual ~Weapon() = default;

    int getDamage() const {
        return damage;
    }

    // When ANY weapon is picked up, it goes into the inventory.
    // Returning true tells the GameEngine to remove it from the floor tile.
    bool onPickup(Player& player) override {
        player.addToInventory(this);
        return false;
    }

    // We leave getSymbol(), getName(), and onEquip() for the child classes 
    // to implement, which keeps this class abstract.
};