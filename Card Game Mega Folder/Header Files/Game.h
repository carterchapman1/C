#ifndef GAMEPUBLIC_H
    #define GAMEPUBLIC_H
        enum EGameState
        {
            eDefault = 0,
            eAutomatic = 1,
            eFirstCards = 2,
            eFirstBets = 3,
            eSecondCard = 4,
            eSecondBets = 5,
            eFinalCard = 6,
            eFinalBets = 7
        };

        enum EGameType
        {
            eP = 0,
            eBJ = 1
        };

        struct TGameState
        {
            EGameState iGameState;
            int iUser;
        };

// extern dec of the gamestate
extern TGameState g_tGameState;
extern EGameType g_tGameType;
#endif