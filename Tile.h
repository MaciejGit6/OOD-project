#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Item.h"

class Tile {
protected:
    std::vector<std::unique_ptr<Item>> itemsOnGround;

public:
    virtual ~Tile() = default;
    virtual bool isPassable() const = 0;
    virtual std::string getSymbol() const = 0;

    void addItem(std::unique_ptr<Item> item);
    std::vector<std::unique_ptr<Item>>& getItems();
};

class FloorTile : public Tile {
public:
    bool isPassable() const override;
    std::string getSymbol() const override;
};

class WallTile : public Tile {
public:
    bool isPassable() const override;
    std::string getSymbol() const override;
};