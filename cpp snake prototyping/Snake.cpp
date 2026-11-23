#include "Snake.h"

Snake_t::Snake_t()
{
	mpHead = new Segment_t(nullptr);
	mpHead->SetID(SNAKE_HEAD);
}

Snake_t::~Snake_t()
{
    while (GetTail()->pPrevSegment != nullptr) //check if the segment is the head
    {
        --*this;   //delete everything in linked list
    }
	delete mpHead;      //delete head
	mpHead = nullptr;
}

Snake_t& Snake_t::operator++() 
{
	Segment_t* tail = GetTail();
	tail->pNextSegment = new Segment_t(tail);
    return *this;

}

Snake_t& Snake_t::operator--() 
{
	Segment_t* penultimatePiece = GetTail()->pPrevSegment;
	delete penultimatePiece->pNextSegment;
	penultimatePiece->pNextSegment = nullptr;
    return *this;
}

void Snake_t::MoveSnake(const short2& pos, Map_t& m)
{
    //work from head down the linked list
    mpHead->SetPos(pos);                                //object update head pos
    m.IdentifyAsItem(SNAKE_HEAD, pos);                  //map register head
    if (mpHead->pNextSegment != nullptr)                //if its not just the head
    {
        m.UnidentifyItem(mpHead->GetPrevPos());         //map deregister previous head position
        m.IdentifyAsItem(SNAKE_BODY, mpHead->GetPrevPos());//map register previous position as snake body
    }
    Segment_t& index = *mpHead;
    while (index.pNextSegment != nullptr)               //for the rest of the segments
    {
        //update the position of the next one with the previous position of the current selected
        index.pNextSegment->SetPos(index.GetPrevPos());
        //TODO:: change index
    }
    m.UnidentifyItem(index.GetPrevPos());               //map deregister snake tail tip
}

bool Snake_t::ValidSnakeMovement(short2& desiredNewPos)
{
    if (direction != NO_DIR)
    {
        desiredNewPos = mpHead->GetPos();
        switch (direction)
        {
        case UP_DIR:
            desiredNewPos.x--;
            break;
        case LEFT_DIR:
            desiredNewPos.y--;
            break;
        case RIGHT_DIR:
            desiredNewPos.y++;
            break;
        case DOWN_DIR:
            desiredNewPos.x++;
            break;
        default:
            break;
        }

        return true;
    }
    else
    {
        return false;
    }
}

int Snake_t::GetScore()
{
    return score;
}

bool& Snake_t::HasLife()
{
    return snakeAlive;
}

DirectionValue& Snake_t::GetDirection()
{
    return direction;
}

Segment_t* Snake_t::GetTail()
{
    Segment_t* pIndex = mpHead;                 //use this to read/write to list
    while (pIndex->pNextSegment != nullptr)     //does a segment have no more after it?
    {
        pIndex = pIndex->pNextSegment;			//go to next one, if there is one
    }
    return pIndex;								//return pointer to final segment object
}

