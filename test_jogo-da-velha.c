#include <stdio.h>
#include <assert.h>
#include "jogo-da-velha.h"

void test_inicializar_tabuleiro() {
    char tab[3][3];
    inicializar_tabuleiro(tab);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            assert(tab[i][j] == ' ');
    printf("[OK] test_inicializar_tabuleiro\n");
}

void test_jogada_valida() {
    char tab[3][3];
    inicializar_tabuleiro(tab);
    assert(jogada_valida(tab, 0, 0) == 1); // Valida
    assert(jogada_valida(tab, 3, 0) == 0); // Fora do limite
    
    tab[0][0] = 'X';
    assert(jogada_valida(tab, 0, 0) == 0); // Ocupada
    printf("[OK] test_jogada_valida\n");
}

void test_verificar_vencedor() {
    char tab[3][3];
    inicializar_tabuleiro(tab);
    
    // Testa linha
    tab[0][0] = 'X'; tab[0][1] = 'X'; tab[0][2] = 'X';
    assert(verificar_vencedor(tab, 'X') == 1);
    assert(verificar_vencedor(tab, 'O') == 0);

    // Testa diagonal
    inicializar_tabuleiro(tab);
    tab[0][0] = 'O'; tab[1][1] = 'O'; tab[2][2] = 'O';
    assert(verificar_vencedor(tab, 'O') == 1);
    
    printf("[OK] test_verificar_vencedor\n");
}

void test_verificar_empate() {
    char tab[3][3] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'O', 'X', 'X'}
    };
    assert(verificar_empate(tab) == 1);

    tab[2][2] = ' '; // Abre uma casa
    assert(verificar_empate(tab) == 0);
    
    printf("[OK] test_verificar_empate\n");
}

int main() {
    printf("Iniciando bateria de testes...\n");
    test_inicializar_tabuleiro();
    test_jogada_valida();
    test_verificar_vencedor();
    test_verificar_empate();
    printf("Todos os testes passaram com sucesso!\n");

    printf("Criado por Luís Guilherme\n");
    return 0;
}
