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
        IdentifyAsItem(WALL, 0, y);
        IdentifyAsItem(WALL, gridSize - 1, y);
    }
    for (short x = 1; x < gridSize; x++) //fill first and last columns as walls (x)
    {
        IdentifyAsItem(WALL, x, 0);
        IdentifyAsItem(WALL, x, gridSize - 1);
    }

    //place player
    IdentifyAsItem(SNAKE_HEAD, (gridSize - 2) / 2, (gridSize - 2) / 2);

    //place apple
    RegenerateApple();
}

void GameManager_t::Update()
{
    
}

void GameManager_t::Render()
{
    for (short x = 0; x < gridSize; x++)
    {
        for (short y = 0; y < gridSize; y++)
        {
            PrintItem(x, y);
        }
        std::cout << '\n';
    }
    std::cout << "\n\n\n";

}

void GameManager_t::InputKey()
{
    std::cin >> lastKeyPress;
    DirectionValue desiredDir;
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
        break;
    }
}

bool GameManager_t::IsGameRunning()
{
    return gameRunning;
}


GridItem GameManager_t::GetIdentityOfItem(short x, short y)
{
    return mapGrid[x][y].GetID();
}

void GameManager_t::IdentifyAsItem(GridItem item, short x, short y)
{
    if (mapGrid[x][y].GetID() == GridItem::EMPTY)
    {
        mapGrid[x][y].SetID(item);
    }
}

void GameManager_t::UnidntifyItem(short x, short y)
{
    if (mapGrid[x][ y].GetID() != GridItem::WALL)
    {
        IdentifyAsItem(EMPTY, x, y);
    }
}

void GameManager_t::PrintItem(short x, short y)
{
    std::cout << mapGrid[x][y].GetDisplayValue();
}

void GameManager_t::GenerateRandomPos(short& x, short& y)
{
    //return x and y as a value between 1 and gridSize-1
    x = (rand() % gridSize - 1) + 1;
    y = (rand() % gridSize - 1) + 1;
}

void GameManager_t::RegenerateApple()
{
    if (appleEaten)
    {
        appleEaten = false;
        short appleX = 1;
        short appleY = 1;
        do
        {
            GenerateRandomPos(appleX, appleY);
        } while (GetIdentityOfItem(appleX, appleY) != GridItem::EMPTY);  // make sure that the desired new position for the apple is in an empty spot
        IdentifyAsItem(APPLE, appleX, appleY);
    }
}



