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
            TCard TCard1;
            TCard TCard2;
        } THand;

        typedef struct TCardsInPlay
        {
            TCard Card1;
            TCard Card2;
            TCard Card3;
            TCard Card4;
            TCard Card5;
            THand Hand1;
        } TCardsInPlay;

        TCardsInPlay AllCards;

        typedef struct TDeck
        {
            TCard tCard[52];
            int iCount;
        } TDeck;

#endif
