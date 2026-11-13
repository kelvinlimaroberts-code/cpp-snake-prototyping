#include "GameManager.h"

#include <iostream>


int main()
{
    //init
    GameManager_t* gameManager = new GameManager_t;

    //while (gameManager->IsGameRunning())
    for (size_t i = 0; i < 8; i++)
    { 
        gameManager->Update();
        gameManager->Render();
    }





    //release 
    delete gameManager;
    gameManager = nullptr;
}
