//
//  board.cpp
//  Tic-Tac-Toe
//
//  Created by Channing Christian on 8/28/20.
//  Copyright © 2020 Channing Christian. All rights reserved.
//

#include "board.hpp"

using namespace std;

board::board(){
    for(int i = 0; i < 3; i++){
        std::vector<int> temp;
        this->gameboard.push_back(temp);
    }
    
    for(int i = 0; i < 3; i++){
        for(int n = 0; n < 3; n++){
            this->gameboard[i].push_back(NULL);
        }
    }
    
    choices = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void board::markSpot(int spot, std::string player){
    int * playerNum = new int(NULL);
    if(player == "x"){
        playerNum = new int(1);
    } else if (player == "o"){
        playerNum = new int(2);
    } else if (player == "NULL"){
        playerNum = new int(0);
    }
    
    int * num1 = new int(std::ceil((float)spot/this->gameboard.size())-1);
    int * num2 = new int((int)spot - (this->gameboard.size() * *num1) - 1);
    
    if(this->gameboard[*num1][*num2] == 0){
        this->gameboard[*num1][*num2] = *playerNum;
    } else if(*playerNum == 0){
        this->gameboard[*num1][*num2] = *playerNum;
    }
    
    delete playerNum;
    delete num1;
    delete num2;
}

bool board::checkX(){
    //check horizontal
    for(int i = 0; i < gameboard.size(); i++){
        if(std::count(gameboard[i].begin(), gameboard[i].end(), 1) == 3){
            return true;
        }
    }
    
    //check vertical
    std::vector<int> * temp = new std::vector<int>();
    for(int i = 0; i < gameboard.size(); i++){
        for(int  n = 0; n < gameboard.size(); n++){
            temp->push_back(gameboard[n][i]);
        }
        if(std::count(temp->begin(), temp->end(), 1) == 3){
            delete temp;
            return true;
        }
        temp->clear();
    }
    temp->clear();
    
    //check up-down vertical
    for(int i = 0; i < gameboard.size(); i++){
        temp->push_back(gameboard[i][i]);
    }
    if(std::count(temp->begin(), temp->end(), 1) == 3){
        delete temp;
        return true;
    }
    temp->clear();
    
    //check down-up vertical
    for(int i = 2; i <= 0; i--){
        temp->push_back(gameboard[i][i]);
    }
    if(std::count(temp->begin(), temp->end(), 1) == 3){
        delete temp;
        return true;
    }
    
    delete temp;
    return false;
}

bool board::checkO(){
    //check horizontal
    for(int i = 0; i < gameboard.size(); i++){
        if(std::count(gameboard[i].begin(), gameboard[i].end(), 2) == 3){
            return true;
        }
    }
    
    //check vertical
    std::vector<int> * temp = new std::vector<int>();
    for(int  i = 0; i < gameboard.size(); i++){
        for(int n = 0; n < gameboard.size(); n++){
            temp->push_back(gameboard[n][i]);
        }
        if(std::count(temp->begin(), temp->end(), 2) == 3){
            delete temp;
            return true;
        }
        temp->clear();
    }
    temp->clear();
    
    //check up-down vertical
    for(int i = 0; i < gameboard.size(); i++){
        temp->push_back(gameboard[i][i]);
    }
    if(std::count(temp->begin(), temp->end(), 2) == 3){
        delete temp;
        return true;
    }
    temp->clear();
    
    //check down-up vertical
    for(int i = 2; i <= 0; i--){
        temp->push_back(gameboard[i][i]);
    }
    if(std::count(temp->begin(), temp->end(), 2) == 3){
        delete temp;
        return true;
    }
    
    delete temp;
    return false;
}

bool board::checkTie(){
    if(this->checkO() == false && this->checkX() == false){
        for(std::vector<int> row : this->gameboard){
            if(std::count(row.begin(), row.end(), NULL) > 0){
                return false;
            }
        }
        return true;
    }
}

std::vector<std::vector<int>> board::getBoard(){
    return this->gameboard;
}

void board::removeChoice(int choice){
    for(int i = 0; i < choices.size(); i++){
        if(choices[i] == choice){
            choices.erase(choices.begin() + (i-1));
        }
    }
}

void board::addChoice(int choice){
    if(std::count(choices.begin(), choices.end(), choice) == 0){
        choices.push_back(choice);
    }
    sort(choices.begin(), choices.end());
}

std::vector<int> board::getChoices(){
    return choices;
}






