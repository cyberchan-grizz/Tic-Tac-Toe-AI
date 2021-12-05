//
//  bots.cpp
//  
//
//  Created by Channing Christian on 9/1/20.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "board.hpp"

using namespace std;
using namespace sf;

#include "bots.hpp"

random_device rd;


//----------------------------------------BASIC BOT IMPLEMENTATION-----------------------------------

int basicBot::getChoice(board * gameboard, std::vector<int> choices){
    std::vector<int> temp;
    choiceRow = -1;
    choiceCol = -1;
    
    //check accross for spots
    for(int i = 0; i < gameboard->getBoard().size(); i++){
        for(int n = 0; n < gameboard->getBoard().size(); n++){
            temp.push_back(gameboard->getBoard()[i][n]);
        }
        if(std::count(temp.begin(), temp.end(), 2) == 2){
            if(std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
                for(int n = 0; n < gameboard->getBoard().size(); n++){
                    if(gameboard->getBoard()[i][n] == 0){
                        choiceRow = i;
                        choiceCol = n;
                        break;
                    }
                }
            }
        } else if (std::count(temp.begin(), temp.end(), 1) == 2){
            if(std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
                for(int n = 0; n < gameboard->getBoard().size(); n++){
                    if(gameboard->getBoard()[i][n] == 0){
                        choiceRow = i;
                        choiceCol = n;
                        break;
                    }
                }
            }
        }
        temp.clear();
    }
    if(choiceRow != -1 && choiceCol != -1){
        choice = (choiceRow * gameboard->getBoard().size()) + (choiceCol + 1);
        if(std::count(choices.begin(), choices.end(), choice) > 0){
            return choice;
        }
    }
    temp.clear();
        
    //check down for spots
    for(int i = 0; i < gameboard->getBoard().size(); i++){
        for(int n = 0; n < gameboard->getBoard().size(); n++){
            temp.push_back(gameboard->getBoard()[n][i]);
        }
        
        if(std::count(temp.begin(), temp.end(), 2) == 2 && std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
            for(int n = 0; n < temp.size(); n++){
                if(temp.at(n) == 0){
                    choiceRow = n;
                    choiceCol = i;
                    break;
                }
            }
        } else if (std::count(temp.begin(), temp.end(), 1) == 2 && std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
            for(int n = 0; n < temp.size(); n++){
                if(temp.at(n) == 0){
                    choiceRow = n;
                    choiceCol = i;
                    break;
                }
            }
        }
        temp.clear();
    }
    if(choiceRow != -1 && choiceCol != -1){
        choice = (choiceRow * gameboard->getBoard().size()) + (choiceCol + 1);
        if(std::count(choices.begin(), choices.end(), choice) > 0){
            return choice;
        }
    }
    temp.clear();
    
    //check up-down diagonal for spots
    for(int i = 0; i < gameboard->getBoard().size(); i++){
        temp.push_back(gameboard->getBoard()[i][i]);
    }
    
    if(std::count(temp.begin(), temp.end(), 2) == 2 && std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
        for(int i = 0; i < temp.size(); i++){
            if(temp.at(i) == 0){
                choiceRow = i;
                choiceCol = i;
                break;
            }
        }
    } else if (std::count(temp.begin(), temp.end(), 1) == 2 && std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
        for(int i = 0; i < temp.size(); i++){
            if(temp.at(i) == 0){
                choiceRow = i;
                choiceCol = i;
                break;
            }
        }
    }
    temp.clear();
    
    if(choiceRow != -1 && choiceCol != -1){
        choice = (choiceRow * gameboard->getBoard().size()) + (choiceCol + 1);
        if(std::count(choices.begin(), choices.end(), choice) > 0){
            return choice;
        }
    }
    
    //check down-up diagonal for spots
    for(int i = 2; i >= 0; i--){
        temp.push_back(gameboard->getBoard()[i][i]);
    }
    
    if(std::count(temp.begin(), temp.end(), 2) == 2 && std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
        for(int i = 0; i < temp.size(); i++){
            if(temp.at(i) == 0){
                choiceRow = i;
                choiceCol = i;
                break;
            }
        }
    } else if(std::count(temp.begin(), temp.end(), 1) == 2 && std::count(temp.begin(), temp.end(), 2) + std::count(temp.begin(), temp.end(), 1) != 3){
        for(int i = 0; i < temp.size(); i++){
            if(temp.at(i) == 0){
                choiceRow = i;
                choiceCol = i;
                break;
            }
        }
    }
    
    if(choiceRow != -1 && choiceCol != -1){
        choice = (choiceRow * gameboard->getBoard().size()) + (choiceCol + 1);
        if(std::count(choices.begin(), choices.end(), choice) > 0){
            return choice;
        }
    }
    
    choice = choices[rd() % (choices.size() - 1)];
    choiceRow = std::ceil((float)choice/gameboard->getBoard().size()) - 1;
    choiceCol = choice - (gameboard->getBoard().size() * choiceRow) - 1;
    
    if(choiceRow != -1 && choiceCol != -1){
        if(std::count(choices.begin(), choices.end(), choice) > 0){
            return choice;
        }
    }
}

