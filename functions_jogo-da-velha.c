#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo-da-velha.h"

void inicializar_tabuleiro(char tab[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            tab[i][j] = ' ';
}

void imprimir_tabuleiro(char tab[3][3]) {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", tab[i][0], tab[i][1], tab[i][2]);
    }
    printf("\n");
}

int verificar_vencedor(char tab[3][3], char c) {
    // Linhas e Colunas
    for(int i = 0; i < 3; i++) {
        if(tab[i][0] == c && tab[i][1] == c && tab[i][2] == c) return 1;
        if(tab[0][i] == c && tab[1][i] == c && tab[2][i] == c) return 1;
    }
    // Diagonais
    if(tab[0][0] == c && tab[1][1] == c && tab[2][2] == c) return 1;
    if(tab[0][2] == c && tab[1][1] == c && tab[2][0] == c) return 1;
    
    return 0;
}

int verificar_empate(char tab[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(tab[i][j] == ' ') return 0;
    return 1; // Todas as casas preenchidas
}

int jogada_valida(char tab[3][3], int l, int c) {
    if(l < 0 || l > 2 || c < 0 || c > 2) return 0; // Fora do tabuleiro
    if(tab[l][c] != ' ') return 0; // Casa já ocupada
    return 1;
}

void jogada_humano(char tab[3][3], char jogador) {
    int l, c;
    do {
        printf("Sua vez (Jogador %c). Digite linha e coluna (1 a 3): ", jogador);
        scanf("%d %d", &l, &c);
        l--; c--; // Ajusta para índice 0-2 da matriz
        
        if(!jogada_valida(tab, l, c)) {
            printf("Jogada invalida! Tente novamente.\n");
        }
    } while(!jogada_valida(tab, l, c));
    
    tab[l][c] = jogador;
}

void jogada_computador(char tab[3][3], char jogador) {
    int l, c;
    do {
        l = rand() % 3;
        c = rand() % 3;
    } while(!jogada_valida(tab, l, c));
    
    printf("Computador (%c) jogou na linha %d, coluna %d\n", jogador, l + 1, c + 1);
    tab[l][c] = jogador;
}

void executar_jogo(int argc, char *argv[]) {
    char tab[3][3];
    char jogador1, jogador2;
    int modo_auto = 0;

    srand(time(NULL));
    inicializar_tabuleiro(tab);

    // Definição do jogador 1
    if (argc > 1) {
        jogador1 = argv[1][0];
    } else {
        printf("Escolha seu caractere (X ou O): ");
        scanf(" %c", &jogador1);
    }
    
    // Converte para maiúsculo caso o usuário digite minúsculo
    if (jogador1 == 'x') jogador1 = 'X';
    if (jogador1 == 'o') jogador1 = 'O';

    jogador2 = (jogador1 == 'X') ? 'O' : 'X';

    // Verificação do modo auto
    if (argc > 2 && strcmp(argv[2], "auto") == 0) {
        modo_auto = 1;
    }

    int turno = 1; // 1 para jogador1, 2 para jogador2
    int jogo_ativo = 1;

    imprimir_tabuleiro(tab);

    while (jogo_ativo) {
        if (turno == 1) {
            if (modo_auto) {
                jogada_computador(tab, jogador1);
            } else {
                jogada_humano(tab, jogador1);
            }
            imprimir_tabuleiro(tab);
            if (verificar_vencedor(tab, jogador1)) {
                printf("O jogador 1 ganhou\n");
                jogo_ativo = 0;
                break;
            }
            turno = 2; // Passa a vez
        } else {
            jogada_computador(tab, jogador2);
            imprimir_tabuleiro(tab);
            if (verificar_vencedor(tab, jogador2)) {
                printf("O jogador 2 ganhou\n");
                jogo_ativo = 0;
                break;
            }
            turno = 1; // Passa a vez
        }

        if (verificar_empate(tab)) {
            printf("O jogo terminou sem vencedores\n");
            jogo_ativo = 0;
            break;
        }
    }
}
