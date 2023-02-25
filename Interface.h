#ifndef PROJETORODOVIARIA_INTERFACE_H
#define PROJETORODOVIARIA_INTERFACE_H

#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"

#define ANSI_COLOR_BLACK_BACK "\x1b[40m"
#define ANSI_COLOR_RED_BACK "\x1b[41m"
#define ANSI_COLOR_GREEN_BACK "\x1b[42m"
#define ANSI_COLOR_YELLOW_BACK "\x1b[43m"
#define ANSI_COLOR_BLUE_BACK "\x1b[44m"
#define ANSI_COLOR_MAGENTA_BACK "\x1b[45m"
#define ANSI_CYAN_BLUE_BACK "\x1b[46m"
#define ANSI_COLOR_WHITE_BACK "\x1b[47m"

#include "Onibus.h"
#include "Passageiro.h"
#include "Passagem.h"
#include "Viagem.h"

void iniciaInterface(int isWindows);

void finalizaInterface(int isWindows);

void interfaceCompanhia(int isWindows);

void imprimeLateral(int isWindows);

void viagensDisponiveis(Viagem *viagem);

void iniciaMenu(int isWindows);

void finalizaMenu(int isWindows);

void menu(int isWindows);

Passageiro *comprarPassagem();

void recadoAcentos();

void imprimeLegenda(int isWindows);

void exibirAcentos(Onibus *onibus, int isWindows);

void exibirPassagemComprada(Viagem *viagem);

void passagemCompradaComSucesso();

void passagemCancelada();

void pausa(int isWindows);

void calculaTotal(Viagem *viagem);

#endif /* PROJETORODOVIARIA_INTERFACE_H */
