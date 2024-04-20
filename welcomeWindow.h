//
// Created by aaron on 4/17/2024.
//
#include <iostream>
#include <cctype>
#include "board.h"
#pragma once
using namespace std;

void setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x,y));
}

struct welcomeWindow {
    sf::Font font;

    welcomeWindow(board& board) {
        font.loadFromFile("font.ttf");
        sf::RenderWindow fWindow(sf::VideoMode((board.getcolNum()*32), ((board.getrowNum()*32)+100)), "Minesweeper", sf::Style::Close);

        sf::Text text1("WELCOME TO MINESWEEPER!", font);
        text1.setCharacterSize(24);
        text1.setStyle(sf::Text::Bold);
        text1.setStyle(sf::Text::Underlined);
        setText(text1, (board.getcolNum()*32)/2.0f,(((board.getrowNum()*32)+100)/2.0f)-150);

        sf::Text text2("Enter your name:", font);
        text2.setCharacterSize(20);
        text2.setStyle(sf::Text::Bold);
        setText(text2, (board.getcolNum()*32)/2.0f,(((board.getrowNum()*32)+100)/2.0f)-75);

        string username;
        sf::Text userText;
        userText.setFont(font);
        userText.setCharacterSize(18);
        userText.setStyle(sf::Text::Bold);
        userText.setFillColor(sf::Color::Yellow);
        setText(userText, (board.getcolNum()*32)/2.0f,(((board.getrowNum()*32)+100)/2.0f)-45);

        sf::Text cursorText("|", font);
        cursorText.setCharacterSize(18);
        cursorText.setStyle(sf::Text::Bold);
        cursorText.setFillColor(sf::Color::Yellow);
        setText(cursorText, (board.getcolNum()*32)/2.0f,(((board.getrowNum()*32)+100)/2.0f)-45);

        while (fWindow.isOpen()) {
            sf::Event event;
            while (fWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    fWindow.close();
                    board.isExit = true;
                }
                if (event.type == sf::Event::TextEntered) {
                    if (isalpha(event.text.unicode) && event.text.unicode != 8 && username.length() < 10) {
                        char c = static_cast<char>(event.text.unicode);
                        if (username.empty()) {
                            c = toupper(c);
                        }
                        else {
                            c = tolower(c);
                        }
                        username += c;
                        userText.setString(username);
                        sf::FloatRect userRect = userText.getGlobalBounds();
                        userText.setPosition((board.getcolNum()*32 - userRect.width)/2.0f,(((board.getrowNum()*32)+100)/2.0f)-45);
                        cursorText.setPosition(userRect.left + userRect.width, userText.getPosition().y + userText.getCharacterSize() / 2.0f);
                    }
                    else if (event.text.unicode == 8 && !username.empty()) {
                        username.pop_back();
                        userText.setString(username);
                        sf::FloatRect userRect = userText.getGlobalBounds();
                        userText.setPosition((board.getcolNum()*32 - userRect.width)/2.0f,(((board.getrowNum()*32)+100)/2.0f)-45);
                        cursorText.setPosition(userRect.left + userRect.width + 10, userText.getPosition().y + userText.getCharacterSize() / 2.0f);
                    }
                    else if (event.text.unicode == 13 && !username.empty()) {
                        fWindow.close();
                    }
                }
            }

            fWindow.clear(sf::Color::Blue);
            fWindow.draw(text1);
            fWindow.draw(text2);
            fWindow.draw(cursorText);
            fWindow.draw(userText);
            fWindow.display();
        }
    }
};

#ifndef MINESWEEPER_WINDOW_H
#define MINESWEEPER_WINDOW_H

#endif //MINESWEEPER_WINDOW_H
