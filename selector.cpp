//
//  selector.cpp
//  Tic-Tac-Toe
//
//  Created by Channing Christian on 8/31/20.
//  Copyright © 2020 Channing Christian. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "board.hpp"
#include "selector.hpp"


selector::selector(std::string selectorTexturePath){
    selectorTexture.loadFromFile(selectorTexturePath);
    sprite.setTexture(selectorTexture);
    
    posRow = 0;
    posCol = 0;
    
    this->setPosition(((1000/3)*(posCol + 1)) - (1000/6), ((1000/3)*(posRow + 1)) - (1000/6));
}

void selector::setOrigin(double x, double y){
    sprite.setOrigin(x, y);
}

void selector::setScale(double width, double height){
    sprite.setScale(width, height);
}

void selector::setPosition(double x, double y){
    sprite.setPosition(x, y);
}

sf::Sprite selector::getSprite(){
    return sprite;
}

void selector::moveLeft(board * gameboard){
    if(posCol == 0){
        return;
    } else {
        if(gameboard->getBoard()[posRow][posCol - 1] == NULL){
            posCol = posCol - 1;
        } else if(posCol == gameboard->getBoard().size() - 1 && gameboard->getBoard()[posRow][posCol - 2] == NULL){
            posCol = posCol - 2;
        } else {
            return;
        }
    }
    this->setPosition(((1000/3)*(posCol + 1)) - (1000/6), ((1000/3)*(posRow + 1)) - (1000/6));
}

void selector::moveRight(board * gameboard){
    if(posCol == gameboard->getBoard().size() - 1){
        return;
    } else {
        if(gameboard->getBoard()[posRow][posCol + 1] == 0){
            posCol = posCol + 1;
        } else if(posCol == 0 && gameboard->getBoard()[posRow][posCol + 2] == 0){
            posCol = posCol + 2;
        } else {
            return;
        }
    }
    this->setPosition(((1000/3)*(posCol + 1)) - (1000/6), ((1000/3)*(posRow + 1)) - (1000/6));
}

void selector::moveDown(board * gameboard){
    if(posRow == gameboard->getBoard().size() - 1){
        return;
    } else {
        if(gameboard->getBoard()[posRow + 1][posCol] == NULL){
            posRow = posRow + 1;
        } else if(posRow == 0 && gameboard->getBoard()[posRow + 2][posCol] == NULL) {
            posRow = posRow + 2;
        } else {
            return;
        }
    }
    this->setPosition(((1000/3)*(posCol + 1)) - (1000/6), ((1000/3)*(posRow + 1)) - (1000/6));
}

void selector:: moveUp(board * gameboard){
    if(posRow == 0){
        return;
    } else {
        if(gameboard->getBoard()[posRow - 1][posCol] == NULL){
            posRow = posRow - 1;
        } else if(posRow == 0 && gameboard->getBoard()[posRow - 2][posCol] == NULL){
            posRow = posRow - 2;
        } else {
            return;
        }
    }
    this->setPosition(((1000/3)*(posCol + 1)) - (1000/6), ((1000/3)*(posRow + 1)) - (1000/6));
}

int selector::getPosRow(){
    return posRow;
}

int selector::getPosCol(){
    return posCol;
}

