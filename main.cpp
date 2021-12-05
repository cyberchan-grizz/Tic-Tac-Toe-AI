
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Tic-Tac-Toe
// By Channing Christian

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;
using namespace sf;

#include "board.hpp"
#include "anamation.hpp"
#include "players.hpp"
#include "selector.hpp"
#include "bots.hpp"
#include "textBox.hpp"

int main()
{
    board * gameboard = new class board();
    board * gb = new class board();
    sf::Sprite board;
    sf::Texture boardTexture;
    boardTexture.loadFromFile("Textures /board.png");
    board.setTexture(boardTexture);
    board.setOrigin(250, 250);
    board.setPosition(500, 500);
    board.setScale(2, 2);
    
    Anamation * x_anamation = new class Anamation(55, 128, 128, 1024, 896);
    sf::Clock xDrawClock;
    double xDrawCount = 0;
    double xDrawTime = NULL;
    std::vector<Player*> xPlays;
    bool playerTurn = true;
    bool drawX;
    
    Anamation * o_anamation = new class Anamation(69, 128, 128, 1152, 1024);
    sf::Clock oDrawClock;
    double oDrawCount = 0;
    double oDrawTime = NULL;
    std::vector<Player*> oPlays;
    bool cpuTurn = false;
    bool drawO;
    
    selector * selector = new class selector("Textures /selector.png");
    sf::Clock selectorClock;
    double selectorTime = NULL;
    selector->setOrigin(64, 64);
    selector->setScale(2, 2);
    
    textBox * credits = new class textBox(new std::string("BearBox Gaming Studios"));
    credits->setPos(new double(0), new double(0));
    credits->setSize(new double(1));
    
    textBox * title = new class textBox(new std::string("Tic-Tac-Toe"));
    title->setPos(new double(200), new double(350));
    title->setSize(new double(3));
    
    textBox * prompt = new class textBox(new std::string("press spacebar to continue"));
    prompt->setPos(new double(35), new double(600));
    prompt->setSize(new double(2));
    sf::Clock promptClock;
    double promptTime;
    
    textBox * winner = new class textBox(new std::string(""));
    winner->setPos(new double(200), new double(350));
    winner->setSize(new double(3));
    
    //basicBot * bot = new class basicBot();
    
    bool playing = false;
    bool startMenu = true;
    bool endMenu = false;
    
    
    //window is 1000 * 1000
    
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic-Tac-Toe");
    
    while(window.isOpen() == true){
        if(startMenu == true){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::KeyPressed){
                    switch(event.key.code){
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Space:
                            startMenu = false;
                            playing = true;
                            oPlays.clear();
                            xPlays.clear();
                            gameboard = new class board();
                            winner->setString(new std::string(""));
                            playerTurn = true;
                            cpuTurn = false;
                            drawX = false;
                            drawO = false;
                            break;
                    }
                }
            }
            window.clear();
            window.draw(credits->getText());
            window.draw(title->getText());
            
            promptTime = promptClock.getElapsedTime().asSeconds();
            if(promptTime > 0.5f){
                window.draw(prompt->getText());
                if(promptTime > 1){
                    promptClock.restart();
                }
            }
            window.display();
            
            
        } else if(playing == true){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::KeyPressed){
                    switch(event.key.code){
                        case sf::Keyboard::Escape:
                            window.close();
                        case sf::Keyboard::W:
                            selector->moveUp(gameboard);
                            break;
                        case sf::Keyboard::S:
                            selector->moveDown(gameboard);
                            break;
                        case sf::Keyboard::A:
                            selector->moveLeft(gameboard);
                            break;
                        case sf::Keyboard::D:
                            selector->moveRight(gameboard);
                            break;
                        case sf::Keyboard::Enter:
                            if(playerTurn == true){
                                int spot = (selector->getPosRow() * gameboard->getBoard().size()) + (selector->getPosCol() + 1);
                                if(gameboard->getBoard()[selector->getPosRow()][selector->getPosCol()] == 0){
                                    gameboard->markSpot(spot, "x");
                                    //gameboard->removeChoice(spot);
                                    xPlays.push_back(new class Player("Textures /x_still.png", "Textures /x_anamation.png", selector->getSprite().getPosition().x, selector->getSprite().getPosition().y));
                                    drawX = true;
                                    playerTurn = false;
                                    
                                    //display the board
                                    for(int i = 0; i < gameboard->getBoard().size(); i++){
                                        for(int n = 0; n < gameboard->getBoard().size(); n++){
                                            std::cout << gameboard->getBoard()[i][n];
                                        }
                                        std::cout << std::endl;
                                    }
                                    std::cout << std::endl;
                                }
                            }
                            break;
                    }
                }
            }
            
            //Bot implementation
            if(cpuTurn == true){
                proBot * bot = new proBot(gameboard);
                int * botChoice = new int(bot->getMove());
                if(gameboard->getBoard()[bot->getChoiceRow()][bot->getChoiceCol()] == 0){
                    gameboard->markSpot(*botChoice, "o");
                    delete botChoice;
                    oPlays.push_back(new class Player("Textures /o_still.png", "Textures /o_anamation.png", (((1000/3)*(bot->getChoiceCol() + 1)) - (1000/6)), ((1000/3)*(bot->getChoiceRow() + 1)) - (1000/6)));
                    drawO = true;
                    cpuTurn = false;
                    
                    //display the board
                    for(int i = 0; i < gameboard->getBoard().size(); i++){
                        for(int n = 0; n < gameboard->getBoard().size(); n++){
                            std::cout << gameboard->getBoard()[i][n];
                        }
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }
                delete bot;
            }
            
            //drawing and anamation
            if(drawX == true){
                xDrawTime = xDrawClock.getElapsedTime().asSeconds();
                if(xDrawTime > 0.05f){
                    if(xDrawCount <= x_anamation->getAnamationLength()){
                        xDrawCount++;
                        xPlays[xPlays.size() - 1]->setFrame(x_anamation->getFrame(xDrawCount));
                    } else {
                        xPlays[xPlays.size() - 1]->setTexture("still");
                        xPlays[xPlays.size() - 1]->setFrame(sf::IntRect{0, 0, 128, 128});
                        xDrawCount = 0;
                        drawX = false;
                        cpuTurn = true;
                    }
                    xDrawClock.restart();
                }
            }
            
            if(drawO == true){
                oDrawTime = oDrawClock.getElapsedTime().asSeconds();
                if(oDrawTime > 0.05f){
                    if(oDrawCount <= o_anamation->getAnamationLength()){
                        oDrawCount++;
                        oPlays[oPlays.size() - 1]->setFrame(o_anamation->getFrame(oDrawCount));
                    } else {
                        oPlays[oPlays.size() - 1]->setTexture("still");
                        oPlays[oPlays.size() - 1]->setFrame(sf::IntRect{0, 0, 128, 128});
                        oDrawCount = 0;
                        drawO = false;
                        playerTurn = true;
                    }
                    oDrawClock.restart();
                }
            }
            
            if(gameboard->checkTie()){
                cpuTurn = false;
                playerTurn = false;
                winner->setString(new std::string("it's a tie"));
                if(drawO == false && drawX == false){
                    playing = false;
                    endMenu = true;
                }
            } else if (gameboard->checkX()){
                cpuTurn = false;
                playerTurn = false;
                winner->setString(new std::string("red wins!"));
                if(drawO == false && drawX == false){
                    playing = false;
                    endMenu = true;
                }
            } else if (gameboard->checkO()){
                cpuTurn = false;
                playerTurn = false;
                winner->setString(new std::string("blue wins!"));
                if(drawO == false && drawX == false){
                    playing = false;
                    endMenu = true;
                }
            }
            
            window.clear();
            
            for(int i = 0; i < xPlays.size(); i++){
                window.draw(xPlays[i]->getSprite());
            }
            
            for(int i = 0; i < oPlays.size(); i++){
                window.draw(oPlays[i]->getSprite());
            }
            
            if(drawX != true && drawO != true){
                selectorTime = selectorClock.getElapsedTime().asSeconds();
                if(selectorTime > 0.5){
                    window.draw(selector->getSprite());
                    if(selectorTime > 1){
                        selectorClock.restart();
                    }
                    
                }
            }
            
            window.draw(board);
            window.display();
        } else if (endMenu == true){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::KeyPressed){
                    switch(event.key.code){
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Space:
                            startMenu = true;
                            endMenu = false;
                            break;
                    }
                }
            }
            window.clear();
            window.draw(winner->getText());
            promptTime = promptClock.getElapsedTime().asSeconds();
            if(promptTime > 0.5f){
                window.draw(prompt->getText());
                if(promptTime > 1){
                    promptClock.restart();
                }
            }
            window.display();
        }
    }
}
