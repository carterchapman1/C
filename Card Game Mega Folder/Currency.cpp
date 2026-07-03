#include <stdbool.h>
#include <stdio.h>
#include "Header Files/Currency.h"
#include "Header Files/Game.h"
#include "Header Files/Card.h"

TGameState g_tGameState;
TCardsInPlay g_tAllCards;
TBalance g_tPotBalance;
EGameType g_tGameType;
TUserBalance g_tUserBalance;

// at the start of the program load the balance into a global or local that's passed
bool LoadBalance(TUserBalance pUserBalance)
{
    FILE* Balance;
    Balance = fopen("UserBalance.csv", "r");
        fread(&pUserBalance.TUBalance, sizeof(int), 1, Balance);
    fclose(Balance);

    return true;
};
// when you do something meaningful just call SaveBalance
bool SaveBalance(TUserBalance pUserBalance)
{
FILE* Balance;
    Balance = fopen("UserBalance.csv", "w");
        fwrite(&pUserBalance.TUBalance, sizeof(int), 1, Balance);
        fclose(Balance);
    return true;
}

void Bets(int BetAmount)
{
    if (g_tGameType == 1)
    {
        
    }

}