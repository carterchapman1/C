#include"CardPublic.h"
#include <stdio.h>
#include <stdlib.h>

TDeck g_tDeck;

TCard* CreateDeck()
{
    TCard* pDeck = malloc((sizeof(TCard)*52));
    int index = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int i = 0; i<13; i++)
        {
            pDeck[index].eSuit = y;
            pDeck[index].eValue = i;
            index ++;
        }
    }
    return pDeck;
}

void ShuffleDeck(TCard* pDeck)
{
    TCard TmpCard;
    int iRandomIndex = (rand() % 52);
    for (int i=0;i<52;i++)
    {
        int iRandomIndex = (rand() % 52);
        TmpCard = pDeck[i];
        pDeck[i] = pDeck[iRandomIndex];
        pDeck[iRandomIndex] = TmpCard;
    }
}

THand DealAHand(TCard* pSDeck)
{
    int iRandom1 = rand() % 52; 
    int iRandom2 = rand() % 52; 

    THand Hand;
    Hand.TCard1 = pSDeck[iRandom1];
    Hand.TCard2 = pSDeck[iRandom2];
    AllCards.Hand1 = Hand;
    return Hand;
}

void NonUserCards(TCard* pSDeck)
{
    int* pRandomNumberList = malloc(sizeof(int)*5);
    for (int i=0;i<5;i++)
    {
        int iRandomIndex = (rand() % 52);
        pRandomNumberList[i] = iRandomIndex;
    }
    AllCards.Card1 = pSDeck[pRandomNumberList[0]];
    AllCards.Card2 = pSDeck[pRandomNumberList[1]];
    AllCards.Card3 = pSDeck[pRandomNumberList[2]];
    AllCards.Card4 = pSDeck[pRandomNumberList[3]];
    AllCards.Card5 = pSDeck[pRandomNumberList[4]];

    free(pRandomNumberList);
}


////////////////////
// get a card from the deck
TCard GetCardFromDeck(TDeck* pSDeck)
{

    // take the top card
    TCard tResult = pSDeck->tCard[pSDeck->iCount - 1];
    pSDeck->iCount--;

    return tResult;


    /*
    TDeck* pPointerToDeck = &tDeck;

    TDeck tNewDeck = *pPointerToDeck;

    int iNumberOfCardsInDeck1 = pPointerToDeck->iCount;
    int iNumberOfCardsInDeck2 = tDeck.iCount;

     pPointerToDeck->iCount = 32;
     tDeck.iCount
*/
}


/*

notes:

rework so that TDeck has up to 52 cards and a counter
you could also have a discard deck which starts at 0 and counts up (etc)
this also allows for multiple packs of cards to be in a deck just by adding more cards and setting (eg) tDeck.iCount to 104,156 etc

then dealing is just calling GetCardFromDeck(..)

also in game.c, rework so that it uses the struct g_tGameState

*/

