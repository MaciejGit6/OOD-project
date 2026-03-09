#pragma once
#include <vector>
#include <memory>
#include "Tile.h"

class Map {
private:
    int width;
    int height;
    std::vector<std::vector<std::unique_ptr<Tile>>> grid;

public:
    Map();
    ~Map() = default;

    Tile* getTile(int x, int y) const;
    bool isValidCoordinate(int x, int y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};