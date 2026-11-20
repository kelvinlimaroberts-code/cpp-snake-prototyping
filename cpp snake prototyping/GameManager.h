#pragma once
#include "Snake.h"
#include "Map_t.h"

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
	void FactorCollisions(short2 nextPos);
	void PrintItem(short2);
	void GenerateRandomPos(short2&);
	void RegenerateApple();

	//map
	Map_t map;
	//inputs
	char lastKeyPress = ' ';
	InputValue lastValidInput = INPUT_NONE;
	//player
	Snake_t player;

};

