#pragma once
#include <string>

//deklaruje Player bo klasa Item modyfikuje Player
class Player;


//czysto abstrakcyjna 
class Item {
public:
    virtual ~Item() = default;
    virtual bool onPickup(Player& player) = 0;
    virtual std::string getSymbol() const = 0;
    virtual std::string getName() const = 0;
    virtual void onEquip(Player& player) {}
};