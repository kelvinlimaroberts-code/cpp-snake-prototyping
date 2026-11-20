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
        map.IdentifyAsItem(WALL, { 0, y });
        map.IdentifyAsItem(WALL, { gridSize - 1, y });
    }
    for (short x = 1; x < gridSize; x++) //fill first and last columns as walls (x)
    {
        map.IdentifyAsItem(WALL, { x, 0 });
        map.IdentifyAsItem(WALL, { x, gridSize - 1 });
    }

    //place player
    player.MoveSnake({ (gridSize - 2) / 2, (gridSize - 2) / 2 }, map);

    //place apple
    RegenerateApple();
}

void GameManager_t::Update()
{
    short2 nextPos = { 0,0 };
    if (player.ValidSnakeMovement(nextPos))
    {
        FactorCollisions(nextPos);
        player.MoveSnake(nextPos, map);
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
    DirectionValue desiredDir = player.GetDirection();
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
    switch (player.GetDirection())
    {
    case UP_DIR:
        if (desiredDir != DOWN_DIR)
        {
            player.GetDirection() = desiredDir;
        }
        break;
    case LEFT_DIR:
        if (desiredDir != RIGHT_DIR)
        {
            player.GetDirection() = desiredDir;
        }
        break;
    case RIGHT_DIR:
        if (desiredDir != LEFT_DIR)
        {
            player.GetDirection() = desiredDir;
        }
        break;
    case DOWN_DIR:
        if (desiredDir != UP_DIR)
        {
            player.GetDirection() = desiredDir;
        }
        break;
    default:
        player.GetDirection() = desiredDir;
        break;
    }
}



void GameManager_t::OutputDeathMessage()
{
    std::cout << "you died. rip bozo. score = " << player.GetScore();
}

bool GameManager_t::IsGameRunning()
{
    return player.HasLife();
}


void GameManager_t::FactorCollisions(short2 nextPos)
{
    //now check collisions between things
        //check wall collision
    switch (map.GetIdentityOfItem(nextPos))
    {
    case WALL:
        player.HasLife() = false;
        break;
    case APPLE:
        map.UnidentifyItem(nextPos);
        ++player;
        map.AppleEaten() = true;
        RegenerateApple();
        break;
    case SNAKE_BODY:
        player.HasLife() = false;
        break;
    }
}



void GameManager_t::PrintItem(short2 pos)
{
    std::cout << map.GetDisplayValueAt(pos);
}

void GameManager_t::GenerateRandomPos(short2& pos)
{
    //return x and y as a value between 1 and gridSize-1
    pos.x = (rand() % gridSize - 1) + 1;
    pos.y = (rand() % gridSize - 1) + 1;
}

void GameManager_t::RegenerateApple()
{
    if (map.AppleEaten())
    {
        map.AppleEaten() = false;
        short2 applePos = { 1,1 };
        do
        {
            GenerateRandomPos(applePos);
        } while (map.GetIdentityOfItem(applePos) != GridItem::EMPTY);  // make sure that the desired new position for the apple is in an empty spot
        map.IdentifyAsItem(APPLE, applePos);
    }
}





