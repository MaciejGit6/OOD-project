#pragma once
#include "Item.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Cross-Platform Input Handling ---
// Terminals normally wait for you to press "Enter" before sending text to the program.
// For a game, we need the program to react the exact moment a key is pressed.
#ifdef _WIN32
#include <conio.h> // Windows has a built-in function for this: _getch()
#else
#include <termios.h> 
#include <unistd.h>

// Linux and macOS don't have _getch(), so we have to build our own.
// This function temporarily turns off the terminal's "wait for enter" feature.
int _getch() {
    struct termios originalSettings, newSettings;
    int characterPressed;

    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &originalSettings);
    newSettings = originalSettings;

    // Disable "canonical" mode (waiting for Enter) and "echo" (printing the key to the screen)
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    // Read the single key press
    characterPressed = getchar();

    // Restore the original terminal settings so the terminal behaves normally after
    tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings);

    return characterPressed;
}
#endif



// --- Constants ---
// These are special commands that tell the terminal console to do things.
// Giving them names makes the code much easier to read.
const string CLEAR_ENTIRE_SCREEN = "\033[2J";
const string RESET_CURSOR_POSITION = "\033[H";
const char WALL_SYMBOL = '█';
const char EMPTY_SPACE_SYMBOL = ' ';
const char PLAYER_SYMBOL = '¶';