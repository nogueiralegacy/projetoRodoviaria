struct passagem {
    char codigoDaPassagem[12];
    char fileira;
    char poltrona;
    double valor;
    // Executada ou Pendente (Quando uma passagem é executada significa que
    // o passageiro já embarcou no ônibus)
    char status[12];
    struct passageiro *passageiro;
};

typedef struct passagem Passagem;
