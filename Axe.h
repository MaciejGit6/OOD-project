#pragma once
#include "Weapon.h"
#include "Player.h"


class Axe : public Weapon {
public:
	Axe() : Weapon(20) {

	}

	std::string getName() const override { return "Axe"; }
	std::string getSymbol() const override { return "a"; }

	void onEquip(Player& p) override { 
		if (p.getRightHand() == this) {
			p.equipRight(nullptr);
		}
		else {
			p.equipRight(this);
			if (p.getLeftHand() == this) {
				p.equipLeft(nullptr);
			}
		}
	}

};