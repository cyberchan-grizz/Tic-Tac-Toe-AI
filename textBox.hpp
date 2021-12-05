//
//  textBox.hpp
//  theMotherFuckers
//
//  Created by Channing Christian on 12/22/19.
//  Copyright © 2019 Channing Christian. All rights reserved.
//

#ifndef textBox_hpp
#define textBox_hpp

#include <stdio.h>

#endif /* textBox_hpp */

class textBox{
private:
    sf::Text text;
    sf::Font font;
public:
    textBox(std::string * msg);
    void setString(std::string * string);
    void setPos(double * x, double * y);
    void setSize(double * size);
    void move(sf::Vector2f * movement);
    sf::Text getText();
};
