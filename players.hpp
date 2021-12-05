//
//  players.hpp
//  Tic-Tac-Toe
//
//  Created by Channing Christian on 8/31/20.
//  Copyright © 2020 Channing Christian. All rights reserved.
//

#ifndef players_hpp
#define players_hpp

#include <stdio.h>

#endif /* players_hpp */


class Player{
private:
    sf::Sprite sprite;
    sf::Texture drawTexture;
    sf::Texture stillTexture;
    
public:
    Player(std::string stillTexturePath, std::string drawTexturePath, double positionX, double positionY);
    void setOrigin(double x, double y);
    void setScale(double width, double height);
    void setPosition(double x, double y);
    
    sf::Sprite getSprite();
    void setTexture(std::string tex);
    
    void setFrame(sf::IntRect frame);
};