int basicBot::getChoiceRow(){
    return choiceRow;
}

int basicBot::getChoiceCol(){
    return choiceCol;
}


//-------------------------------------PRO BOT IMPLEMENTATION----------------------------------

proBot::proBot(board * gameboard){
    for(int i = 0; i < gameboard->getBoard().size(); i++){
        for(int n = 0; n < gameboard->getBoard().size(); n++){
            int * spot = new int((i*3) + (n+1));
            if(gameboard->getBoard()[i][n] == 1){
                this->gameboard->markSpot(*spot, "x");
                this->gameboard->removeChoice(*spot);
            } else if(gameboard->getBoard()[i][n] == 2){
                this->gameboard->markSpot(*spot, "o");
                this->gameboard->removeChoice(*spot);
            }
            delete spot;
        }
    }
}

int proBot::getChoice(std::string * playerTurn){
    int maxsf = -INFINITY;
    int minsf = INFINITY;
    int bestMoveSoFar = 0;
    
    if(this->gameboard->checkO() == true){
        return 10;
    } else if (this->gameboard->checkX() == true){
        return -10;
    } else if (this->gameboard->checkTie() == true){
        return 0;
    }
    
    for(int choice : this->gameboard->getChoices()){
        this->gameboard->markSpot(choice, *playerTurn);
        this->gameboard->removeChoice(choice);
        
        for(std::vector<int> row : this->gameboard->getBoard()){
            for(int num : row){
                std::cout << num;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        for(int choice : this->gameboard->getChoices()){
            std::cout << choice;
        }
        std::cout << endl;
        std::cout << endl;
        
        if(*playerTurn == "o"){
            int score = (this->getChoice(new std::string("x")));
            
            if(score > maxsf){
                maxsf = score;
                bestMoveSoFar = choice;
            }
            
        } else {
            int score = (this->getChoice(new std::string("o")));
            
            if(score < minsf){
                minsf = score;
            }
        }
        this->gameboard->markSpot(choice, "NULL");
        this->gameboard->addChoice(choice);
    }
    
    this->choice = bestMoveSoFar;
    this->choiceCol = choice - (this->gameboard->getBoard().size() * choiceRow) - 1;
    this->choiceRow = std::ceil((float)choice/this->gameboard->getBoard().size()) - 1;
    
    if(*playerTurn == "x"){
        delete playerTurn;
        return minsf;
    } else {
        delete playerTurn;
        return maxsf;
    }
}

int proBot::getMove(){
    this->getChoice(new std::string("o"));
    delete gameboard;
    return this->choice;
}

int proBot::getChoiceRow(){
    return choiceRow;
}

int proBot::getChoiceCol(){
    return choiceCol;
}
