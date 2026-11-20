#pragma once
#include "Snake.h"

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
	void OutputDeathMessage();
	bool IsGameRunning();
private:
	//map
	Tile_t mapGrid[gridSize][gridSize];
	bool appleEaten = true;
	//inputs
	char lastKeyPress = ' ';
	InputValue lastValidInput = INPUT_NONE;
	//player
	Snake_t player;
	

	GridItem GetIdentityOfItem(short2);
	void IdentifyAsItem(GridItem item, short2);
	void UnidntifyItem(short2);
	void PrintItem(short2);
	void GenerateRandomPos(short2&);
	void RegenerateApple();
};

