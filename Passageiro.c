#include "Passageiro.h"

const char *FORMATO_PASSAGEIRO_OUT = "(%s,%s,%s,%s,%s)";
const char *FORMATO_PASSAGEIRO_IN = "(%[^,],%[^,],%[^,],%[^,],%[^)])\n";

struct passageiro {
    char nome[50];
    char cpf[12];
    char telefone[12];
    char email[50];
    char telefoneDeEmergencia[12];
};

typedef struct passageiro Passageiro;

Passageiro *iniciaPassageiro(char nome[50], char cpf[12], char telefone[12], char email[50], char telefoneDeEmergencia[12]) {
    Passageiro *passageiro = (Passageiro *) malloc(sizeof(Passageiro));
    strcpy(passageiro->nome, nome);
    strcpy(passageiro->cpf, cpf);
    strcpy(passageiro->telefone, telefone);
    strcpy(passageiro->email, email);
    strcpy(passageiro->telefoneDeEmergencia, telefoneDeEmergencia);

    return passageiro;
}

Passageiro *criaPassageiro() {
    Passageiro *passageiro = (Passageiro *) malloc(sizeof(Passageiro));
    strcpy(passageiro->nome, "");
    strcpy(passageiro->cpf, "");
    strcpy(passageiro->telefone, "");
    strcpy(passageiro->email, "");
    strcpy(passageiro->telefoneDeEmergencia, "");

    return passageiro;
}

void liberaPassageiro(Passageiro *passageiro) {
    free(passageiro);
}

char *getNome(Passageiro *passageiro) {
    return passageiro->nome;
}

char *getCpf(Passageiro *passageiro) {
    return passageiro->cpf;
}

char *getTelefone(Passageiro *passageiro) {
    return passageiro->telefone;
}

char *getEmail(Passageiro *passageiro) {
    return passageiro->email;
}

char *getTelefoneDeEmergencia(Passageiro *passageiro) {
    return passageiro->telefoneDeEmergencia;
}

void setNome(Passageiro *passageiro, char nome[50]) {
    strcpy(passageiro->nome, nome);
}

void setCpf(Passageiro *passageiro, char cpf[12]) {
    strcpy(passageiro->cpf, cpf);
}

void setTelefone(Passageiro *passageiro, char telefone[12]) {
    strcpy(passageiro->telefone, telefone);
}

void setEmail(Passageiro *passageiro, char email[50]) {
    strcpy(passageiro->email, email);
}

void setTelefoneDeEmergencia(Passageiro *passageiro, char telefoneDeEmergencia[12]) {
    strcpy(passageiro->telefoneDeEmergencia, telefoneDeEmergencia);
}

void salvaPassageiro(Passageiro *passageiro, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a+");

    passageiro->nome[strcspn(passageiro->nome, "\n")] = '\0';
    passageiro->cpf[strcspn(passageiro->cpf, "\n")] = '\0';
    passageiro->telefone[strcspn(passageiro->telefone, "\n")] = '\0';
    passageiro->email[strcspn(passageiro->email, "\n")] = '\0';
    passageiro->telefoneDeEmergencia[strcspn(passageiro->telefoneDeEmergencia, "\n")] = '\0';

    fprintf(arquivo, FORMATO_PASSAGEIRO_OUT, passageiro->nome, passageiro->cpf, passageiro->telefone, passageiro->email,
            passageiro->telefoneDeEmergencia);
    fprintf(arquivo, "\n");
    fclose(arquivo);
}

void recuperaPassageiro(Passageiro *passageiro, char *nomeDoArquivo, char *cpf) {
    FILE *arquivo;
    arquivo = fopen(nomeDoArquivo, "r");

    char linha[200];
    while (fgets(linha, 200, arquivo) != NULL) {
        sscanf(linha, FORMATO_PASSAGEIRO_IN, passageiro->nome, passageiro->cpf, passageiro->telefone, passageiro->email,
               passageiro->telefoneDeEmergencia);
        if (strcmp(passageiro->cpf, cpf) == 0) {
            break;
        }
    }
    fclose(arquivo);
}

void removerPassageiro(char *nomeDoArquivo , char *cpf) {
    FILE *arquivo = fopen(nomeDoArquivo, "r");
    FILE* arquivoTemporario = fopen("temp.csv", "a+");

    Passageiro *passageiro = criaPassageiro();
    char linha[200];
    while (fgets(linha, 200, arquivo) != NULL) {

        sscanf(linha, FORMATO_PASSAGEIRO_IN, passageiro->nome, passageiro->cpf, passageiro->telefone, passageiro->email,
               passageiro->telefoneDeEmergencia);

        if (strcmp(passageiro->cpf, cpf) != 0) {
            fprintf(arquivoTemporario, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemporario);

    remove(nomeDoArquivo);
    rename("temp.csv", nomeDoArquivo);
}
