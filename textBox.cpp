//
//  textBox.cpp
//  theMotherFuckers
//
//  Created by Channing Christian on 12/22/19.
//  Copyright © 2019 Channing Christian. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "textBox.hpp"
using namespace std;

textBox::textBox(std::string * msg)
{
    font.loadFromFile("Fonts/upheavtt.ttf");
    text.setFont(font);
    text.setString(* msg);
    text.setFillColor(sf::Color::White);
    delete msg;
}

void textBox::setString(std::string * string)
{
    text.setString(* string);
    delete string;
}

void textBox::setPos(double * x, double * y)
{
    text.setPosition(*x, *y);
    delete x;
    delete y;
}

void textBox::setSize(double * size)
{
    text.setScale(*size, *size);
    delete size;
}

void textBox::move(sf::Vector2f * movement)
{
    text.move(*movement);
    delete movement;
}

sf::Text textBox::getText()
{
    return text;
}
