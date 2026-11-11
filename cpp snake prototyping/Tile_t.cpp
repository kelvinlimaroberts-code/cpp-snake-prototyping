#include "Tile_t.h"

GridItem Tile_t::GetID()
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
	case (PLAYER_HEAD):
		displayValue = 'P';
		break;
	case (PLAYER_BODY):
		displayValue = 'p';
		break;
	default:
		displayValue = 'x';
	}
}

char Tile_t::GetDisplayValue()
{
	return displayValue;
}
