#ifdef __unix__
    #define SO_Linux
#elif defined(_WIN32) || defined(WIN32)
    #define SO_Windows
#endif

#include <stdio.h>
#include "Interface.h"

 /**
  * Metodo para encontrar em qual SO a aplicaçao ta rodando
  * @return TRUE (1) Se for Windows ou FALSE (0) se nao for
  */
 int defineSO() {
    int isWindows = 0;

    #ifdef SO_Windows
        isWindows = 1;
    #endif

    return isWindows;
}

int main() {
    int isWindows = defineSO();
    int opcao, linha, coluna;

    /* Instanciar listas */

    /* Iniciar gravaçao em arquivos */

    interfaceCompanhia(isWindows);
    pausa(isWindows);

    do {
        menu(isWindows);
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch (opcao) {
            case 1: /* Comprar passagem */
                /* Receber dados do usuario */

                printf("Escolha um acento, que nao esteja ocupado ou reservado.\n\n");
                exibirAcentos(isWindows);
                printf("\n");

                printf("Digite a fileira e coluna do acento:\n");
                scanf("%d %d", &linha, &coluna);
                printf("\n");

                while (linha < 1 || coluna < 1 || linha > 12 || coluna > 4) {
                    printf(ANSI_COLOR_RED "O numero digitado nao corresponde ao numero de fileiras ou colunas!\n" ANSI_DEFAULT);
                    printf(ANSI_COLOR_RED "Por favor, digite a fileira e coluna do acento novamente\n" ANSI_DEFAULT);
                    scanf("%d %d", &linha, &coluna);
                    printf("\n");
                }

                /* While poltrona ocupada ou reservada */

                passagemComprada();

                /* Cadastrar */

                pausa(isWindows);
                break;

            case 2: /* Reservar um acento */
                break;
            case 3: /* Vizualizar a situacao de todos os acentos */
                break;
            case 4: /* Vizualizar a situacao de um determinado acento */
                break;
            case 5: /* Exibir as passagens ja compradas */
                break;
            case 6: /* Sair do aplicativo */
                break;
            default:
                printf(ANSI_COLOR_RED "Ops! Opcao invalida.\n" ANSI_DEFAULT);
                printf(ANSI_COLOR_RED "Por favor, digite uma opcao valida. Obrigado!\n\n" ANSI_DEFAULT);
                pausa(isWindows);
        }

    } while (opcao != 6);

    return 0;
}