#include "Viagem.h"
#include "TestViagem.h"
#include "stdio.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"


void testIniciaPassagemVendida() {
    // Cria uma passagem sem atributos
    struct passagem *passagem = criaPassagem();

    // Configura o código da passagem
    setCodigoDaPassagem(passagem, "12345678910");


    PassagemVendida *passagemVendida = iniciaPassagemVendida(passagem);

    if (strcmp(getCodigoDaPassagem(passagem), getCodigoDaPassagem(getPassagem(passagemVendida))) == 0) {
        if (getProximo(passagemVendida) == NULL) {
            printf(ANSI_COLOR_GREEN "testIniciaPassagemVendida(): Success!\n" ANSI_DEFAULT);
            liberaPassagemVendida(passagemVendida);
            return;
        }
    }

    printf(ANSI_COLOR_RED "testIniciaPassagemVendida(): Failed!\n" ANSI_DEFAULT);
    liberaPassagemVendida(passagemVendida);
}


void testInsereListaPassagensVendidas() {
    // Cria passagem1 sem atributos
    struct passagem *passagem1 = criaPassagem();

    // Configura o código da passagem1
    setCodigoDaPassagem(passagem1, "12345678910");

    // Cria passagem2 sem atributos
    struct passagem *passagem2 = criaPassagem();

    // Configura o código da passagem2
    setCodigoDaPassagem(passagem2, "10987654321");

    // Instancia a lista de passagens vendidas
    ListaPassagensVendidas *listaPassagensVendidas = iniciaListaPassagensVendidas();

    // Insere passagemVendida1 e passagemVendida2 na lista
    insereListaPassagensVendidas(listaPassagensVendidas, passagem1);
    insereListaPassagensVendidas(listaPassagensVendidas, passagem2);

    PassagemVendida *primeiraPassagemVendida = getInicioListaPassagensVendidas(listaPassagensVendidas);
    PassagemVendida *segundaPassagemVendida = getProximo(primeiraPassagemVendida);

    PassagemVendida *ultimaPassagemVendida = getFimListaPassagensVendidas(listaPassagensVendidas);
    /* Verifica se a lista de passagens vendidas foi instanciada corretamente */
    //Verifica se a primeira passagemVendida é a passagem1
    if (getCodigoDaPassagem(getPassagem(primeiraPassagemVendida)) == getCodigoDaPassagem(passagem1)) {
        //Verifica se a última passagemVendida é a passagem2
        if (getCodigoDaPassagem(getPassagem(ultimaPassagemVendida)) == getCodigoDaPassagem(passagem2)) {
            //Verifica se a segunda passagem é a passagem2
            if (getCodigoDaPassagem(getPassagem(segundaPassagemVendida)) == getCodigoDaPassagem(passagem2)) {
                //Verifica se a segunda passagemVendida não tem próximo
                if (getProximo(segundaPassagemVendida) == NULL) {
                    printf(ANSI_COLOR_GREEN "testIniciaListaDePassagensVendidas(): Success!\n" ANSI_DEFAULT);
                    liberaListaDePassagensVendidas(listaPassagensVendidas);
                    return;
                }
            }
        }
    }

    printf(ANSI_COLOR_RED "testIniciaListaDePassagensVendidas(): Failed!\n" ANSI_DEFAULT);
    liberaListaDePassagensVendidas(listaPassagensVendidas);
}

void testRecuperaViagem() {
    Viagem *viagem = criaViagem();

    recuperaViagem(viagem, "testViagem.csv", "testOnibus.csv", "testPassagem.csv", "testPassageiro.csv");

    char *codigoDoOnibus = getCodigoDoOnibus(getOnibus(viagem));
    PassagemVendida *passagemVendida = getPrimeiraPassagemVendida(viagem);
    char *codigoDaPassagem = getCodigoDaPassagem(getPassagem(passagemVendida));

    if (strcmp(codigoDoOnibus, "20122002") == 0) {
        if (strcmp(codigoDaPassagem, "241202") == 0) {
            printf(ANSI_COLOR_GREEN "testRecuperaViagem(): Success!\n" ANSI_DEFAULT);
            liberaViagem(viagem);
            return;
        }
    }

    printf(ANSI_COLOR_RED "testRecuperaViagem(): Failed!\n" ANSI_DEFAULT);
    liberaViagem(viagem);
}

void agrupaTestesViagem() {
    printf("------ Testes Viagem.c -------\n");
    testIniciaPassagemVendida();
    printf("\n");
    testInsereListaPassagensVendidas();
    printf("\n");
    testRecuperaViagem();
    printf("\n");
}