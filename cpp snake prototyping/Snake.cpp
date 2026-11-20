#include "Snake.h"

Snake_t::Snake_t()
{
	mpHead = new Segment_t();
	mpHead->SetID(SNAKE_HEAD);
}

Snake_t::~Snake_t()
{
	delete mpHead;
	mpHead = nullptr;
}

void Snake_t::GetTail(Segment_t* tail)
{
	Segment_t* pIndex = mpHead; //use this to read/write to list
	while (pIndex != nullptr)
	{
		pIndex = pIndex->pNextSegment;
	}
	tail = pIndex;
}

