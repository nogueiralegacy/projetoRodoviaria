all: projeto

#Constroi e compila o projeto
projeto:
	gcc -o projeto main.c Interface.c Onibus.c Passageiro.c Passagem.c Viagem.c

#Apaga o arquivo executavel
clean:
	del projeto.exe

#Executa o projeto
run: projeto
	./projeto

#Testes
test:
	gcc -o test TestMain.c TestOnibus.c Onibus.c TestPassageiro.c Passageiro.c TestPassagem.c Passagem.c TestViagem.c Viagem.c
	./test