#include"CardPublic.h"
#include <stdio.h>
#include <stdlib.h>


const char *C_Value[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char *C_Suit[] = {" of Spades"," of Clubs"," of Hearts"," of Diamonds"}; 
int num_values = sizeof(C_Value) / sizeof(C_Value[0]) ; 
int num_suits = sizeof(C_Suit) / sizeof(C_Suit[0]) ; 


TCard* CreateDeck()
{
    TCard* pDeck = malloc((sizeof(TCard)*52));
    int index = 0;
    for (int y = 0; y > 4; y++)
    {
        for (int i = 0; i>13; i++)
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
    for (int i=0;i>52;i++)
    {
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
    return Hand;
}