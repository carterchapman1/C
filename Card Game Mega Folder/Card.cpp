#include"CardPublic.cpp"
#include <stdio.h>
#include <stdlib.h>

TDeck g_tDeck;
TCardsInPlay g_tCardsInPLay;


void CreateDeck()
{
    g_tDeck.iCount = 0;
    for (int y = 0; y < 4; y++)
    {  
        for (int i = 0; i<13; i++)
        {
            g_tDeck.tCard[g_tDeck.iCount].eSuit = (ESuit)y;
            g_tDeck.tCard[g_tDeck.iCount].eValue = (EValue)i;;
            g_tDeck.iCount++;
        }
    }
}

void ShuffleDeck()
{
    TCard TmpCard;
    int iRandomIndex = (rand() % 52);
    for (int i=0;i<52;i++)
    {
        int iRandomIndex = (rand() % 52);
        TmpCard = g_tDeck.tCard[i];
        g_tDeck.tCard[i] = g_tDeck.tCard[iRandomIndex];
        g_tDeck.tCard[iRandomIndex] = TmpCard;
    }
}


////////////////////
// get a card from the deck
TCard GetCardFromDeck()
{

    // take the top card
    TCard tResult = g_tDeck.tCard[g_tDeck.iCount - 1];
    g_tDeck.iCount--;

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

