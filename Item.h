#pragma once
#include <string>

class Player;

class Item {
public:
    virtual ~Item() = default;
    virtual bool onPickup(Player& player) = 0;
    virtual std::string getSymbol() const = 0;
    virtual std::string getName() const = 0;
    virtual void onEquip(Player& player) {}
};