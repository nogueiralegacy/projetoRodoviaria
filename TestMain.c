#include "TestOnibus.h"
#include "TestPassageiro.h"
#include "TestPassagem.h"
#include "TestViagem.h"

int main() {
    agrupaTestesOnibus();
    agrupaTestesPassageiro();
    agrupaTestesPassagem();
    agrupaTestesViagem();

    return 0;
}