//
// Created by aaron on 4/18/2024.
//
#include <iostream>
#include <cctype>
#include "board.h"
#include "textureManager.h"
#include "tile.h"
#include <cstdlib>
#include <ctime>
#pragma once
using namespace std;

struct gameWindow {
    gameWindow(board& board, textureManager& textureManager, bool isExit) {
        if (!isExit) {
            sf::RenderWindow gWindow(sf::VideoMode((board.getcolNum()*32), ((board.getrowNum()*32)+100)), "Minesweeper", sf::Style::Close);
            tile t(textureManager.icons,0,0);
            vector<tile> tiles;
            for (int i = 0; i < board.getrowNum(); i++) {
                for (int j = 0; j < board.getcolNum(); j++) {
                    tiles.push_back(tile(textureManager.icons, j * 32, i * 32));
                }
            }
            srand(time(nullptr));
            int numMines = 0;
            while (numMines < board.getMine()) {
                int randRow = rand() % board.getrowNum();
                int randCol = rand() % board.getcolNum();
                int index = randRow * board.getcolNum() + randCol;
                if (!tiles[index].isMine) {
                    tiles[index].isMine = true;
                    numMines++;
                }
            }
            while (gWindow.isOpen()) {
                sf::Event event;
                sf::Mouse mouse;
                while (gWindow.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        gWindow.close();
                    }
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            //t.tileClicked(mouse.getPosition(gWindow).x,mouse.getPosition(gWindow).y);
                            for (int i = 0; i < tiles.size(); i++) {
                                if (tiles[i].back.getGlobalBounds().contains(mouse.getPosition(gWindow).x,mouse.getPosition(gWindow).y) && !tiles[i].isFlagged) {
                                    tiles[i].isRevealed = true;
                                }
                            }
                        }
                        if (event.mouseButton.button == sf::Mouse::Right) {
                            for (int i = 0; i < tiles.size(); i++) {
                                if (!tiles[i].isRevealed && tiles[i].back.getGlobalBounds().contains(mouse.getPosition(gWindow).x,mouse.getPosition(gWindow).y)) {
                                    tiles[i].isFlagged = !tiles[i].isFlagged;
                                }
                            }
                        }
                    }
                }
                gWindow.clear(sf::Color::White);
                for (int i = 0; i < tiles.size(); i++) {
                    tiles[i].draw(gWindow);
                }
                gWindow.display();
            }
        }
    }
};

#ifndef MINESWEEPER_GAMEWINDOW_H
#define MINESWEEPER_GAMEWINDOW_H

#endif //MINESWEEPER_GAMEWINDOW_H
