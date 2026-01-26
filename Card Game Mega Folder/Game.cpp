#include "GamePublic.cpp"
#include "CardPublic.cpp"
#include <stdio.h>
#include <stdlib.h>

const char *C_Value[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char *C_Suit[] = {"Spades","Clubs","Hearts","Diamonds"}; 

// declare the gamestate variable
TGameState g_tGameState;

void GameDisplay()
    {
        if (g_tGameState.iGameState > 0)
         {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("Your Cards : %s of %s | %s of %s \n", C_Value[AllCards.Hand1.TCard1.eValue], C_Suit[AllCards.Hand1.TCard1.eSuit], C_Value[AllCards.Hand1.TCard2.eValue],  C_Suit[AllCards.Hand1.TCard2.eSuit]);
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("The Cards on the Table : | %s of %s | %s of %s | %s of %s |", C_Value[AllCards.tCard[0].eValue], C_Suit[AllCards.tCard[0].eSuit], C_Value[AllCards.tCard[1].eValue],  C_Suit[AllCards.tCard[1].eSuit] ,C_Value[AllCards.tCard[2].eValue], C_Suit[AllCards.tCard[2].eSuit]);
            if (g_tGameState.iGameState > 3)
            {
                printf(" %s of %s |", C_Value[AllCards.tCard[3].eValue], C_Suit[AllCards.tCard[3].eSuit]);

                if (g_tGameState.iGameState > 5)
            {
                printf(" %s of %s |", C_Value[AllCards.tCard[4].eValue], C_Suit[AllCards.tCard[4].eSuit]);
            }
            }
            printf("\n--------------------------------------------------------------------------------------------------------------------\n");
        }
    }

void GameStart()
    {
        // anything that wasn't done in GameInit to start the game

        int UserChoice;
        printf("Please Select a User \n 1: User1 2: Coming Soon...\n");
        scanf("%d", &UserChoice);
        if (UserChoice == 1)
        {
            g_tGameState.iUser = 1 ;
            g_tGameState.iGameState = 1;
        }
        
    }

void GameInit()
{

// create the deck, shuffle it
// basically do all the setup stuff before the game starts
    TCard* pDeck;
    CreateDeck();
    ShuffleDeck();
    for (int i=0; i<5; i++)
    {
        AllCards.tCard[i] = GetCardFromDeck();
;
    }
}


void GamePlay()
{

    // play a round/turn etc.

}