#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

void iniciaInterface(int isWindows) {
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

void finalizaInterface(int isWindows) {
    if (isWindows) {
        printf("      %c\n", 186);
        printf("             ");
        printf("%c", 200);
        for (int i = 0; i < 51; i++) {
            printf("%c", 205);
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
        printf(ANSI_COLOR_RED "%c Felipe Moreira da Silva  | Engenharia de Software\n" ANSI_DEFAULT, 254);
        printf(ANSI_COLOR_RED "%c Daniel Nogueira da Costa | Engenharia de Software\n\n\n" ANSI_DEFAULT, 254);
    } else {
        printf(ANSI_COLOR_RED "\u2578 Felipe Moreira da Silva  | Engenharia de Software\n" ANSI_DEFAULT);
        printf(ANSI_COLOR_RED "\u2578 Daniel Nogueira da Costa | Engenharia de Software\n\n\n" ANSI_DEFAULT);
    }
}

void interfaceCompanhia(int isWindows) {
    iniciaInterface(isWindows);

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

    finalizaInterface(isWindows);
    by(isWindows);
}

void pausa(int isWindows) {
    printf("\t\t\tPressione ENTER para continuar.");
    getchar();

    if (isWindows) {
        system("cls");
    } else {
        system("clear");
    }
}

void viagensDisponiveis() {
    printf("++++++ VIAGENS  DISPONIVEIS ++++++\n\n");

    printf("+--------------------------------+\n");
    printf("| Viagem 1:                      |\n");
    printf("| -> Partindo de: ANAPOLIS       |\n");
    printf("| <- Indo para: GOIANIA          |\n");
    printf("| Horario de Saida: 17:00hrs     |\n| Horario de Chegada: 18:00hrs   |\n");
    printf("| ROTA 0001 - ONIBUS N 202105027 |\n");
    printf("| Valor da passagem: R$ 100,00   |\n");
    printf("+--------------------------------+\n\n");

    printf("+--------------------------------+\n");
    printf("| Viagem 2:                      |\n");
    printf("| -> Partindo de: SAO PAULO      |\n");
    printf("| <- Indo para: RIO DE JANEIRO   |\n");
    printf("| Horario de Saida: 07:00hrs     |\n| Horario de Chegada: 14:30hrs   |\n");
    printf("| ROTA 0002 - ONIBUS N 202105048 |\n");
    printf("| Valor da passagem: R$ 350,00   |\n");
    printf("+--------------------------------+\n\n");
}

void iniciaMenu(int isWindows) {
    int i;
    if (isWindows) {
        printf("%c", 201);
        for (i = 0; i < 25; i++) {
            printf("%c", 205);
        }
        printf(" M E N U ");
        for (i = 0; i < 26; i++) {
            printf("%c", 205);
        }
        printf("%c\n", 187);
    } else {
        printf("\u2554");
        for (i = 0; i < 25; i++) {
            printf("\u2550");
        }
        printf(" M E N U ");
        for (i = 0; i < 26; i++) {
            printf("\u2550");
        }
        printf("\u2557\n");
    }
}

void finalizaMenu(int isWindows) {
    int i;
    if (isWindows) {
        printf("%c", 200);
        for (i = 0; i < 60; i++) {
            printf("%c", 205);
        }
        printf("%c\n\n", 188);
    } else {
        printf("\u255A", 200);
        for (i = 0; i < 60; i++) {
            printf("\u2550", 205);
        }
        printf("\u255D\n\n", 188);
    }
}

void menu(int isWindows) {
    iniciaMenu(isWindows);

    if (isWindows) {
        printf("%c                                                            %c\n", 186, 186);
        printf("%c    1 - Comprar passagem.                                   %c\n", 186, 186);
        printf("%c    2 - Reservar um acento.                                 %c\n", 186, 186);
        printf("%c    3 - Vizualizar a situacao de todos os acentos.          %c\n", 186, 186);
        printf("%c    4 - Vizualizar a situacao de um determinado acento.     %c\n", 186, 186);
        printf("%c    5 - Exibir as passagens ja compradas.                   %c\n", 186, 186);
        printf("%c    6 - Sair do aplicativo.                                 %c\n", 186, 186);
        printf("%c                                                            %c\n", 186, 186);
    } else {
        printf("\u2551                                                            \u2551\n");
        printf("\u2551    1 - Comprar passagem.                                   \u2551\n");
        printf("\u2551    2 - Reservar um acento.                                 \u2551\n");
        printf("\u2551    3 - Vizualizar a situacao de todos os acentos.          \u2551\n");
        printf("\u2551    4 - Vizualizar a situacao de um determinado acento.     \u2551\n");
        printf("\u2551    5 - Exibir as passagens ja compradas.                   \u2551\n");
        printf("\u2551    6 - Sair do aplicativo.                                 \u2551\n");
        printf("\u2551                                                            \u2551\n");
    }

    finalizaMenu(isWindows);
    printf("Escoha uma opcao:\n");
}

void recadoAcentos() {
    printf("IMPORTANTE: As colunas de numero 1 e 4 sao referentes aos acentos na JANELA.\n");
    printf("IMPORTANTE: As colunas de numero 2 e 3 sao referentes aos acentos no CORREDOR.\n\n");
}

void imprimeLegenda(int isWindows) {
    printf("++++++++ LEGENDA ++++++++\n");
    printf("+ [] - Acento vazio     +\n");

    if (isWindows) printf("+ %c%c - Acento ocupado   +\n", 219, 219);
    else printf("+ \u2589\u2589 - Acento ocupado   +\n");

    if (isWindows) printf("+ %c%c - Acento reservado +\n", 176, 176);
    else printf("+ \u2591\u2591 - Acento reservado +\n");

    printf("+++++++++++++++++++++++++\n\n");
}

void exibirAcentos(int isWindows) { /* precisa receber a lista */
    recadoAcentos();

    printf("+++++++ EXIBICAO DOS ACENTOS +++++++\n\n");
    printf("   ESQUERDA  |  DIREITA\n\n"); // podemos colocar ASC179
    printf("     01  02     03  04\n\n");

    // Aqui vamos percorrer a lista de acentos, alinhar com Daniel como fazer ser o FOR
    // Legendas ja definidas

    imprimeLegenda(isWindows);
}

void exibirPassagemComprada() {

} // implementar ainda mec, so copiar

void passagemComprada() {
    printf(ANSI_COLOR_GREEN "Sua passagem foi comprada com sucesso!\n" ANSI_DEFAULT);
    printf(ANSI_COLOR_GREEN "Muito obrigado pela sua preferencia :)\n\n" ANSI_DEFAULT);
}

void passagemReservada() {
    printf(ANSI_COLOR_GREEN "Sua passagem foi reservada com sucesso!\n" ANSI_DEFAULT);
    printf(ANSI_COLOR_GREEN "Muito obrigado pela sua preferencia :)\n\n" ANSI_DEFAULT);
}