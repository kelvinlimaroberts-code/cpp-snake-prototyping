#pragma once
#include "Tile_t.h"

enum InputValue
{
	INPUT_NONE,
	INPUT_A = 65,
	INPUT_D = 68,
	INPUT_S = 83,
	INPUT_W = 87,

	INPUT_a = 97,
	INPUT_d = 100,
	INPUT_s = 115,
	INPUT_w = 119
};

class GameManager_t
{
public:
	GameManager_t();
	//~GameManager_t();
	void Update();
	void Render();
	void InputKey();
	bool IsGameRunning();
private:
	//map
	bool gameRunning = true;
	Tile_t mapGrid[gridSize][gridSize];
	bool appleEaten = true;
	//inputs
	char lastKeyPress = ' ';
	InputValue lastValidInput = INPUT_NONE;
	enum DirectionValue {NO_DIR, UP_DIR, LEFT_DIR, RIGHT_DIR, DOWN_DIR};
	DirectionValue direction = NO_DIR;
	//player
	Segment_t segments[gridSize * gridSize];
	int amountSegments = 0;

	GridItem GetIdentityOfItem(short2);
	void IdentifyAsItem(GridItem item, short2);
	void UnidntifyItem(short2);
	void PrintItem(short2);
	void GenerateRandomPos(short2&);
	void RegenerateApple();
	void MoveSnake(short2);
	bool ValidSnakeMovement(short2&);
};

