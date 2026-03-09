#pragma once
#include "Weapon.h"
#include "Player.h"

class Sword : public Weapon {
public:
    Sword() : Weapon(15) {}

    std::string getSymbol() const override { return "/"; }
    std::string getName() const override { return "Iron Sword"; }

    void onEquip(Player& player) override {
        if (player.getRightHand() == this) {
            player.equipRight(nullptr);
        }
        else {
            player.equipRight(this);
            if (player.getLeftHand() == this) {
                player.equipLeft(nullptr);
            }
        }
    }
};