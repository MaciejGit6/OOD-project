#pragma once
#include "Player.h"
#include "Map.h"
// Assuming your Utils.h contains _getch() and the constants
#include "Utils.h" 


class GameEngine {
private:
    Player player;
    Map gameMap;
    bool gameIsRunning;

    // Helper method to draw the side UI next to the map
    void drawSideUI(int currentRow) const;

public:
    GameEngine();

    bool isRunning() const;
    void drawFrame() const;
    void processUserInput();
};