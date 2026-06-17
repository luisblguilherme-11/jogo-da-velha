all: compilar_jogo compilar_testes

compilar_jogo:
	gcc -o jogo-da-velha jogo-da-velha.c functions_jogo-da-velha.c

compilar_testes:
	gcc -o testes test_jogo-da-velha.c functions_jogo-da-velha.c

run_jogo: compilar_jogo
	./jogo-da-velha

run_auto: compilar_jogo
	./jogo-da-velha X auto

run_testes: compilar_testes
	./testes

clean:
	rm -f jogo-da-velha testes
