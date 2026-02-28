#include "Game.h"


void Game::Run() {
    cout << "\033[2J\033[?25l";

    GameEngine engine;

    while (engine.isRunning()) {
        engine.drawFrame();
        engine.processUserInput();
    }

    // When quitting: clear screen, reset cursor, AND SHOW the cursor again (\033[?25h)
    cout << "\033[2J\033[H\033[?25h";
    cout << "Thanks for playing! Goodbye.\n";
}