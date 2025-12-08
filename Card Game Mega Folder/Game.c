#include "GamePublic.h"
#include "CardPublic.h"
#include <stdio.h>
#include <stdlib.h>

const char *C_Value[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char *C_Suit[] = {"Spades","Clubs","Hearts","Diamonds"}; 

void GameDisplay()
    {
        if (iGameState > 0)
         {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("| %s of %s | %s of %s | %s of %s |\n", C_Value[AllCards.Card1.eValue], C_Suit[AllCards.Card1.eSuit], C_Value[AllCards.Card2.eValue],  C_Suit[AllCards.Card2.eSuit] ,C_Value[AllCards.Card1.eValue], C_Suit[AllCards.Card3.eSuit]);
            
            if (iGameState > 3)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %s of %s |\n", C_Value[AllCards.Card4.eValue], C_Suit[AllCards.Card4.eSuit]);

                if (iGameState > 5)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %s of %s |\n", C_Value[AllCards.Card5.eValue], C_Suit[AllCards.Card5.eSuit]);
            }
            }
            printf("--------------------------------------------------------------------------------------------------------------------\n");
        }
    }

void StartGame()
    {
        int UserChoice;
        printf("Please Select a User \n 1: User1 2: Coming Soon...\n");
        scanf("%d", &UserChoice);
        if (UserChoice == 1)
        {
            iUser = 1 ;
            iGameState = 1;
        }
        
    }