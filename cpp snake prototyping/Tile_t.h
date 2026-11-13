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


class Segment_t : public Tile_t
{
public:
	Segment_t();
	void SetPos(short2 newPos);
	const short2 GetPos() const;
	const short2 GetPrev() const;

private:
	short2 pos = { 0,0 };
	short2 prevPos = pos;
};






