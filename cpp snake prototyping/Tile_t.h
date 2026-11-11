#pragma once
#include "Contants.h"
class Tile_t
{
public:
	//Tile_t();
	//~Tile_t();
	GridItem GetID();
	void SetID(GridItem i);
	char GetDisplayValue();
private:
	GridItem id = EMPTY;
	char displayValue = ' ';
};







