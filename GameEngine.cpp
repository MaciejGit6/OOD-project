#include "GameEngine.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "UnusableItem.h"
#include "Sword.h"
#include "CurrencyItem.h"
#include "GreatSword.h"
#include "Axe.h"

//poniższa wartosc okresla ile losowych przedmiotow dajemy na planszę
#define RAND_AMOUNT 7

using namespace std;

GameEngine::GameEngine() {
    gameIsRunning = true;
    srand(time(0));

    //tworzenie randomowych przedmiotow
    for (int i = 0; i < RAND_AMOUNT; i++) {
        int x, y;
        Tile* targetTile = nullptr;


        //losowe koordynaty
        do {
            x = rand() % gameMap.getWidth();
            y = rand() % gameMap.getHeight();
            targetTile = gameMap.getTile(x, y);
        } while (targetTile == nullptr || !targetTile->isPassable());


        //losowy typ
        int r = rand() % 8;
        switch (r) {
        case 0: targetTile->addItem(make_unique<Sword>()); break;
        case 1: targetTile->addItem(make_unique<Coin>()); break;
        case 2: targetTile->addItem(make_unique<Gold>()); break;
        case 3: targetTile->addItem(make_unique<Book>()); break;
        case 4: targetTile->addItem(make_unique<Key>()); break;
        case 5: targetTile->addItem(make_unique<Bone>()); break;
        case 6: targetTile->addItem(make_unique<Greatsword>()); break;
        case 7: targetTile->addItem(make_unique<Axe>()); break;
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

    if (input == 'w') targetY--;
    else if (input == 's') targetY++;
    else if (input == 'a') targetX--;
    else if (input == 'd') targetX++;
    else if (input == 'q') {
        gameIsRunning = false;

        return;
    }
    else if (input == 'e') {
        Tile* currentTile = gameMap.getTile(player.getX(), player.getY());
        auto& groundItems = currentTile->getItems();

        if (!groundItems.empty()) {
            std::unique_ptr<Item> item = std::move(groundItems.back());
            groundItems.pop_back();

            bool shouldDestroy = item->onPickup(player);

            if (!shouldDestroy) {
                player.addToInventory(std::move(item));
            }
        }
        return;
    }
    else if (input >= '1' && input <= '9') {
        int index = input - '1';
        if (index < player.getInventory().size()) {
            player.getInventory()[index]->onEquip(player);
        }
        return;
    }

    Tile* targetTile = gameMap.getTile(targetX, targetY);
    if (targetTile != nullptr && targetTile->isPassable()) {
        if (input == 'w') player.moveUp();
        else if (input == 's') player.moveDown();
        else if (input == 'a') player.moveLeft();
        else if (input == 'd') player.moveRight();
    }
}

void GameEngine::drawFrame() const {
    cout << "\033[H";

    for (int y = 0; y < gameMap.getHeight(); ++y) {
        for (int x = 0; x < gameMap.getWidth(); ++x) {
            if (x == player.getX() && y == player.getY()) {
                cout << "P";
            }
            else {
                cout << gameMap.getTile(x, y)->getSymbol();
            }
        }
        drawSideUI(y);
        cout << "\n";
    }
    cout << "\nControls: WASD to move, E to pick up, 1-9 to equip/unequip, Q to quit.      \n";
}

void GameEngine::drawSideUI(int currentRow) const {
    string spacing = "   |   ";
    string line = "";

    if (currentRow == 1) {
        line = spacing + "--- PLAYER STATS ---";
    }
    else if (currentRow == 2) {
        line = spacing + "Gold: " + to_string(player.getGold()) + "  Coins: " + to_string(player.getCoins());
    }
    else if (currentRow == 4) {
        line = spacing + "--- EQUIPMENT ---";
    }
    else if (currentRow == 5) {
        Item* left = player.getLeftHand();
        line = spacing + "Left Hand:  " + (left ? left->getName() : "Empty");
    }
    else if (currentRow == 6) {
        Item* right = player.getRightHand();
        line = spacing + "Right Hand: " + (right ? right->getName() : "Empty");
    }
    else if (currentRow == 8) {
        line = spacing + "--- INVENTORY ---";
    }
    else if (currentRow >= 9 && currentRow < 9 + player.getInventory().size()) {
        int invIndex = currentRow - 9;
        line = spacing + to_string(invIndex + 1) + ". " + player.getInventory()[invIndex]->getName();
    }
    else if (currentRow == 18) {
        Tile* currentTile = gameMap.getTile(player.getX(), player.getY());
        line = spacing + "Standing on: ";
        if (!currentTile->getItems().empty()) {
            line += currentTile->getItems().back()->getName() + " ";
        }
        else {
            line += "Nothing ";
        }
        line += "(" + to_string(player.getX()) + "," + to_string(player.getY()) + ")";
    }

    cout << line << "                   ";
}