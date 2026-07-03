#ifndef CURRENCYPUBLIC_H
    #define CURRENCYPUBLIC_H
        enum EChip
        {
            eChip1 = 1,
            eChip5 = 5,
            eChip10 = 10,
            eChip20 = 20,
            eChip50 = 50,
            eChip100 = 100,
            eChip200 = 200
        };

        struct TBalance
        {
            int TBalanceTotal;
            EChip TChips[];
        };

        struct TUserBalance
        {
            TBalance TUBalance;
            int iUser;
        };
        extern TBalance g_tPotBalance;
#endif
