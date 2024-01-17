#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void delay(int sec)
{
    int ms = 1000 * sec;
    clock_t st = clock();
    while (clock() < st + ms)
    {
    }
}
int main()
{
    int roundu = 0;
    int roundc = 0;
    char s[69];
    int a, b, n;
    char c[] = "COMPUTER\0";
    printf("\n\n\n          WELCOME IN THE GAME         \n");
    printf("\n     STONE-PAPER-SCISSOR AGAINST PC\n");
    printf("\nENTER YOUR NAME (IN BLOCK LETTERS)\n");
    fgets(s, 69, stdin);
    int l = strlen(s);
    s[l - 1] = '\0';
    char *h[] = {"STONE", "PAPER", "SCISSOR"};
    printf("\n--------------------------------------------\n");
    printf("\nSELECT YOUR DESIRE NUMBER OF ROUNDS\n");
    scanf("%d", &a);
    printf("\nSELECT YOUR DESIRE NUMBER OF PLAY PER ROUND\n");
    scanf("%d", &b);
    printf("\n---------------------------------------------\n");
    for (int i = 1; i <= a; i++)
    {
        srand((time(NULL)));
        int score1 = 0;
        int score2 = 0;
        printf("\n---------------------------------------------\n");
        printf("\nROUND %d BEGINS\n", i);
        printf("\n---------------------------------------------\n");
        delay(3);
        printf("\n\nPRESS 1 -> STONE\n");
        printf("\nPRESS 2 -> PAPER\n");
        printf("\nPRESS 3 -> SCISSOR\n\n");
        printf("\n---------------------------------------------\n");
        delay(3);
        for (int j = 1; j <= b; j++)
        {
            printf("\nPLAY %d\n", j);
            printf("\n%s PLAYED ->\n", s);
            scanf("%d", &n);
            int r = rand() % 3;
            printf("\n%s PLAYED ->\n%s\n", c, h[r]);
            printf("\n---------------------------------------------\n");
            delay(2);
            if ((r == 0 && r + 1 == n) || (r == 1 && r + 1 == n) || (r == 2 && r + 1 == n))
            {
                printf("\nDRAW\n");
                printf("\n%s's SCORE -> %d\n", s, score1);
                printf("\n%s's SCORE -> %d\n", c, score2);
                printf("\n---------------------------------------------\n");
                delay(2);
            }
            else if ((n == 1 && r == 2) || (n == 2 && r == 0) || (n == 3 && r == 1))
            {
                score1++;
                printf("\n%s's SCORE -> %d\n", s, score1);
                printf("\n%s's SCORE -> %d\n", c, score2);
                printf("\n---------------------------------------------\n");
                delay(2);
            }
            else
            {
                score2++;
                printf("\n%s's SCORE -> %d\n", s, score1);
                printf("\n%s's SCORE -> %d\n", c, score2);
                printf("\n---------------------------------------------\n");
                delay(2);
            }
        }
        if (score1 > score2)
        {
            printf("\n---------------------------------------------\n");
            printf("\n%s WON ROUND %d\n", s, i);
            printf("\n---------------------------------------------\n");
            roundu++;
            printf("\n%s's ROUND SCORE -> %d\n", s, roundu);
            printf("\n%s's ROUND SCORE -> %d\n", c, roundc);
            delay(2);
        }
        else if (score1 == score2)
        {
            printf("\n---------------------------------------------\n");
            printf("\nROUND %d IS DRAW\n", i);
            printf("\n---------------------------------------------\n");
            printf("\n%s's ROUND SCORE -> %d\n", s, roundu);
            printf("\n%s's ROUND SCORE -> %d\n", c, roundc);
            delay(2);
        }
        else
        {
            printf("\n---------------------------------------------\n");
            printf("\n%s WON ROUND %d\n", c, i);
            printf("\n---------------------------------------------\n");
            roundc++;
            printf("\n%s's ROUND SCORE -> %d\n", s, roundu);
            printf("\n%s's ROUND SCORE -> %d\n", c, roundc);
            delay(2);
        }
    }
    if (roundu > roundc)
    {
        printf("\n---------------------------------------------\n");
        printf("\nCONGRATULATIONS %s, YOU WON THE MATCH\n", s);
        printf("\n---------------------------------------------\n\n");
        delay(2);
    }
    else if (roundu == roundc)
    {
        printf("\n---------------------------------------------\n");
        printf("\nMATCH IS DRAW\n");
        printf("\nBETTER LUCK NEXT TIME\n");
        printf("\n---------------------------------------------\n\n");
        delay(2);
    }
    else
    {
        printf("\n---------------------------------------------\n");
        printf("\n%s WON THE MATCH\n", c);
        printf("\nBETTER LUCK NEXT TIME %s\n", s);
        printf("\n---------------------------------------------\n\n");
        delay(2);
    }
}