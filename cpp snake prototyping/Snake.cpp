#include "Snake.h"

Snake_t::Snake_t()
{
	mpHead = new Segment_t(nullptr);
	mpHead->SetID(SNAKE_HEAD);
}

Snake_t::~Snake_t()
{
	delete mpHead;
	mpHead = nullptr;
}

void Snake_t::operator++()
{
	Segment_t& tail = GetTail();
	tail.pNextSegment = new Segment_t(tail);
}

void Snake_t::operator--()
{
	Segment_t* penultimatePiece = GetTail().pPrevSegment;
	delete penultimatePiece->pNextSegment;
	penultimatePiece->pNextSegment = nullptr;
}



Segment_t& Snake_t::GetTail()
{
	Segment_t* pIndex = mpHead; //use this to read/write to list
	while (pIndex->pNextSegment != nullptr)     //does a segment have no more after it?
	{
		pIndex = pIndex->pNextSegment;			//go to next one, if there is one
	}
	return *pIndex;								//return refernce to final segment object
}

