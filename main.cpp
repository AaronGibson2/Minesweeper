#include <iostream>
#include <SFML/Graphics.hpp>
#include "welcomeWindow.h"
#include "gameWindow.h"
#include "board.h"
using namespace std;

int main() {
    board board;
    readBoard(board);
    welcomeWindow window(board);
    textureManager textureManager;
    gameWindow gWindow(board, textureManager, board.isExit);


    //sf::RenderWindow leaderboardWindow(sf::VideoMode((board.getcolNum())*16, (board.getrowNum()*16)+50), "Minesweeper", sf::Style::Close);
    return 0;
}