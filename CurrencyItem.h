#pragma once
#include "Item.h"
#include "Player.h"

class Coin : public Item {
public:
    bool onPickup(Player& player) override {
        player.addCoins(1);
        return true;
    }
    std::string getSymbol() const override { return "c"; }
    std::string getName() const override { return "Coin"; }
};

class Gold : public Item {
public:
    bool onPickup(Player& player) override {
        player.addGold(1);
        return true;
    }
    std::string getSymbol() const override { return "g"; }
    std::string getName() const override { return "Gold Chunk"; }
};