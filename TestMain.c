#include <stdio.h>
#include "TestOnibus.h"
#include "TestPassageiro.h"
#include "TestPassagem.h"
#include "TestViagem.h"

int main() {
    agrupaTestesOnibus();
    printf("\n");
    agrupaTestesPassageiro();
    printf("\n");
    agrupaTestesPassagem();
    printf("\n");
    agrupaTestesViagem();
    printf("\n");

    return 0;
}