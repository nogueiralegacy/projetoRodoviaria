#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void linhasIniciais(int isWindows) {
    printf("             ");
    if (isWindows) {
        printf("%c", 201);
        for (int i = 0; i < 51; i++) {
            printf("%c", 205);
        }
        printf("%c\n", 187);

        printf("             %c     ", 186);
    } else {
        printf("\u2554");
        for (int i = 0; i < 51; i++) {
            printf("\u2550");
        }
        printf("\u2557\n");

        printf("             \u2551     ");
    }
}

void linhasFinais(int isWindows) {
    if (isWindows) {
        printf("      %c\n", 186);
        printf("             ");
        printf("%c", 200);
        for (int i = 0; i < 51; i++) {
            printf("\u2550");
        }
        printf("%c\n\n\n", 188);
    } else {
        printf("      \u2551\n");
        printf("             ");
        printf("\u255A");
        for (int i = 0; i < 51; i++) {
            printf("\u2550");
        }
        printf("\u255D\n\n\n");
    }
}

void imprimeLateral(int isWindows) {
    if (isWindows) {
        printf("     %c\n", 186);
        printf("             %c     ", 186);
    } else {
        printf("     \u2551\n");
        printf("             \u2551     ");
    }
}

void by(int isWindows) {
    if (isWindows) {
        printf("%c Felipe Moreira da Silva  | Engenharia de Software\n", 254);
        printf("%c Daniel Nogueira da Costa | Engenharia de Software\n\n\n", 254);
    } else {
        printf(ANSI_COLOR_RED "\u2578 Felipe Moreira da Silva  | Engenharia de Software\n" ANSI_DEFAULT);
        printf("\u2578 Daniel Nogueira da Costa | Engenharia de Software\n\n\n");
    }
}

void interfaceCompanhia(int isWindows) {
    linhasIniciais(isWindows);

    printf("-----------------------------------------");
    imprimeLateral(isWindows);

    printf("COMPANHIA DE VIAGENS RODOVIARIAS | UFG-ES");
    imprimeLateral(isWindows);

    printf("-----------------------------------------");
    imprimeLateral(isWindows);

    printf("           -------------------           ");
    imprimeLateral(isWindows);

    printf("          |   [UFG-ES]        |          ");
    imprimeLateral(isWindows);

    printf("           --O-O-----------O--           ");
    imprimeLateral(isWindows);

    printf("_  _  _  _  _  _  _  _  _  _  _  _  _  _ ");
    imprimeLateral(isWindows);
    printf("                                        ");

    linhasFinais(isWindows);
    by(isWindows);
}