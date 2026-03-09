#pragma once
#include "Player.h"
#include "Map.h"

#include "Utils.h" 


class GameEngine {
private:
    Player player;
    Map gameMap;
    bool gameIsRunning;

    
    void drawSideUI(int currentRow) const;

public:
    GameEngine();

    bool isRunning() const;
    void drawFrame() const;
    void processUserInput();
};