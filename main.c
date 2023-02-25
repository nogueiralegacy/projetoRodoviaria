#ifdef __unix__
    #define SO_Linux
#elif defined(_WIN32) || defined(WIN32)
    #define SO_Windows
#endif

#include <stdio.h>
#include <time.h>
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

/**
 * Metodo para gerar um codigo de passagem aleatorio
 * @param saida String com codigo
 */
void gerarCodigoPassagem(char *saida) {
    srand(time(NULL));
    int codigo = rand() % 1000;
    sprintf(saida, "%d", codigo);
 }

int main() {
    int isWindows = defineSO();
    int opcao, linha, coluna;

    /* Instanciar viagem */
    Viagem *viagemDisponivel = criaViagem();
    recuperaViagem(viagemDisponivel, "viagem.csv", "onibus.csv", "passagem.csv", "passageiro.csv");

    interfaceCompanhia(isWindows);
    pausa(isWindows);

    viagensDisponiveis(viagemDisponivel);
    pausa(isWindows);

    do {
        menu(isWindows);
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch (opcao) {
            case 1:; /* Comprar passagem */

                /* Receber dados do usuario */
                Passageiro *novoPassageiro = comprarPassagem();

                printf("Escolha um acento, que nao esteja ocupado ou reservado.\n\n");
                exibirAcentos(getOnibus(viagemDisponivel), isWindows);
                printf("\n");

                printf("Digite a fileira e coluna do acento:\n");
                while (1) {
                    scanf("%d %d", &linha, &coluna);
                    printf("\n");

                    if (linha < 1 || coluna < 1 || linha > 12 || coluna > 4) {
                        printf(ANSI_COLOR_RED "O numero digitado nao corresponde ao numero de fileiras ou colunas!\n" ANSI_DEFAULT);
                        printf(ANSI_COLOR_RED "Por favor, digite a fileira e coluna do acento novamente\n" ANSI_DEFAULT);
                        continue;
                    }

                    if (!assentoVazio(getOnibus(viagemDisponivel),linha - 1, coluna - 1)) {
                        printf(ANSI_COLOR_RED "Esse acento nao esta disponivel! Por favor escolha outro.\n" ANSI_DEFAULT);
                        printf(ANSI_COLOR_RED "Digite novamente a fileira e coluna do acento:\n" ANSI_DEFAULT);
                        continue;
                    }
                    break;
                }

                /* Ocupa o acento dentro do Onibus */
                setAssento(getOnibus(viagemDisponivel),linha, coluna);

                /* Inserindo passageiro na lista */
                char codigoPassagem[12];
                gerarCodigoPassagem(codigoPassagem);
                Passagem *passagemComprada = iniciaPassagem(codigoPassagem, linha, coluna, 375.00, novoPassageiro);
                insereListaPassagensVendidas(getListaPassagensVendidas(viagemDisponivel), passagemComprada);

                /* Inserir na persistencia */
                salvaPassagem(passagemComprada, "passagem.csv");
                salvarOnibus(getOnibus(viagemDisponivel), "onibus.csv");

                getchar();
                passagemCompradaComSucesso();
                pausa(isWindows);

                /* Liberar passagem e passageiro */
                liberaPassagem(passagemComprada);
                break;

            case 2:; /* Cancelar passagem */

                char cpfTemp[12];
                printf("Digite o CPF do passageiro para remover:\n");
                fgets(cpfTemp, 12, stdin);
                printf("\n");

                cpfTemp[strcspn(cpfTemp, "\n")] = '\0';
                removerPassageiro("passageiro.csv", cpfTemp);

                break;
            case 3: /* Vizualizar a situacao de todos os acentos */
                exibirAcentos(getOnibus(viagemDisponivel), isWindows);
                pausa(isWindows);
                break;

            case 4: /* Vizualizar a situacao de um determinado acento */

                exibirAcentos(getOnibus(viagemDisponivel), isWindows);
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
                 if (assentoVazio(getOnibus(viagemDisponivel),linha - 1, coluna - 1)) {
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