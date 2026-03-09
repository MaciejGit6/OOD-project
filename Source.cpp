#include <windows.h>
#include "Game.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); //i tak mialem problem ze zmianą symboli playera i ścian

    Game myGame;

    myGame.Run();

    return 0;
}