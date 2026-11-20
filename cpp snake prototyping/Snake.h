#pragma once
#include "Tile_t.h"

//https://www.geeksforgeeks.org/cpp/cpp-linked-list/
//https://www.geeksforgeeks.org/cpp/operator-overloading-cpp/

class Snake_t
{
public:
	Snake_t();
	~Snake_t();
	void MoveSnake(const short2&);
	bool ValidSnakeMovement(short2&);
	int GetScore();
	bool& HasLife();
	DirectionValue& GetDirection();

	Snake_t& operator++();
	Snake_t& operator--();
private:
	Segment_t& GetTail();
	Segment_t* mpHead = nullptr;

	bool snakeAlive = true;
	int score = 0;
	DirectionValue direction = NO_DIR;
};



