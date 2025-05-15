#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se é possível posicionar um navio horizontalmente
bool podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != VALOR_AGUA)
            return false;
    }
    return true;
}

// Função para posicionar o navio horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = VALOR_NAVIO;
    }
}

// Função para verificar se é possível posicionar um navio verticalmente
bool podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != VALOR_AGUA)
            return false;
    }
    return true;
}

// Função para posicionar o navio vertical
void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = VALOR_NAVIO;
    }
}

// Função para exibir o tabuleiro
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

    // Coordenadas dos navios (linha, coluna)
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 7;

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Verifica e posiciona o navio horizontal
    if (!podePosicionarHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Erro: não é possível posicionar o navio horizontal na posição (%d, %d).\n",
               linhaHorizontal, colunaHorizontal);
        return 1;
    }
    posicionarHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);

    // Verifica e posiciona o navio vertical
    if (!podePosicionarVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Erro: não é possível posicionar o navio vertical na posição (%d, %d).\n",
               linhaVertical, colunaVertical);
        return 1;
    }
    posicionarVertical(tabuleiro, linhaVertical, colunaVertical);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
