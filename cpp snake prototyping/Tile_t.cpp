#include "Tile_t.h"

const GridItem& Tile_t::GetID() const 
{
	return id;
}

void Tile_t::SetID(GridItem i)
{
	id = i;
	switch (id)
	{
	case (EMPTY):
		displayValue = ' ';
		break;
	case (WALL):
		displayValue = 'W';
		break;
	case (APPLE):
		displayValue = 'a';
		break;
	case (SNAKE_HEAD):
		displayValue = 'S';
		break;
	case (SNAKE_BODY):
		displayValue = 's';
		break;
	default:
		displayValue = 'x';
	}
}

const char Tile_t::GetDisplayValue() const
{
	return displayValue;
}
