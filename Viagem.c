struct Viagem {
    char codigoDaViagem[12];
    char companhia[50];
    char origem[50];
    char destino[50];
    char data[10];
    char hora[5];
    struct passagem *passagens;
    struct onibus *onibus;
};

typedef struct Viagem Viagem;