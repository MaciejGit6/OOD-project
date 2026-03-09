#pragma once
#include "Item.h"
#include "Player.h"

class Weapon : public Item {
protected:
    int damage;

public:
    Weapon(int dmg) : damage(dmg) {}
    virtual ~Weapon() = default;

    int getDamage() const { return damage; }

    bool onPickup(Player& player) override {
        return false;
    }
};