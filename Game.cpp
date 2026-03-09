#include "Game.h"
#include <iostream>

using namespace std;

void Game::Run() {
    cout << "\033[2J\033[?25l";

    while (engine.isRunning()) {
        engine.drawFrame();
        engine.processUserInput();
    }

    cout << "\033[2J\033[H\033[?25h";
}