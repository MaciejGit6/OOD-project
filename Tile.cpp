#include "Tile.h"

void Tile::addItem(std::unique_ptr<Item> item) {
    itemsOnGround.push_back(std::move(item));
}

std::vector<std::unique_ptr<Item>>& Tile::getItems() {
    return itemsOnGround;
}

bool FloorTile::isPassable() const {
    return true;
}

std::string FloorTile::getSymbol() const {
    if (!itemsOnGround.empty()) {
        return itemsOnGround.back()->getSymbol();
    }
    return " ";
}

bool WallTile::isPassable() const {
    return false;
}

std::string WallTile::getSymbol() const {
    return "█";
}