#pragma once
#include "Weapon.h"
#include "Player.h"

//Przykład itema dla którego potrzebne sa obie ręce 

class Greatsword : public Weapon {
public:
    
    Greatsword() : Weapon(30) {}

    std::string getSymbol() const override { return "T"; }
    std::string getName() const override { return "Heavy Greatsword"; }

    void onEquip(Player& player) override {
       
        if (player.getLeftHand() == this && player.getRightHand() == this) {
            player.equipLeft(nullptr);
            player.equipRight(nullptr);
        }
       
        else { //zajmuje obie ręce 
            player.equipLeft(this);
            player.equipRight(this);
        }
    }
};