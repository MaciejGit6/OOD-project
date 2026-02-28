#include "Tile.h"
#include <algorithm>

void Tile::addItem(Item* item) {
    itemsOnGround.push_back(item);
}

void Tile::removeItem(Item* item) {
    
    auto it = std::find(itemsOnGround.begin(), itemsOnGround.end(), item);
    if (it != itemsOnGround.end()) {
        itemsOnGround.erase(it);
    }
}

std::vector<Item*>& Tile::getItems() {
    return itemsOnGround;
}


bool FloorTile::isPassable() const { 
    return true; 
}

char FloorTile::getSymbol() const {

    if (!itemsOnGround.empty()) {
        return itemsOnGround.back()->getSymbol();
    }
    return ' '; 
}


bool WallTile::isPassable() const { 
    return false; 
}

char WallTile::getSymbol() const {

    return '█'; 
}