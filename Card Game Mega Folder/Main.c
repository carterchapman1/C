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

void GameDisplay();
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
    for (int i = 0; i < 52; i++)
    {
        TCard tmpCard = pDeck[i];
        printf("%s of %s\n", C_Value[tmpCard.eValue], C_Suit[tmpCard.eSuit]);
    }
    return 0;
}

