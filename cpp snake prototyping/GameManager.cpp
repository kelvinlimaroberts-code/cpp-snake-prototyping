#include "GameManager.h"
#include <cstdlib>      //for random
#include <ctime>        //for seed
#include <iostream>     //for cout

GameManager_t::GameManager_t()
{
    srand(time(0));   //generate seed
    //identify GRID items ON INIT
  
    //IDENTIFY walls
    for (short y = 0; y < gridSize; y++) //fill first and last rows as walls (y)
    {
        IdentifyAsItem(WALL, { 0, y });
        IdentifyAsItem(WALL, { gridSize - 1, y });
    }
    for (short x = 1; x < gridSize; x++) //fill first and last columns as walls (x)
    {
        IdentifyAsItem(WALL, { x, 0 });
        IdentifyAsItem(WALL, { x, gridSize - 1 });
    }

    //place player
    MoveSnake({ (gridSize - 2) / 2, (gridSize - 2) / 2 });

    //place apple
    RegenerateApple();
}

void GameManager_t::Update()
{
    short2 nextPos = { 0,0 };
    if (ValidSnakeMovement(nextPos))
    {
        MoveSnake(nextPos);
    }
}

void GameManager_t::Render()
{
    for (short x = 0; x < gridSize; x++)
    {
        for (short y = 0; y < gridSize; y++)
        {
            PrintItem({ x, y });
        }
        std::cout << '\n';
    }
    std::cout << "\n\n\n";

}

void GameManager_t::InputKey()
{
    std::cin >> lastKeyPress;
    DirectionValue desiredDir = NO_DIR;
    switch ((InputValue)lastKeyPress)
    {
    case INPUT_A:
    case INPUT_a:
        desiredDir = LEFT_DIR;
        break;
    case INPUT_D:
    case INPUT_d:
        desiredDir = RIGHT_DIR;
        break;
    case INPUT_S:
    case INPUT_s:
        desiredDir = DOWN_DIR;
        break;
    case INPUT_W:
    case INPUT_w:
        desiredDir = UP_DIR;
        break;
    default:
        break;
    }
    switch (direction)
    {
    case GameManager_t::UP_DIR:
        if (desiredDir != DOWN_DIR)
        {
            direction = desiredDir;
        }
        break;
    case GameManager_t::LEFT_DIR:
        if (desiredDir != RIGHT_DIR)
        {
            direction = desiredDir;
        }
        break;
    case GameManager_t::RIGHT_DIR:
        if (desiredDir != LEFT_DIR)
        {
            direction = desiredDir;
        }
        break;
    case GameManager_t::DOWN_DIR:
        if (desiredDir != UP_DIR)
        {
            direction = desiredDir;
        }
        break;
    default:
        direction = desiredDir;
        break;
    }
}

bool GameManager_t::IsGameRunning()
{
    return gameRunning;
}


GridItem GameManager_t::GetIdentityOfItem(short2 pos)
{
    return mapGrid[pos.x][pos.y].GetID();
}

void GameManager_t::IdentifyAsItem(GridItem item, short2 pos)
{
    if (mapGrid[pos.x][pos.y].GetID() == GridItem::EMPTY)
    {
        mapGrid[pos.x][pos.y].SetID(item);
    }
}

void GameManager_t::UnidntifyItem(short2 pos)
{
    if (mapGrid[pos.x][pos.y].GetID() != GridItem::WALL)
    {
        IdentifyAsItem(EMPTY, pos);
    }
}

void GameManager_t::PrintItem(short2 pos)
{
    std::cout << mapGrid[pos.x][pos.y].GetDisplayValue();
}

void GameManager_t::GenerateRandomPos(short2& pos)
{
    //return x and y as a value between 1 and gridSize-1
    pos.x = (rand() % gridSize - 1) + 1;
    pos.y = (rand() % gridSize - 1) + 1;
}

void GameManager_t::RegenerateApple()
{
    if (appleEaten)
    {
        appleEaten = false;
        short2 applePos = { 1,1 };
        do
        {
            GenerateRandomPos(applePos);
        } while (GetIdentityOfItem(applePos) != GridItem::EMPTY);  // make sure that the desired new position for the apple is in an empty spot
        IdentifyAsItem(APPLE, applePos);
    }
}

void GameManager_t::MoveSnake(short2 pos)
{
    //work from head down
    segments[0].SetPos(pos);
    IdentifyAsItem(SNAKE_HEAD, pos);                    //register head
    if (amountSegments > 0)
    {
        UnidntifyItem(segments[0].GetPrev());               //deregister previous head position
        IdentifyAsItem(SNAKE_BODY, segments[0].GetPrev());  //replace previous head with body
    }
    for (short i = 1; i < amountSegments; i++)
    {
        segments[i].SetPos(segments[i - 1].GetPrev());
    }
    UnidntifyItem(segments[amountSegments].GetPrev());  //deregister snake tail tip
}

bool GameManager_t::ValidSnakeMovement(short2&desiredNewPos)
{
    if (direction != NO_DIR)
    {
        desiredNewPos = segments[0].GetPos();
        switch (direction)
        {
        case GameManager_t::UP_DIR:
            desiredNewPos.x--;
            break;
        case GameManager_t::LEFT_DIR:
            desiredNewPos.y--;
            break;
        case GameManager_t::RIGHT_DIR:
            desiredNewPos.y++;
            break;
        case GameManager_t::DOWN_DIR:
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



