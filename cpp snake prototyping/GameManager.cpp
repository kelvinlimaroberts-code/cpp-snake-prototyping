#include "GameManager.h"
#include <cstdlib>      //for random
#include <ctime>        //for seed
#include <iostream>     //for cout

GameManager_t::GameManager_t()
{
    srand(time(0));   //generate seed
    //identify GRID items ON INIT
  
    //IDENTIFY walls
    for (int y = 0; y < gridSize; y++) //fill first and last rows as walls (y)
    {
        IdentifyAsItem(WALL, 0, y);
        IdentifyAsItem(WALL, gridSize - 1, y);
    }
    for (int x = 1; x < gridSize; x++) //fill first and last columns as walls (x)
    {
        IdentifyAsItem(WALL, x, 0);
        IdentifyAsItem(WALL, x, gridSize - 1);
    }

    //place player
    IdentifyAsItem(PLAYER_HEAD, (gridSize - 2) / 2, (gridSize - 2) / 2);

    //place apple
    RegenerateApple();
}

void GameManager_t::Update()
{
    
}

void GameManager_t::Render()
{
    for (int x = 0; x < gridSize; x++)
    {
        for (int y = 0; y < gridSize; y++)
        {
            PrintItem(x, y);
        }
        std::cout << '\n';
    }
    std::cout << "\n\n\n";

}

bool GameManager_t::IsGameRunning()
{
    return gameRunning;
}

void GameManager_t::SetGameToRun(bool run)
{
    gameRunning = run;
}

GridItem GameManager_t::GetIdentityOfItem(int x, int y)
{
    return mapGrid[x][y].GetID();
}

void GameManager_t::IdentifyAsItem(GridItem item, int x, int y)
{
    if (mapGrid[x][y].GetID() == GridItem::EMPTY)
    {
        mapGrid[x][y].SetID(item);
    }
}

void GameManager_t::UnidntifyItem(int x, int y)
{
    if (mapGrid[x][ y].GetID() != GridItem::WALL)
    {
        IdentifyAsItem(EMPTY, x, y);
    }
}

void GameManager_t::PrintItem(int x, int y)
{
    std::cout << mapGrid[x][y].GetDisplayValue();
}

void GameManager_t::GenerateRandomPos(int& x, int& y)
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
        int appleX = 1;
        int appleY = 1;
        do
        {
            GenerateRandomPos(appleX, appleY);
        } while (GetIdentityOfItem(appleX, appleY) != GridItem::EMPTY);  // make sure that the desired new position for the apple is in an empty spot
        IdentifyAsItem(APPLE, appleX, appleY);
    }
}



