#ifndef CARDPUBLIC_H
    #define CARDPUBLIC_H
        enum ESuit
        {
            ES_HEARTS,
            ES_DIAMONDS,
            ES_CLUBS,
            ES_SPADES,
        };

        enum EValue
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
        };

        struct TCard
        {
            ESuit eSuit;
            EValue eValue;
        };

        struct THand
        {
            TCard tCard[11];
            int iCount;
        };

        struct TCardsInPlay
        {
            TCard tCard[5];
            THand HandUser;
            THand HandDealer;
        };

        struct TDeck
        {
            TCard tCard[52];
            int iCount;
        };


        extern TCardsInPlay g_tAllCards;
        extern int g_tAmountOfCards;
#endif
