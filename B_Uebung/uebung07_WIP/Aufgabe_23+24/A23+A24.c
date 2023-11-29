#include <stdio.h>
#include <stdlib.h>

#define MAX_ROLLS 10
#define MAX_DICE_VALUE 6

/* ----------------------------------- */

int read_bet(int kontostand_user, int kontostand_bot)
{
    int bet;

    do {
        /* Muss kleiner Bot und User sein */
        printf("Bitte geben Sie Ihren Wetteinsatz ein (maximal %d): ", kontostand_user < kontostand_bot ? kontostand_user : kontostand_bot);
        scanf("%d", &bet);
    }

    while (bet < 0 || bet > kontostand_user || bet > kontostand_bot);

    return bet;
}

/* ----------------------------------- */

int user_move()
{

    int sum = 0;
    int i;

    printf("Drücken Sie Enter für jeden Wurf.\n");

    for (i = 0; i < MAX_ROLLS; i++) {

        /* ich warte auf tastendruck und würfel dann */
        getchar();

        sum = sum + (rand() % MAX_DICE_VALUE) + 1;
    }
    return sum;
}

/* ----------------------------------- */

int bot_move()
{
    int sum = 0;
    int i;
    for (i = 0; i < MAX_ROLLS; i++) {

        sum = sum + (rand() % MAX_DICE_VALUE) + 1;
    }
    return sum;
}

/* ----------------------------------- */


int main(int argc, char *argv[])
{
    int kontostand_user;
    int kontostand_bot
    int bet;
    int user_sum;
    int bot_sum;

    if (argc != 2 || (kontostand_user = atoi(argv[1])) <= 0) {
        printf("Fehler: Ungültiger Kommandozeilenparameter.\n");
        return 1;
    }

    kontostand_bot = kontostand_user;

    while (kontostand_user > 0 && kontostand_bot > 0) {
        printf("User Kontostand: %d, Bot Kontostand: %d\n", kontostand_user, kontostand_bot);
        bet = read_bet(kontostand_user, kontostand_bot);

        user_sum = user_move();
        bot_sum = bot_move();

        printf("User Summe: %d, Bot Summe: %d\n", user_sum, bot_sum);

        if (user_sum > bot_sum) {
            printf("Sie haben gewonnen!\n");
            kontostand_user += bet;
            kontostand_bot -= bet;
        } else {
            printf("Computer hat gewonnen.\n");
            kontostand_user -= bet;
            kontostand_bot += bet;
        }
    }

    if (kontostand_user > 0) {
        printf("Glückwunsch! Sie haben gewonnen mit %d Münzen.\n", kontostand_user);
    } else {
        printf("Schade! Der Computer hat gewonnen mit %d Münzen.\n", kontostand_bot);
    }

    return 0;
}
