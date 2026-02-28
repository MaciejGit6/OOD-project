#include "Player.h"

Player::Player(int startX, int startY)
    : x(startX), y(startY),
    strength(5), dexterity(5), health(100), luck(5), aggression(5), wisdom(5),
    coins(0), gold(0),
    leftHand(nullptr), rightHand(nullptr) {
}

void Player::moveUp() { y--; }
void Player::moveDown() { y++; }
void Player::moveLeft() { x--; }
void Player::moveRight() { x++; }

int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::equipLeft(Item* item) { leftHand = item; }
void Player::equipRight(Item* item) { rightHand = item; }
void Player::clearHands() { leftHand = nullptr; rightHand = nullptr; }

void Player::addToInventory(Item* item) { inventory.push_back(item); }
void Player::addGold(int amount) { gold += amount; }
void Player::addCoins(int amount) { coins += amount; }

int Player::getGold() const { return gold; }
int Player::getCoins() const { return coins; }
const std::vector<Item*>& Player::getInventory() const { return inventory; }
Item* Player::getLeftHand() const { return leftHand; }
Item* Player::getRightHand() const { return rightHand; }