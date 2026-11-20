#pragma once
//common data structures
struct short2
{
	short x;
	short y;
};


//MAP CONSTANTS
constexpr short tileSize = 10;

constexpr short gridSize = 22;


//TILE CONSTANTS
enum GridItem { EMPTY, WALL, APPLE, SNAKE_HEAD, SNAKE_BODY };

//direction
enum DirectionValue { NO_DIR, UP_DIR, LEFT_DIR, RIGHT_DIR, DOWN_DIR };




