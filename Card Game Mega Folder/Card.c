#include"CardPublic.h"
#include <stdio.h>
#include <stdlib.h>

TCardsInPlay AllCards;

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
        while (i != 0)
        {
            if (pRandomNumberList[i] != pRandomNumberList[i-1])
            {
                if (pRandomNumberList[i] != pRandomNumberList[i-2])
                {
                    if (pRandomNumberList[i] != pRandomNumberList[i-3])
                    {
                        if (pRandomNumberList[i] != pRandomNumberList[i-4])
                            {

                            }
                    }
                }
            }
            else
            {
              i-- ;
            }
        }
    }
    AllCards.Card1 = pSDeck[pRandomNumberList[0]];
    AllCards.Card2 = pSDeck[pRandomNumberList[1]];
    AllCards.Card3 = pSDeck[pRandomNumberList[2]];
    AllCards.Card4 = pSDeck[pRandomNumberList[3]];
    AllCards.Card5 = pSDeck[pRandomNumberList[4]];
}

