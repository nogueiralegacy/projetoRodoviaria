#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

void iniciaInterface(int isWindows) {
    printf("\n\n");
    printf("            ");
    if (isWindows) {
        printf(ANSI_COLOR_CYAN "%c" ANSI_DEFAULT, 201);
        for (int i = 0; i < 51; i++) {
            printf(ANSI_COLOR_CYAN "%c" ANSI_DEFAULT, 205);
        }
        printf(ANSI_COLOR_CYAN "%c\n" ANSI_DEFAULT, 187);

        printf(ANSI_COLOR_CYAN "             %c     " ANSI_DEFAULT, 186);
    } else {
        printf(ANSI_COLOR_CYAN " \u2554" ANSI_DEFAULT);
        for (int i = 0; i < 51; i++) {
            printf(ANSI_COLOR_CYAN "\u2550" ANSI_DEFAULT);
        }
        printf(ANSI_COLOR_CYAN "\u2557\n" ANSI_DEFAULT);

        printf(ANSI_COLOR_CYAN "             \u2551     " ANSI_DEFAULT);
    }
}

void finalizaInterface(int isWindows) {
    if (isWindows) {
        printf(ANSI_COLOR_CYAN "      %c\n" ANSI_DEFAULT, 186);
        printf(ANSI_COLOR_CYAN "             ");
        printf(ANSI_COLOR_CYAN "%c" ANSI_DEFAULT, 200);
        for (int i = 0; i < 51; i++) {
            printf(ANSI_COLOR_CYAN "%c" ANSI_DEFAULT, 205);
        }
        printf(ANSI_COLOR_CYAN "%c\n\n\n" ANSI_DEFAULT, 188);
    } else {
        printf(ANSI_COLOR_CYAN "      \u2551\n" ANSI_DEFAULT);
        printf("             ");
        printf(ANSI_COLOR_CYAN "\u255A" ANSI_DEFAULT);
        for (int i = 0; i < 51; i++) {
            printf(ANSI_COLOR_CYAN "\u2550" ANSI_DEFAULT);
        }
        printf(ANSI_COLOR_CYAN "\u255D\n\n\n" ANSI_DEFAULT);
    }
}

void imprimeLateral(int isWindows) {
    if (isWindows) {
        printf(ANSI_COLOR_CYAN "     %c\n" ANSI_DEFAULT, 186);
        printf(ANSI_COLOR_CYAN "             %c     " ANSI_DEFAULT, 186);
    } else {
        printf(ANSI_COLOR_CYAN "     \u2551\n" ANSI_DEFAULT);
        printf(ANSI_COLOR_CYAN "             \u2551     " ANSI_DEFAULT);
    }
}

void by(int isWindows) {
    if (isWindows) {
        printf(ANSI_COLOR_YELLOW "%c Felipe Moreira da Silva  | Engenharia de Software\n" ANSI_DEFAULT, 254);
        printf(ANSI_COLOR_YELLOW "%c Daniel Nogueira da Costa | Engenharia de Software\n\n\n" ANSI_DEFAULT, 254);
    } else {
        printf(ANSI_COLOR_YELLOW "\u2578 Felipe Moreira da Silva  | Engenharia de Software\n" ANSI_DEFAULT);
        printf(ANSI_COLOR_YELLOW "\u2578 Daniel Nogueira da Costa | Engenharia de Software\n\n\n" ANSI_DEFAULT);
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

    printf("          |   ");
    printf(ANSI_COLOR_MAGENTA "[UFG-ES]" ANSI_DEFAULT);
    printf("        |          ");
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
    /* vai receber as viagens da persistencia */
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
        printf("%c    2 - Cancelar passagem.                                  %c\n", 186, 186);
        printf("%c    3 - Vizualizar a situacao de todos os acentos.          %c\n", 186, 186);
        printf("%c    4 - Vizualizar a situacao de um determinado acento.     %c\n", 186, 186);
        printf("%c    5 - Exibir as passagens ja compradas.                   %c\n", 186, 186);
        printf("%c    6 - Calcular total vendido.                             %c\n", 186, 186);
        printf("%c    7 - Sair do aplicativo.                                 %c\n", 186, 186);
        printf("%c                                                            %c\n", 186, 186);
    } else {
        printf("\u2551                                                            \u2551\n");
        printf("\u2551    1 - Comprar passagem.                                   \u2551\n");
        printf("\u2551    2 - Cancelar passagem.                                  \u2551\n");
        printf("\u2551    3 - Vizualizar a situacao de todos os acentos.          \u2551\n");
        printf("\u2551    4 - Vizualizar a situacao de um determinado acento.     \u2551\n");
        printf("\u2551    5 - Exibir as passagens ja compradas.                   \u2551\n");
        printf("\u2551    6 - Calcular total vendido.                             \u2551\n");
        printf("\u2551    7 - Sair do aplicativo.                                 \u2551\n");
        printf("\u2551                                                            \u2551\n");
    }

    finalizaMenu(isWindows);
    printf("Escoha uma opcao:\n");
}

