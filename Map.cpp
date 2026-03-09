#include "Map.h"

//Jesli odkomentowane -> zmiana kształtu planszy,
// tylko trzeba jeszcze zmienić domyślną pozycję startową Playera z (1,1) na (0,0)


Map::Map() : width(40), height(20) {
    grid.resize(height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            /*if ((x == 0 && y == 0) || (x == 1 && y == 0) || (x == 0 && y == 1)) {
                grid[y].push_back(std::make_unique<FloorTile>());
            }*/
            /*else */if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                grid[y].push_back(std::make_unique<WallTile>());
            }
            /*else if (x >= 10 && x <= 15 && y == 5) {
                grid[y].push_back(std::make_unique<WallTile>());
            }*/
            else {
                grid[y].push_back(std::make_unique<FloorTile>());
            }
        }
    }
}

bool Map::isValidCoordinate(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

Tile* Map::getTile(int x, int y) const {
    if (isValidCoordinate(x, y)) {
        return grid[y][x].get();
    }
    return nullptr;
}