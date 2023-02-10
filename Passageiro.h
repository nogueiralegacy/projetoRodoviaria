#ifndef PROJETORODOVIARIA_PASSAGEIRO_H
#define PROJETORODOVIARIA_PASSAGEIRO_H

 typedef struct passageiro Passageiro;

Passageiro *iniciaPassageiro(char nome[50], char cpf[12], char telefone[12], char email[50], char telefoneDeEmergencia[12]);

Passageiro *criaPassageiro();

void liberaPassageiro(Passageiro *passageiro);

char *getNome(Passageiro *passageiro);

char *getCpf(Passageiro *passageiro);

char *getTelefone(Passageiro *passageiro);

char *getEmail(Passageiro *passageiro);

char *getTelefoneDeEmergencia(Passageiro *passageiro);

void setNome(Passageiro *passageiro, char nome[50]);

void setCpf(Passageiro *passageiro, char cpf[12]);

void setTelefone(Passageiro *passageiro, char telefone[12]);

void setEmail(Passageiro *passageiro, char email[50]);

void setTelefoneDeEmergencia(Passageiro *passageiro, char telefoneDeEmergencia[12]);

#endif //PROJETORODOVIARIA_PASSAGEIRO_H
