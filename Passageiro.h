#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJETORODOVIARIA_PASSAGEIRO_H
#define PROJETORODOVIARIA_PASSAGEIRO_H

 typedef struct passageiro Passageiro;

/**
 * Construtor com todos os atributos de passageiro
 *
 * @param nome Nome do Passageiro
 * @param cpf CPF do passageiro
 * @param telefone Telefone do passageiro
 * @param email Email do passageiro
 * @param telefoneDeEmergencia Telefone de emergência do passageiro
 *
 * @return O endereço de moméria do passageiro criado
 */
struct passageiro *iniciaPassageiro(char nome[50], char cpf[15], char telefone[15], char email[50], char telefoneDeEmergencia[15]);

/**
 * Construtor vazio, retorna um endereço (instância) de Passageiro
 * com todos os campos vazios.
 *
 * @return Instância de Passageiro
 */
struct passageiro *criaPassageiro();

void liberaPassageiro(Passageiro *passageiro);

char *getNome(Passageiro *passageiro);

char *getCpf(Passageiro *passageiro);

char *getTelefone(Passageiro *passageiro);

char *getEmail(Passageiro *passageiro);

char *getTelefoneDeEmergencia(Passageiro *passageiro);

void setNome(Passageiro *passageiro, char nome[50]);

void setCpf(Passageiro *passageiro, char cpf[15]);

void setTelefone(Passageiro *passageiro, char telefone[15]);

void setEmail(Passageiro *passageiro, char email[50]);

void setTelefoneDeEmergencia(Passageiro *passageiro, char telefoneDeEmergencia[15]);

void salvaPassageiro(Passageiro *passageiro, char *nomeArquivo);

void recuperaPassageiro(Passageiro *passageiro, char *nomeArquivo, char *cpf);

void removerPassageiro(char *nomeDoArquivo , char *cpf);

#endif //PROJETORODOVIARIA_PASSAGEIRO_H
