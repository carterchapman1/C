#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CardPublic.cpp"
#include "CurrencyPublic.cpp"
#include "GamePublic.cpp"

//////////////////////////////////////////

void GameStart();
void GameInit();
void GameDisplay();
bool LoadBalance(TBalance *pBalance);
bool SaveBalance(TBalance *pBalance);

//////////////////////////////////////////

int main()
{   
    srand(time(NULL));
    GameInit();
    GameStart();
    GameDisplay();
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
