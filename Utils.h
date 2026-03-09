#pragma once
#include "Item.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


#ifdef _WIN32
#include <conio.h> //windows built in function _getchar()
#else
#include <termios.h> 
#include <unistd.h>
//Defining for non-windows
int _getch() {
    struct termios originalSettings, newSettings;
    int characterPressed;

    
    tcgetattr(STDIN_FILENO, &originalSettings);
    newSettings = originalSettings;

    
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    
    characterPressed = getchar();

   
    tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings);

    return characterPressed;
}
#endif




const string CLEAR_ENTIRE_SCREEN = "\033[2J";
const string RESET_CURSOR_POSITION = "\033[H";
const char WALL_SYMBOL = '█';
const char EMPTY_SPACE_SYMBOL = ' ';
const char PLAYER_SYMBOL = '¶';