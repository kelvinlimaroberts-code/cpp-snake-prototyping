#pragma once
#include "Tile_t.h"

//https://www.geeksforgeeks.org/cpp/cpp-linked-list/

class Snake_t
{
public:
	Snake_t();
	~Snake_t();

	void operator++();
	void operator--();
private:
	void GetTail(Segment_t* tail);
	Segment_t* mpHead = nullptr;

	
};



