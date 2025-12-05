#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CardPublic.h"
#include "CurrencyPublic.h"

const char *C_Value[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char *C_Suit[] = {"Spades","Clubs","Hearts","Diamonds"}; 
int num_values = sizeof(C_Value) / sizeof(C_Value[0]) ; 
int num_suits = sizeof(C_Suit) / sizeof(C_Suit[0]) ; 
int iGameState = 0; //0 = not being played, 1 = first cards/bets 2 = second bets 3 = third bets / cards 4 = finished

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

