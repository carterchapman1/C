#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **MakeCardGroup() {
    const char *C_Value[] = {
        "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
    };
    const char *C_Suit[] = {
        " of Spades", " of Clubs", " of Hearts", " of Diamonds"
    };

    int num_values = sizeof(C_Value) / sizeof(C_Value[0]);
    int num_suits = sizeof(C_Suit) / sizeof(C_Suit[0]);
    int total_cards = num_values * num_suits;

    char **C_List = malloc(total_cards * sizeof(char *));
    if (C_List == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int c_index = 0;
    for (int y = 0; y < num_suits; y++) {
        for (int i = 0; i < num_values; i++) {
            size_t c_len = strlen(C_Value[i]) + strlen(C_Suit[y]) + 1;
            C_List[c_index] = malloc(c_len);
            if (C_List[c_index] == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }

            strcpy(C_List[c_index], C_Value[i]);
            strcat(C_List[c_index], C_Suit[y]);
            c_index++;
        }
    }

    return C_List;
}

int main() {
    char **deck = MakeCardGroup();
    int total_cards = 13 * 4;

    for (int i = 0; i < total_cards; i++) {
        printf("%s\n", deck[i]);
    }
    return 0;
}