#include "Map.h"

Map::Map() : width(40), height(20) {
    grid.resize(height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            
            // 2. Draw walls on ALL FOUR edges everywhere else!
            if (x == 0 || x == width -1 || y == 0 || y == height -1) {
                grid[y].push_back(new WallTile());
            }
            // 3. The rest of the inside is floor
            else {
                grid[y].push_back(new FloorTile());
            }
        }
    }
}


Map::~Map() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            
            std::vector<Item*>& floorItems = grid[y][x]->getItems();
            for (Item* item : floorItems) {
                delete item;
            }

          
            delete grid[y][x];
        }
    }
}


bool Map::isValidCoordinate(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}


Tile* Map::getTile(int x, int y) const {
    if (isValidCoordinate(x, y)) {
        return grid[y][x]; // Y is the row, X is the column
    }
    return nullptr; // Safety fallback
}