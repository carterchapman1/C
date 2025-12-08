#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CardPublic.h"
#include "CurrencyPublic.h"
#include "GamePublic.h"

//////////////////////////////////////////

EGameState iGameState = 0;

void StartGame();
void GameDisplay(THand Hand);
TCard* CreateDeck();
void ShuffleDeck(TCard* pDeck);
THand DealAHand(TCard* pSDeck);
bool LoadBalance(TBalance *pBalance);
bool SaveBalance(TBalance *pBalance);
void NonUserCards(TCard* pSDeck);

//////////////////////////////////////////

int main()
{   
    srand(time(NULL));
    int iRandomIndex = rand() % 53 ; 
    TCard* pDeck;
    pDeck = CreateDeck();
    ShuffleDeck(pDeck);
    THand Hand = DealAHand(pDeck);
    NonUserCards(pDeck);
    StartGame();
    GameDisplay(Hand);
    return 0;
}

