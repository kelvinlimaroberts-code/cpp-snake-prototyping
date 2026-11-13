#include "GameManager.h"

#include <iostream>


int main()
{
    //init
    GameManager_t* gameManager = new GameManager_t;

    while (gameManager->IsGameRunning())
    { 
        gameManager->Update();
        gameManager->Render();
        gameManager->InputKey();
    }





    //release 
    delete gameManager;
    gameManager = nullptr;
}
