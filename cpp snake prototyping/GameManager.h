#pragma once
#include "Tile_t.h"

enum InputValue
{
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
	InputValue lastValidInput = INPUT_W;
	enum DirectionValue {UP_DIR, LEFT_DIR, RIGHT_DIR, DOWN_DIR};
	DirectionValue direction = UP_DIR;
	//player



	GridItem GetIdentityOfItem(short x, short y);
	void IdentifyAsItem(GridItem item, short x, short y);
	void UnidntifyItem(short x, short y);
	void PrintItem(short x, short y);
	void GenerateRandomPos(short& x, short& y);
	void RegenerateApple();
	void PlacePlayer(short x, short y);
};

