//
// Created by aaron on 4/18/2024.
//

#include <iostream>
#include <cctype>
#include "board.h"
#include "textureManager.h"
#pragma once
using namespace std;

struct tile {
    bool isRevealed;
    bool isFlagged;
    bool isMine;
    vector<tile*> neighbors;
    sf::Sprite back;
    sf::Sprite front;
    sf::Sprite icon;
    sf::Sprite flag;

    map<string,sf::Texture> textures;

    tile(map<string,sf::Texture>& textures, float xpos, float ypos) {
        back.setPosition(xpos, ypos);
        front.setPosition(xpos, ypos);
        icon.setPosition(xpos,ypos);
        flag.setPosition(xpos,ypos);

        back.setTexture(textures["tile_revealed"]);
        front.setTexture(textures["tile_hidden"]);
        flag.setTexture(textures["flag"]);

        //flag.setColor(sf::Color(255,255,255,0));
        isRevealed = false;
        isFlagged = false;
        isMine = false;
        this->textures = textures;
    }

//    bool tileClicked(float positionx, float positiony) {
//        if(back.getGlobalBounds().contains(positionx,positiony)) {
//            cout << isRevealed << "The tile has been revealed" << endl;
//            this->isRevealed = true;
//            return true;
//        }
//        return false;
//    }

    void draw(sf::RenderWindow& window) {
        if (!isRevealed) {
            window.draw(front);
        }
        else if (isRevealed){
            window.draw(back);
        }
        if (isFlagged) {
            window.draw(flag);
        }
        if (isMine && isRevealed) {
            icon.setTexture(textures["mine"]);
            window.draw(icon);
        }
    }
};

#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

#endif //MINESWEEPER_TILE_H
