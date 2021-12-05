//
//  selector.hpp
//  Tic-Tac-Toe
//
//  Created by Channing Christian on 8/31/20.
//  Copyright © 2020 Channing Christian. All rights reserved.
//

#ifndef selector_hpp
#define selector_hpp

#include <stdio.h>

#endif /* selector_hpp */

class selector{
private:
    sf::Sprite sprite;
    sf::Texture selectorTexture;
    int posRow;
    int posCol;
    
public:
    selector(std::string selectorTexturePath);
    void setOrigin(double x, double y);
    void setScale(double width, double height);
    void setPosition(double x, double y);
    
    void moveLeft(board * gameboard);
    void moveRight(board * gameboard);
    void moveUp(board * gameboard);
    void moveDown(board * gameboard);
    
    sf::Sprite getSprite();
    int getPosRow();
    int getPosCol();
};
