#include "Game.h"
#include "Card.h"
#include <stdio.h>
#include <stdlib.h>

const char *C_Value[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char *C_Suit[] = {"Spades","Clubs","Hearts","Diamonds"}; 

// declare the gamestate variable
TGameState g_tGameState;
TCardsInPlay g_tAllCards;
EGameType g_tGameType;
void ShuffleDeck();
void CreateDeck();
TCard GetCardFromDeck();


void GameDisplay()
    {
        if (g_tGameType == EGameType(0))
         {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("Your Cards : %s of %s | %s of %s \n", C_Value[g_tAllCards.Hand1.tCard[0].eValue], C_Suit[g_tAllCards.Hand1.tCard[0].eSuit], C_Value[g_tAllCards.Hand1.tCard[1].eValue],  C_Suit[g_tAllCards.Hand1.tCard[1].eSuit]);
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("The Cards on the Table : | %s of %s | %s of %s | %s of %s |", C_Value[g_tAllCards.tCard[0].eValue], C_Suit[g_tAllCards.tCard[0].eSuit], C_Value[g_tAllCards.tCard[1].eValue],  C_Suit[g_tAllCards.tCard[1].eSuit] ,C_Value[g_tAllCards.tCard[2].eValue], C_Suit[g_tAllCards.tCard[2].eSuit]);
            if (g_tGameState.iGameState > 3)
            {
                printf(" %s of %s |", C_Value[g_tAllCards.tCard[3].eValue], C_Suit[g_tAllCards.tCard[3].eSuit]);

                if (g_tGameState.iGameState > 5)
            {
                printf(" %s of %s |", C_Value[g_tAllCards.tCard[4].eValue], C_Suit[g_tAllCards.tCard[4].eSuit]);
            }
            }
            printf("\n--------------------------------------------------------------------------------------------------------------------\n");
        }
        if (g_tGameType == EGameType(1))
         {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("Your Cards : %s of %s | %s of %s \n", C_Value[g_tAllCards.Hand1.tCard[0].eValue], C_Suit[g_tAllCards.Hand1.tCard[0].eSuit], C_Value[g_tAllCards.Hand1.tCard[1].eValue],  C_Suit[g_tAllCards.Hand1.tCard[1].eSuit]);
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            
         }
    }

void GameStart()
    {
        // anything that wasn't done in GameInit to start the game
        int UserChoiceUser;
        int UserChoiceGame;
        printf("Please Select a User \n 1: User1 2: Coming Soon...\n");
        scanf("%d", &UserChoiceUser);
        if (UserChoiceUser == 1)
        {
            g_tGameState.iUser = int(1) ;
        }

        printf("Please Select a Game Type \n 1: Poker 2: BlackJack\n");
        scanf("%d", &UserChoiceGame);
        if (UserChoiceGame == 1)
        {
            g_tGameType = EGameType(0);
        }
        if (UserChoiceGame == 2)
        {
            g_tGameType = EGameType(1);
        }

        g_tGameState.iGameState = EGameState(1);
    }

void GameInit()
{

// create the deck, shuffle it
    CreateDeck();
    ShuffleDeck();
// basically do all the setup stuff before the game starts
    TCard* pDeck;
    if (g_tGameType == EGameType(0))
        {
        for (int i=0; i<5; i++)
        {
            g_tAllCards.tCard[i] = GetCardFromDeck();
        }
        }
    if (g_tGameType == EGameType(1))
        {
        for (int i=0; i<2; i++)
        {
            g_tAllCards.tCard[i] = GetCardFromDeck();
        }
        }
    
    for (int i=0; i<2; i++)
    {
            g_tAllCards.Hand1.tCard[i] = GetCardFromDeck();
    }
}


void GamePlay()
{

    // play a round/turn etc.
    if (g_tGameType == EGameType(0)) //poker
    {

    }
    if (g_tGameType == EGameType(1)) //blackjack
        {
        printf("Dealers Cards : | %s of %s | %s of %s | \n", C_Value[g_tAllCards.tCard[0].eValue], C_Suit[g_tAllCards.tCard[0].eSuit], C_Value[g_tAllCards.tCard[1].eValue],  C_Suit[g_tAllCards.tCard[1].eSuit]);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        }

}