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
	Segment_t& GetTail();
	Segment_t* mpHead = nullptr;

	
};



