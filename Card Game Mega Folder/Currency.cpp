#include <stdbool.h>
#include <stdio.h>
#include "Currency.h"

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