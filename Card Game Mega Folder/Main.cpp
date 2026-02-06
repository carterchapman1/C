#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Header Files/Card.h"
#include "Header Files/Currency.h"
#include "Header Files/Game.h"

//////////////////////////////////////////

void GameStart();
void GameInit();
void GamePlay();
void GameDisplay();
bool LoadBalance(TBalance *pBalance);
bool SaveBalance(TBalance *pBalance);

//////////////////////////////////////////

int main()
{   
    srand(time(NULL));
    GameStart();
    GameInit();
    GameDisplay();
    GamePlay();
    return 0;
}

/*

from here
call:
    GameInit
    GameStart

    then probably somethinglike
    while(true)
    {
        //could return false from GamePlay() when it's finsihed so could do
        if (!GamePlay())
          break;

        GameDisplay();
        
    }

    GameShutdown();

*/
