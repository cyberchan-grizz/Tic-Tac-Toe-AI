//
//  bots.hpp
//  
//
//  Created by Channing Christian on 9/1/20.
//

#ifndef bots_hpp
#define bots_hpp

#include <stdio.h>

#endif /* bots_hpp */

class basicBot{
private:
    int choiceRow = -1;
    int choiceCol = -1;
    int choice = NULL;
    
public:
    int getChoice(board * gameboard, std::vector<int> choices);
    int getChoice1(board * gameboard, std::vector<int> choices);
    int getChoiceRow();
    int getChoiceCol();
};


class proBot{
private:
    int choiceRow = 0;
    int choiceCol = 0;
    int choice = NULL;
    
    board * gameboard = new class board();
    
public:
    proBot(board * gameboard);
    int getChoice(std::string * playerTurn);
    int getMove();
    int getChoiceRow();
    int getChoiceCol();
};
