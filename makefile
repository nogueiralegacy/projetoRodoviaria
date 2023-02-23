all: projeto

#Constroi e compila o projeto
projeto:
	gcc -o projeto main.c interface.c
#Apaga o arquivo executavel
clean:
	del projeto.exe

#Executa o projeto
run: projeto
	./projeto

#Testes
test:
	gcc -o test testMain.c TestOnibus.c Onibus.c TestPassageiro.c Passageiro.c TestPassagem.c Passagem.c TestViagem.c Viagem.c
	./test