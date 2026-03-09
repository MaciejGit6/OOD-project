#include <windows.h>
#include "Game.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Game myGame;
    myGame.Run();

    return 0;
}