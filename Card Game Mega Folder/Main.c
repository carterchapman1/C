#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CardPublic.h"
#include "CurrencyPublic.h"



int iGameState = 0; //0 = not being played, 1 = first cards/bets 2 = second bets 3 = third bets / cards 4 = finished

TCard* CreateDeck();
void ShuffleDeck();
THand DealAHand(TCard* pSDeck);


// at the start of the program load the balance into a global or local that's passed
bool LoadBalance(TBalance *pBalance)
{
    FILE* Balance;
    Balance = fopen("UserBalance.bin", "rb");
        fread(&pBalance, sizeof(int), 1, Balance);
    fclose(Balance);

    return true;
};
// when you do something meaningful just call SaveBalance
bool SaveBalance(TBalance *pBalance)
{
FILE* Balance;
    Balance = fopen("UserBalance.bin", "wb");
        fwrite(&pBalance, sizeof(int), 1, Balance);
        fclose(Balance);
    return true;
}

//////////////////////////////////////////

int main()
{   
    srand(time(NULL));
    int iRandomIndex = rand() % 53 ; 
    TCard* pDeck;
    pDeck = CreateDeck();
    ShuffleDeck(pDeck);
    THand Hand = DealAHand(pDeck);
    TCard tmpCard = pDeck[4];
    printf("%d of %d", C_Value[tmpCard.eValue], C_Suit[tmpCard.eSuit]);
    return 0;
}

