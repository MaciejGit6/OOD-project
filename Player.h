#pragma once
#include <vector>
#include <memory>
#include "Item.h"

class Player {
private:
    int x, y;
    int strength, dexterity, health, luck, aggression, wisdom;
    int coins, gold;

    Item* leftHand;
    Item* rightHand;
    std::vector<std::unique_ptr<Item>> inventory;

public:
    Player(int startX = 1, int startY = 1);

    void moveUp(); void moveDown(); void moveLeft(); void moveRight();
    int getX() const; int getY() const;

    void equipLeft(Item* item);
    void equipRight(Item* item);
    void clearHands();

    void addToInventory(std::unique_ptr<Item> item);
    void addGold(int amount);
    void addCoins(int amount);

    int getGold() const;
    int getCoins() const;
    const std::vector<std::unique_ptr<Item>>& getInventory() const;
    Item* getLeftHand() const;
    Item* getRightHand() const;
};