#ifdef __unix__
    #define SO_Linux
#elif defined(_WIN32) || defined(WIN32)
    #define SO_Windows
#endif

#include <stdio.h>
#include "Interface.h"
#include "Onibus.h"
#include "Viagem.h"

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

    // Usamos a varivel viagem para dar o get onibus
    Onibus *onibus = criaOnibus();

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
                exibirAcentos(onibus, isWindows);
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

                /* While poltrona ocupada */

                // insere na lista
                // inserir na persistencia

                passagemComprada();
                pausa(isWindows);
                break;

            case 2: /* Cancelar passagem */
                break;
            case 3: /* Vizualizar a situacao de todos os acentos */
                exibirAcentos(onibus, isWindows);
                pausa(isWindows);
                break;

            case 4: /* Vizualizar a situacao de um determinado acento */
                exibirAcentos(onibus, isWindows);
                printf("Digite a fileira e coluna a ser consultada:\n");
                scanf("%d %d", &linha, &coluna);
                printf("\n");

                while (linha < 1 || coluna < 1 || linha > 12 || coluna > 4) {
                    printf(ANSI_COLOR_RED "O numero digitado nao corresponde ao numero de fileiras ou colunas!\n" ANSI_DEFAULT);
                    printf(ANSI_COLOR_RED "Por favor, digite a fileira e coluna do acento novamente\n" ANSI_DEFAULT);
                    scanf("%d %d", &linha, &coluna);
                    printf("\n");
                }

                getchar();
                 if (assentoVazio(onibus,linha - 1, coluna - 1)) {
                     printf(ANSI_COLOR_GREEN "O acento da fileira %d, coluna %d esta vazio!\n\n" ANSI_DEFAULT, linha, coluna);
                 } else {
                     printf(ANSI_COLOR_RED "O acento da fileira %d, coluna %d esta ocupado!\n\n" ANSI_DEFAULT, linha, coluna);
                 }

                pausa(isWindows);
                break;

            case 5: /* Exibir as passagens ja compradas */

                // Percorrer a lista de passagem vendidas, imprimindo as colunas

                break;
            case 6: /* Calcular total vendido (concatenar) */

                // Recuperamos as duas viagens da persistencia, para percorrer as passagens
                // vendidas, concatenamos as listas de passagens e percorremos somando

                break;
            case 7: /* Sair do aplicativo */
                printf("Obrigado por utilizar nossos servicos, volte sempre!");
                printf(ANSI_COLOR_RED " <3\n\n" ANSI_DEFAULT);
                break;
            default:
                printf(ANSI_COLOR_RED "Ops! Opcao invalida.\n" ANSI_DEFAULT);
                printf(ANSI_COLOR_RED "Por favor, digite uma opcao valida. Obrigado!\n\n" ANSI_DEFAULT);
                pausa(isWindows);
        }

    } while (opcao != 7);

    return 0;
}