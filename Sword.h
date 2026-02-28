#pragma once
#include "Weapon.h"
#include "Player.h"

class Sword : public Weapon {
public:
    // Call the Weapon constructor to set the damage to 15
    Sword() : Weapon(15) {}

    char getSymbol() const override {
        return '/'; // A slash makes a nice simple sword symbol
    }

    std::string getName() const override {
        return "Iron Sword";
    }

    // The "Tell, Don't Ask" interaction
    void onEquip(Player& player) override {
        // A one-handed weapon simply tells the player to hold it in one hand.
        // It doesn't need to ask the player for permission or check types!
        player.equipRight(this);
    }
};