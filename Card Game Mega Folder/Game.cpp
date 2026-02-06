#include "Header Files/Game.h"
#include "Header Files/Card.h"
#include <stdio.h>
#include <stdlib.h>

const char *C_Value[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char *C_Suit[] = {"Spades","Clubs","Hearts","Diamonds"}; 

// declare the gamestate variable
TGameState g_tGameState;
TCardsInPlay g_tAllCards;
EGameType g_tGameType;
int CalculateHandValue(THand pHand);
void ShuffleDeck();
void CreateDeck();
TCard GetCardFromDeck();


void GameDisplay()
    {
        if (g_tGameType == EGameType(0))
         {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("Your Cards : %s of %s | %s of %s \n", C_Value[g_tAllCards.HandUser.tCard[0].eValue], C_Suit[g_tAllCards.HandUser.tCard[0].eSuit], C_Value[g_tAllCards.HandUser.tCard[1].eValue],  C_Suit[g_tAllCards.HandUser.tCard[1].eSuit]);
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
            printf("Your Cards : %s of %s | %s of %s \n", C_Value[g_tAllCards.HandUser.tCard[0].eValue], C_Suit[g_tAllCards.HandUser.tCard[0].eSuit], C_Value[g_tAllCards.HandUser.tCard[1].eValue],  C_Suit[g_tAllCards.HandUser.tCard[1].eSuit]);
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
            printf("1");
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
    g_tAmountOfCards = 0;
    g_tAllCards.HandDealer.iCount = 0;    
    if (g_tGameType == EGameType(0))
        {
        for (int i=0; i<5; i++)
        {
            g_tAllCards.tCard[i] = GetCardFromDeck();

        }
        }
    else if (g_tGameType == EGameType(1))
        {
        for (int i=0; i<2; i++)
        {
            g_tAllCards.HandDealer.tCard[i] = GetCardFromDeck();
            g_tAllCards.HandDealer.iCount++;

        }
        }
    
    // set count to 0 to start with because in C/C++ numbers/values DON'T default to 0
    g_tAllCards.HandUser.iCount = 0;    
    for (int i=0; i<2; i++)
    {
            g_tAllCards.HandUser.tCard[i] = GetCardFromDeck();
            g_tAllCards.HandUser.iCount++;
            g_tAmountOfCards++;

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
            bool bUBust = false;
            bool bUBlackJack = false;
            bool bDBust = false;
            bool bDBlackJack = false;
            bool bStand = false;
            bool bDealerLimit = false;
            int DealerValue;
            int UserValue;
            while (bUBust == false && bUBlackJack == false && bStand == false){
                int UserInput;
                printf("Make a choice:\n1: Hit:\n2: Stand:\n");
                scanf("%d", &UserInput);
                UserValue = CalculateHandValue(g_tAllCards.HandUser);
                if (UserInput == 1)
                {
                    UserValue = CalculateHandValue(g_tAllCards.HandUser);
                    //printf("%d", UserValue);
                    g_tAllCards.HandUser.tCard[g_tAllCards.HandUser.iCount] = GetCardFromDeck();
                    g_tAllCards.HandUser.iCount++;
                    printf("Your New Card : %s of %s \n", C_Value[g_tAllCards.HandUser.tCard[g_tAllCards.HandUser.iCount-1].eValue], C_Suit[g_tAllCards.HandUser.tCard[g_tAllCards.HandUser.iCount-1].eSuit]);
                    UserValue = CalculateHandValue(g_tAllCards.HandUser);
                    //printf("%d", UserValue);
                    if (UserValue > 21)
                    {
                        bUBust = true;
                    }
                    else if (UserValue == 21)
                    {
                        bUBlackJack = true;
                    }
                    
                }
                else if (UserInput == 2)
                {
                    bStand = true;
                }

            }
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            if (bUBust == true)
            {
                printf("You Went bust!\n");
            }
            else
            {
            printf("Dealers Cards : | %s of %s | %s of %s | \n", C_Value[g_tAllCards.HandDealer.tCard[0].eValue], C_Suit[g_tAllCards.HandDealer.tCard[0].eSuit], C_Value[g_tAllCards.HandDealer.tCard[1].eValue],  C_Suit[g_tAllCards.HandDealer.tCard[1].eSuit]);
            while (bDealerLimit == false && bUBust == false)
            {
                DealerValue = CalculateHandValue(g_tAllCards.HandDealer);
                if (DealerValue < 17)
                {
                g_tAllCards.HandDealer.tCard[g_tAllCards.HandDealer.iCount] = GetCardFromDeck();
                g_tAllCards.HandDealer.iCount++;
                printf("Dealers new Card : | %s of %s | \n", C_Value[g_tAllCards.HandDealer.tCard[g_tAllCards.HandDealer.iCount-1].eValue],C_Suit[g_tAllCards.HandDealer.tCard[g_tAllCards.HandDealer.iCount-1].eSuit]);
                DealerValue = CalculateHandValue(g_tAllCards.HandDealer);
                //printf(" -- %d --  %d -- \n", DealerValue, g_tAllCards.HandDealer.iCount);
                }
                else if (DealerValue > 21)
                {
                    bDealerLimit = true;
                    bDBust = true;
                    //printf("3 %d -- %d", DealerValue, UserValue );
                    }
                else
                {
                    bDealerLimit = true;
                }
                }
            }
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("%d -- %d \n", DealerValue, UserValue );
            if (bDBust == true or ((UserValue > DealerValue) and DealerValue <= 21 and bUBust != true))
            {
                printf("Player Wins\n");
            }
            else if (UserValue == DealerValue)
            {
                printf("Its a draw\n");
            }
            else 
            {
                printf("House Wins\n");
            }
            
            }
            printf("--------------------------------------------------------------------------------------------------------------------\n");

        }
    
