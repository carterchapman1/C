#ifndef GAMEPUBLIC_H
    #define GAMEPUBLIC_H
        typedef enum EGameState
        {
            eDefault = 0,
            eAutomatic = 1,
            eFirstCards = 2,
            eFirstBets = 3,
            eSecondCard = 4,
            eSecondBets = 5,
            eFinalCard = 6,
            eFinalBets = 7
        } EGameState;

typedef struct TGameState
{
        EGameState iGameState;
        int iUser;
} TGameState;

// extern dec of the gamestate
extern TGameState g_tGameState;
#endif