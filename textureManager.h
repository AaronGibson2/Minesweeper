//
// Created by aaron on 4/18/2024.
//
#include <iostream>
#include <map>
using namespace std;
#include <SFML/Graphics.hpp>
#pragma once

struct textureManager {
    map<string, sf::Texture> icons;
    textureManager() {
        sf::Texture temp;
        temp.loadFromFile("images/debug.png");
        icons.emplace("debug",temp);
        temp.loadFromFile("images/digits.png");
        icons.emplace("digits", temp);
        temp.loadFromFile("images/face_happy.png");
        icons.emplace("happy",temp);
        temp.loadFromFile("images/face_lose.png");
        icons.emplace("lose",temp);
        temp.loadFromFile("images/face_win.png");
        icons.emplace("win", temp);
        temp.loadFromFile("images/flag.png");
        icons.emplace("flag",temp);
        temp.loadFromFile("images/leaderboard.png");
        icons.emplace("leaderboard",temp);
        temp.loadFromFile("images/mine.png");
        icons.emplace("mine",temp);
        temp.loadFromFile("images/number_1.png");
        icons.emplace("number_1",temp);
        temp.loadFromFile("images/number_2.png");
        icons.emplace("number_2",temp);
        temp.loadFromFile("images/number_3.png");
        icons.emplace("number_3",temp);
        temp.loadFromFile("images/number_4.png");
        icons.emplace("number_4",temp);
        temp.loadFromFile("images/number_5.png");
        icons.emplace("number_5",temp);
        temp.loadFromFile("images/number_6.png");
        icons.emplace("number_6",temp);
        temp.loadFromFile("images/number_7.png");
        icons.emplace("number_7",temp);
        temp.loadFromFile("images/number_8.png");
        icons.emplace("number_8",temp);
        temp.loadFromFile("images/pause.png");
        icons.emplace("pause",temp);
        temp.loadFromFile("images/play.png");
        icons.emplace("play",temp);
        temp.loadFromFile("images/tile_hidden.png");
        icons.emplace("tile_hidden",temp);
        temp.loadFromFile("images/tile_revealed.png");
        icons.emplace("tile_revealed",temp);
    }
};


#ifndef MINESWEEPER_TEXTUREMANAGER_H
#define MINESWEEPER_TEXTUREMANAGER_H

#endif //MINESWEEPER_TEXTUREMANAGER_H
