#pragma once
#include "Item.h"
#include "Player.h"
#include <string>

class UnusableItem : public Item {
public:
    virtual ~UnusableItem() = default;

    bool onPickup(Player& player) override {
        return false;
    }

    void onEquip(Player& player) override {}
};

class Book : public UnusableItem {
public:
    std::string getSymbol() const override { return "B"; }
    std::string getName() const override { return "Old Book"; }
};

class Key : public UnusableItem {
public:
    std::string getSymbol() const override { return "K"; }
    std::string getName() const override { return "Rusty Key"; }
};

class Bone : public UnusableItem {
public:
    std::string getSymbol() const override { return "%"; }
    std::string getName() const override { return "Monster Bone"; }
};