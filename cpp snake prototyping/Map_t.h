#pragma once
#include "Tile_t.h"
class Map_t
{
public:
	Map_t();
	~Map_t();

	GridItem GetIdentityOfItem(short2);
	void IdentifyAsItem(GridItem item, short2);
	void UnidntifyItem(short2);
	bool& AppleEaten();
	char GetDisplayValueAt(short2 pos);

private:
	Tile_t mapGrid[gridSize][gridSize];
	bool appleEaten = true;
};



