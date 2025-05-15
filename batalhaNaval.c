#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Inicializa todas as posições do tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Verifica se é possível posicionar horizontalmente
bool podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != VALOR_AGUA)
            return false;
    }
    return true;
}

// Verifica se é possível posicionar verticalmente
bool podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != VALOR_AGUA)
            return false;
    }
    return true;
}

// Verifica se é possível posicionar diagonal crescente (↘)
bool podePosicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != VALOR_AGUA)
            return false;
    }
    return true;
}

// Verifica se é possível posicionar diagonal secundária (↙)
bool podePosicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return false;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != VALOR_AGUA)
            return false;
    }
    return true;
}

// Posiciona horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = VALOR_NAVIO;
    }
}

// Posiciona vertical
void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = VALOR_NAVIO;
    }
}

// Posiciona diagonal crescente ↘
void posicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = VALOR_NAVIO;
    }
}

// Posiciona diagonal decrescente ↙
void posicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = VALOR_NAVIO;
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos 4 navios
    int l1 = 1, c1 = 1;  // horizontal
    int l2 = 4, c2 = 6;  // vertical
    int l3 = 0, c3 = 7;  // diagonal ↙
    int l4 = 6, c4 = 1;  // diagonal ↘

    // Posiciona navio horizontal
    if (!podePosicionarHorizontal(tabuleiro, l1, c1)) {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }
    posicionarHorizontal(tabuleiro, l1, c1);

    // Posiciona navio vertical
    if (!podePosicionarVertical(tabuleiro, l2, c2)) {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }
    posicionarVertical(tabuleiro, l2, c2);

    // Posiciona navio diagonal ↙ (secundária)
    if (!podePosicionarDiagonalSecundaria(tabuleiro, l3, c3)) {
        printf("Erro ao posicionar navio diagonal ↙.\n");
        return 1;
    }
    posicionarDiagonalSecundaria(tabuleiro, l3, c3);

    // Posiciona navio diagonal ↘ (principal)
    if (!podePosicionarDiagonalPrincipal(tabuleiro, l4, c4)) {
        printf("Erro ao posicionar navio diagonal ↘.\n");
        return 1;
    }
    posicionarDiagonalPrincipal(tabuleiro, l4, c4);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
