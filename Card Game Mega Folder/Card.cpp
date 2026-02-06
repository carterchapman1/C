#include"Header Files/Card.h"
#include <stdio.h>
#include <stdlib.h>

TDeck g_tDeck;
TCardsInPlay g_tCardsInPLay;
int g_tAmountOfCards;
const int CardValue[] = {11,2,3,4,5,6,7,8,9,10,10,10,10};

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
}

/*
int CalculateHandValue(THand *pHand)
{

    printf("%d , %d, %d \n",CardValue[pHand->tCard[0].eValue], CardValue[pCard->tCard[amount-1].eValue], amount   );

   // instead of referencing _tAllCards.HandUser you can just use pHand
   // dealervalue = CalculateHandValue(g_tAllCards.HandDeadler);
   // uservalue = CalculateHandValue(g_tAllCards.HandUser);
   // so try to get THand::iCount working

}
*/


int CalculateHandValue(THand pHand)
{
    int iTotalValue = 0;
    int iNumOfAces = 0;

    for (int i=0;i<int(pHand.iCount); i++)
    {
        int iThisCardValue = CardValue[pHand.tCard[i].eValue];  // use this below where you can
        iTotalValue += iThisCardValue;
        if (iThisCardValue == 11)
            {
                iNumOfAces ++;
            }
        // then at the end, outside the loop check if iTotalValue 
        // this is an 'if' because we only ever add ONE ace as 11, never more
        if ((iTotalValue > 21) && (iNumOfAces > 0))
        {
            iTotalValue -= 10;  
            iNumOfAces--;
        }
    }
    return  iTotalValue;
}


    /*
    TDeck* pPointerToDeck = &tDeck;

    TDeck tNewDeck = *pPointerToDeck;

    int iNumberOfCardsInDeck1 = pPointerToDeck->iCount;
    int iNumberOfCardsInDeck2 = tDeck.iCount;

     pPointerToDeck->iCount = 32;
     tDeck.iCount
*/



/*

notes:

rework so that TDeck has up to 52 cards and a counter
you could also have a discard deck which starts at 0 and counts up (etc)
this also allows for multiple packs of cards to be in a deck just by adding more cards and setting (eg) tDeck.iCount to 104,156 etc

then dealing is just calling GetCardFromDeck(..)

also in game.c, rework so that it uses the struct g_tGameState

*/

