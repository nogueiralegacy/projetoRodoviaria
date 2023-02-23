#ifndef PROJETORODOVIARIA_INTERFACE_H
#define PROJETORODOVIARIA_INTERFACE_H

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void iniciaInterface(int isWindows);

void finalizaInterface(int isWindows);

void interfaceCompanhia(int isWindows);

void imprimeLateral(int isWindows);

void viagensDisponiveis();

void iniciaMenu(int isWindows);

void finalizaMenu(int isWindows);

void menu(int isWindows);

void recadoAcentos();

void imprimeLegenda(int isWindows);

void exibirAcentos(int isWindows);

void exibirPassagemComprada();

void passagemComprada();

void passagemReservada();

void pausa(int isWindows);

#endif /* PROJETORODOVIARIA_INTERFACE_H */
