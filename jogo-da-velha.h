#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

void inicializar_tabuleiro(char tab[3][3]);
void imprimir_tabuleiro(char tab[3][3]);
int verificar_vencedor(char tab[3][3], char c);
int verificar_empate(char tab[3][3]);
int jogada_valida(char tab[3][3], int l, int c);
void jogada_humano(char tab[3][3], char jogador);
void jogada_computador(char tab[3][3], char jogador);
void executar_jogo(int argc, char *argv[]);

#endif
