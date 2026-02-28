#pragma once
#include <vector>
#include "Item.h"

class Tile {
protected:
    std::vector<Item*> itemsOnGround;

public:
    virtual ~Tile() = default;

    virtual bool isPassable() const = 0;
    virtual char getSymbol() const = 0;

    void addItem(Item* item);
    void removeItem(Item* item);
    std::vector<Item*>& getItems();
};

class FloorTile : public Tile {
public:
    bool isPassable() const override;
    char getSymbol() const override;
};

class WallTile : public Tile {
public:
    bool isPassable() const override;
    char getSymbol() const override;
};