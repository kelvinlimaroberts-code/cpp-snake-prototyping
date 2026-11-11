#pragma once
#include "Tile_t.h"
class GameManager_t
{
public:
	GameManager_t();
	//~GameManager_t();
	void Update();
	void Render();
	bool IsGameRunning();
	void SetGameToRun(bool run);
private:
	bool gameRunning = true;
	Tile_t mapGrid[gridSize][gridSize];
	bool appleEaten = true;

	GridItem GetIdentityOfItem(int x, int y);
	void IdentifyAsItem(GridItem item, int x, int y);
	void UnidntifyItem(int x, int y);
	void PrintItem(int x, int y);
	void GenerateRandomPos(int& x, int& y);
	void RegenerateApple();

	
};

