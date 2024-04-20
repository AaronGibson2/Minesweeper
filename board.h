//
// Created by aaron on 4/15/2024.
//
#include <iostream>
#include <fstream>
#pragma once
using namespace std;

struct board {
    int colNum;
    int rowNum;
    int mineNum;
    bool isExit;

    void setcolNum(int colNum) {
        this->colNum = colNum;
    }
    void setrowNum(int rowNum) {
        this->rowNum = rowNum;
    }
    void setMine(int mine) {
        this->mineNum = mine;
    }

    int getcolNum() {
        return this->colNum;
    }
    int getrowNum() {
        return this->rowNum;
    }
    int getMine() {
        return this->mineNum;
    }
};

void readBoard(board& board) {
    string line;
    ifstream infile("config.cfg");
    getline(infile, line);
    board.setcolNum(stoi(line));
    getline(infile, line);
    board.setrowNum(stoi(line));
    getline(infile, line);
    board.setMine(stoi(line));
    infile.close();
}



#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#endif //MINESWEEPER_BOARD_H
