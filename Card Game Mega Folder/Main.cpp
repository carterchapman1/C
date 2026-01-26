#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CardPublic.cpp"
#include "CurrencyPublic.cpp"
#include "GamePublic.cpp"

//////////////////////////////////////////

EGameState iGameState = 0;

void StartGame();
void GameDisplay();
void CreateDeck();
void ShuffleDeck();
TCard GetCardFromDeck(); 
bool LoadBalance(TBalance *pBalance);
bool SaveBalance(TBalance *pBalance);

//////////////////////////////////////////

int main()
{   
    srand(time(NULL));
    int iRandomIndex = rand() % 53 ; 
    TCard* pDeck;
    CreateDeck();
    ShuffleDeck();
    THand Hand = DealAHand(pDeck);
    NonUserCards(pDeck);
    StartGame();
    GameDisplay(Hand);
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
