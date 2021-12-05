//
//  players.cpp
//  Tic-Tac-Toe
//
//  Created by Channing Christian on 8/31/20.
//  Copyright © 2020 Channing Christian. All rights reserved.
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "players.hpp"

using namespace sf;
using namespace std;

Player::Player(std::string stillTexturePath, std::string drawTexturePath, double positionX, double positionY){
    drawTexture.loadFromFile(drawTexturePath);
    stillTexture.loadFromFile(stillTexturePath);
    
    this->setOrigin(64, 64);
    this->setScale(2, 2);
    this->setPosition(positionX, positionY);
    
    sprite.setTexture(drawTexture);
}

void Player::setOrigin(double x, double y){
    sprite.setOrigin(x, y);
}

void Player::setScale(double width, double height){
    sprite.setScale(width, height);
}

void Player::setPosition(double x, double y){
    sprite.setPosition(x, y);
}

sf::Sprite Player::getSprite(){
    return sprite;
}

void Player::setFrame(sf::IntRect frame){
    sprite.setTextureRect(frame);
}

void Player::setTexture(std::string tex){
    sprite.setTexture(stillTexture);
}


