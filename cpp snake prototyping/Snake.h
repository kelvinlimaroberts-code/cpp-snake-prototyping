#pragma once
#include "Tile_t.h"

//https://www.geeksforgeeks.org/cpp/cpp-linked-list/

class Snake_t
{
public:
	Snake_t();
	~Snake_t();
	void MoveSnake(const short2&);
	bool ValidSnakeMovement(short2&);
	int GetScore();
	bool IsSnakeAlive();
	DirectionValue& GetDirection();

	void operator++();
	void operator--();
private:
	Segment_t& GetTail();
	Segment_t* mpHead = nullptr;

	bool snakeAlive = true;
	Segment_t segments[gridSize * gridSize];
	int amountSegments = 0;
	int score = 0;
	DirectionValue direction = NO_DIR;
};



