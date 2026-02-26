#include <stdbool.h>
#include <stdio.h>
#include "Header Files/Currency.h"

// at the start of the program load the balance into a global or local that's passed
bool LoadBalance(TUserBalance *pUserBalance)
{
    FILE* Balance;
    Balance = fopen("UserBalance.csv", "r");
        fread(&pUserBalance->TBalance, sizeof(int), 1, Balance);
    fclose(Balance);

    return true;
};
// when you do something meaningful just call SaveBalance
bool SaveBalance(TUserBalance *pUserBalance)
{
FILE* Balance;
    Balance = fopen("UserBalance.csv", "w");
        fwrite(&pUserBalance->TBalance, sizeof(int), 1, Balance);
        fclose(Balance);
    return true;
}

void Bets()
{


}