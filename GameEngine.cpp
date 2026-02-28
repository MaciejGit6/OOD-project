#include "GameEngine.h"
#include <iostream>
#include <string>
#include "UnusableItem.h"


#include "Sword.h"
#include "CurrencyItem.h"

#include <cstdlib>
#include <ctime>   

#include "Sword.h"
#include "CurrencyItem.h"

#define RAND_AMOUNT 7

using namespace std;

GameEngine::GameEngine() {
    gameIsRunning = true;

    
    srand(time(0));

    
    for (int i = 0; i < RAND_AMOUNT; i++) {
        int x, y;
        Tile* targetTile = nullptr;

      
        do {
            x = rand() % gameMap.getWidth();   
            y = rand() % gameMap.getHeight();  
            targetTile = gameMap.getTile(x, y);
        } while (targetTile == nullptr || !targetTile->isPassable());

        // Now that we know the tile is a floor, add the item
        
        // At the top of GameEngine.cpp:


// ... inside your constructor's for-loop:
        int r = rand() % 6; // Increase to 6 possible items
        switch (r) {
        case 0:
            targetTile->addItem(new Sword());
            break;
        case 1:
            targetTile->addItem(new Coin());
            break;
        case 2:
            targetTile->addItem(new Gold());
            break;
        case 3:
            targetTile->addItem(new Book());
            break;
        case 4:
            targetTile->addItem(new Key());
            break;
        case 5:
            targetTile->addItem(new Bone());
            break;
        }
    }
}

bool GameEngine::isRunning() const {
    return gameIsRunning;
}

void GameEngine::processUserInput() {
    char input = _getch();
    input = tolower(input);

    int targetX = player.getX();
    int targetY = player.getY();

    // 1. Determine target coordinates based on WASD
    if (input == 'w') targetY--;
    else if (input == 's') targetY++;
    else if (input == 'a') targetX--;
    else if (input == 'd') targetX++;
    else if (input == 'q') {
        gameIsRunning = false;
        return;
    }
    // 2. Handle Interaction (The 'E' key)
    else if (input == 'e') {
        Tile* currentTile = gameMap.getTile(player.getX(), player.getY());
        std::vector<Item*>& groundItems = currentTile->getItems();

        if (!groundItems.empty()) {
            // Get the top item
            Item* itemToPickUp = groundItems.back();

            // TELL the item to be picked up. No RTTI needed!
            bool shouldDestroy = itemToPickUp->onPickup(player);

            // Remove it from the ground
            groundItems.pop_back();

            // If it was a coin/gold, it returned true, meaning we need to delete it from memory.
            if (shouldDestroy) {
                delete itemToPickUp;
            }
        }
        return; // Skip movement logic
    }

    // 3. If moving, check if the target tile is valid and passable
    Tile* targetTile = gameMap.getTile(targetX, targetY);
    if (targetTile != nullptr && targetTile->isPassable()) {
        if (input == 'w') player.moveUp();
        else if (input == 's') player.moveDown();
        else if (input == 'a') player.moveLeft();
        else if (input == 'd') player.moveRight();
    }
}

void GameEngine::drawFrame() const {
    // Reset cursor to top-left to avoid flickering (assuming this is in your Utils.h)
    cout << "\033[H";

    for (int y = 0; y < gameMap.getHeight(); ++y) {
        // Draw the map row
        for (int x = 0; x < gameMap.getWidth(); ++x) {
            if (x == player.getX() && y == player.getY()) {
                cout << 'P'; // Or PLAYER_SYMBOL if you have it in Utils.h
            }
            else {
                cout << gameMap.getTile(x, y)->getSymbol();
            }
        }

        // Draw the side UI for this specific row
        drawSideUI(y);

        cout << "\n";
    }

    cout << "\nControls: WASD to move, E to pick up, Q to quit.\n";
}

void GameEngine::drawSideUI(int currentRow) const {
    string spacing = "   |   ";

    if (currentRow == 1) {
        cout << spacing << "--- PLAYER STATS ---";
    }
    else if (currentRow == 2) {
        cout << spacing << "Gold: " << player.getGold() << "  Coins: " << player.getCoins();
    }
    else if (currentRow == 4) {
        cout << spacing << "--- EQUIPMENT ---";
    }
    else if (currentRow == 5) {
        Item* left = player.getLeftHand();
        cout << spacing << "Left Hand:  " << (left ? left->getName() : "Empty");
    }
    else if (currentRow == 6) {
        Item* right = player.getRightHand();
        cout << spacing << "Right Hand: " << (right ? right->getName() : "Empty");
    }
    else if (currentRow == 8) {
        cout << spacing << "--- INVENTORY ---";
    }
    else if (currentRow >= 9 && currentRow < 9 + player.getInventory().size()) {
        // List inventory items
        int invIndex = currentRow - 9;
        cout << spacing << "- " << player.getInventory()[invIndex]->getName();
    }
    else if (currentRow == 18) {
        // Look at the ground
        Tile* currentTile = gameMap.getTile(player.getX(), player.getY());
        
        cout << spacing << "Standing on: ";
        if (!currentTile->getItems().empty()) {
            cout << currentTile->getItems().back()->getName() << " ";
        } else {
            cout << "Nothing ";
        }
        
        // Print coordinates on the exact same line. No endl!
        // (Note: I removed the - 1 so it matches the actual mathematical array coordinates)
        cout << "(" << player.getX() - 1 << "," << player.getY() - 1 << ")";

        cout << "         "; //TO AVOID )) CLUSTERS  
    }
    
}