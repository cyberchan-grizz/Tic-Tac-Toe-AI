//
//  board.hpp
//  Tic-Tac-Toe
//
//  Created by Channing Christian on 8/28/20.
//  Copyright © 2020 Channing Christian. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

#endif /* board_hpp */

class board{
private:
    std::vector<std::vector<int>> gameboard;
    std::vector<int> choices;
    
public:
    board();
    std::vector<std::vector<int>> getBoard();
    void markSpot(int spot, std::string player);
    bool checkX();
    bool checkO();
    bool checkTie();
    void removeChoice(int choice);
    void addChoice(int choice);
    std::vector<int> getChoices();
};
