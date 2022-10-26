#pragma once
#include <cstdint>

// all constants values are in pixels
#define TETRIS_FRAMES_DELAY_MS 200

// DO NOT TOUCH IT
#define TETRIS_BLOCK_W 21
#define TETRIS_BLOCK_H 21

#define TETRIS_BLOCK_AMOUNT_ROW 15
#define TETRIS_BLOCK_AMOUNT_COL 30

#define TETRIS_FIGURE_BLOCK_AMOUNT_COL 4 //height
#define TETRIS_FIGURE_BLOCK_AMOUNT_ROW 2 //width

#define TEXTURE_PATH "C:\\Projects\\cpp\\Tetris\\images\\bricks.PNG"

#define TETRIS_FIGURE_BLOCK_AMOUNT 4

// (TETRIS_FIGURE_BLOCK_AMOUNT_COL*TETRIS_FIGURE_BLOCK_AMOUNT_ROW) // block amount (width * height)

#define TETRIS_FIGURE_VERTICAL_SPEED_PX 0.05

// top left gamefield point (actually a top and left margin)
#define TETRIS_GAMEFIELD_X 0
#define TETRIS_GAMEFIELD_Y 0

// bottom right gamefield point (actually the width and height)
#define TETRIS_GAMEFIELD_W (TETRIS_BLOCK_W * TETRIS_BLOCK_AMOUNT_ROW)
#define TETRIS_GAMEFIELD_H (TETRIS_BLOCK_H * TETRIS_BLOCK_AMOUNT_COL)

#define TETRIS_APP_WIDTH TETRIS_GAMEFIELD_W
#define TETRIS_APP_HEIGHT TETRIS_GAMEFIELD_H

// control buttons
#define TETRIS_RIGHT Keyboard::Right
#define TETRIS_LEFT Keyboard::Left
#define TETRIS_ROTATE Keyboard::Up
#define TETRIS_FORCE_DOWN Keyboard::Down

// don't forget to include SFML header with Color class
#define TETRIS_BACKGROUND_COLOR sf::Color::Green

#define TETRIS_SLEEP_MS 20