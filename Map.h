#pragma once
#include <vector>
#include "Tile.h"

class Map {
private:
    int width;
    int height;
    std::vector<std::vector<Tile*>> grid;

public:
    Map();
    ~Map(); // Crucial: You must loop through and delete all Tile* to prevent memory leaks!

    Tile* getTile(int x, int y) const;
    bool isValidCoordinate(int x, int y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};