void comprarPassagem() {
    char nome[50];
    char cpf[12];
    char telefone[12];
    char email[50];
    char telefoneDeEmergencia[12];

    printf("Digite o nome do passageiro:\n");
    fgets(nome, 50, stdin);
    printf("\n");

    printf("Digite o CPF do passageiro: (EX: 12345678912)\n");
    fgets(cpf, 12, stdin);
    printf("\n");

    printf("Digite o numero de telefone do passageiro:\n");
    fgets(telefone, 12, stdin);
    printf("\n");

    printf("Digite o endereco de email do passageiro:\n");
    fgets(email, 50, stdin);
    printf("\n");

    printf("Digite um numero de telefone em caso de emergencias:\n");
    fgets(telefoneDeEmergencia, 12, stdin);
    printf("\n");

    /* Alinhar e passar para passageiro */
}

void recadoAcentos() {
    printf(ANSI_COLOR_YELLOW "IMPORTANTE: As colunas de numero 1 e 4 sao referentes aos acentos na JANELA.\n" ANSI_DEFAULT);
    printf(ANSI_COLOR_YELLOW "IMPORTANTE: As colunas de numero 2 e 3 sao referentes aos acentos no CORREDOR.\n\n" ANSI_DEFAULT);
}

void imprimeLegenda(int isWindows) {
    printf("++++++++ LEGENDA ++++++++\n");

    printf("+ ");
    printf(ANSI_COLOR_BLUE "[]" ANSI_DEFAULT);
    printf(" - Acento vazio     +\n");

    if (isWindows) {
        printf("+ ");
        printf(ANSI_COLOR_BLUE "%c%c" ANSI_DEFAULT, 219, 219);
        printf(" - Acento ocupado   +\n");
    } else {
        printf("+ ");
        printf(ANSI_COLOR_BLUE "\u2589\u2589" ANSI_DEFAULT);
        printf(" - Acento ocupado   +\n");
    }

    printf("+++++++++++++++++++++++++\n\n");
}

void exibirAcentos(Onibus *onibus, int isWindows) {
    int linha, coluna;

    recadoAcentos();

    printf(ANSI_COLOR_CYAN "+++++++ EXIBICAO DOS ACENTOS +++++++\n\n" ANSI_DEFAULT);
    printf("   ESQUERDA  |  DIREITA\n\n");
    printf("     01  02     03  04\n\n");

    for (linha = 0; linha < getQuantidadeDeFileiras(onibus); linha ++) {
        printf("%02d - ", linha + 1);

        for (coluna = 0; coluna < getQuantidadeDeColunas(onibus) - 1; coluna++) {

            if (assentoVazio(onibus, linha, coluna)) {
                printf(ANSI_COLOR_BLUE "[]  " ANSI_DEFAULT);
            } else {
                if (isWindows) printf(ANSI_COLOR_BLUE "%c%c  " ANSI_DEFAULT, 219, 219);
                else printf(ANSI_COLOR_BLUE "\u2589\u2589  " ANSI_DEFAULT);
            }

            if (coluna == 1) printf("|  ");
        }

        if (assentoVazio(onibus, linha, coluna)) {
            printf(ANSI_COLOR_BLUE "[]\n\n" ANSI_DEFAULT);
        } else {
            if (isWindows) printf(ANSI_COLOR_BLUE "%c%c  \n\n" ANSI_DEFAULT, 219, 219);
            else printf(ANSI_COLOR_BLUE "\u2589\u2589  \n\n" ANSI_DEFAULT);
        }
    }

    imprimeLegenda(isWindows);
}

void exibirPassagemComprada() {

} // implementar ainda mec, so copiar

void passagemComprada() {
    printf(ANSI_COLOR_GREEN "Sua passagem foi comprada com sucesso!\n" ANSI_DEFAULT);
    printf(ANSI_COLOR_GREEN "Muito obrigado pela sua preferencia :)\n\n" ANSI_DEFAULT);
}

void passagemCancelada() {
    printf(ANSI_COLOR_GREEN "Sua passagem foi cancelada com sucesso!\n" ANSI_DEFAULT);
    printf(ANSI_COLOR_GREEN "Muito obrigado pela sua preferencia :)\n\n" ANSI_DEFAULT);
}