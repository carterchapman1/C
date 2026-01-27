#ifndef CARDPUBLIC_H
    #define CARDPUBLIC_H
        typedef enum ESuit
        {
            ES_HEARTS,
            ES_DIAMONDS,
            ES_CLUBS,
            ES_SPADES,
        } ESuit;

        typedef enum EValue
        {
            EV_ONE,
            EV_TWO,
            EV_THREE,
            EV_FOUR,
            EV_FIVE,
            EV_SIX,
            EV_SEVEN,
            EV_EIGHT,
            EV_NINE,
            EV_TEN,
            EV_JACK,
            EV_QUEEN,
            EV_KING,
        } EValue;

        typedef struct TCard
        {
            ESuit eSuit;
            EValue eValue;
        } TCard;

        typedef struct THand
        {
            TCard tCard[2];
        } THand;

        typedef struct TCardsInPlay
        {
            TCard tCard[5];
            THand Hand1;
        } TCardsInPlay;

        typedef struct TDeck
        {
            TCard tCard[52];
            int iCount;
        } TDeck;


        extern TCardsInPlay g_tAllCards;
#endif
