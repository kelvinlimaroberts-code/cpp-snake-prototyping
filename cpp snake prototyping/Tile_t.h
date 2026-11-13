#pragma once
#include "Contants.h"
class Tile_t
{
public:
	//Tile_t();
	//~Tile_t();
	const GridItem& GetID() const;
	void SetID(GridItem i);
	const char GetDisplayValue() const;
private:
	GridItem id = EMPTY;
	char displayValue = ' ';
};







