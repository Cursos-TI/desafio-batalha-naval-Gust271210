#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio de tamanho 3 (horizontal, vertical ou diagonal)
int posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;
        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'A') { l += i; c -= i; } // Diagonal anti

        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0)
            return 0; // Inválido ou sobreposto
    }

    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;
        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'A') { l += i; c -= i; }

        tabuleiro[l][c] = NAVIO;
    }
    return 1;
}

// Aplica habilidade centrada em (cx, cy), usando matriz nxn com valores 0 e 1
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[7][7], int cx, int cy, int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (habilidade[i][j] == 1) {
                int x = cx - centro + i;
                int y = cy - centro + j;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM && tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

// Gera matriz de cone (7x7)
void gerarCone(int cone[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            cone[i][j] = (j >= 3 - i && j <= 3 + i && i >= 0) ? 1 : 0;
}

// Gera matriz de cruz (7x7)
void gerarCruz(int cruz[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            cruz[i][j] = (i == 3 || j == 3) ? 1 : 0;
}

// Gera matriz de octaedro (losango 7x7)
void gerarOctaedro(int octaedro[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            octaedro[i][j] = (abs(i - 3) + abs(j - 3) <= 3) ? 1 : 0;
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento de 4 navios
    posicionarNavio(tabuleiro, 1, 1, 'H'); // horizontal
    posicionarNavio(tabuleiro, 4, 0, 'V'); // vertical
    posicionarNavio(tabuleiro, 6, 6, 'D'); // diagonal
    posicionarNavio(tabuleiro, 0, 9, 'A'); // diagonal inversa

    // Matrizes das habilidades
    int cone[7][7], cruz[7][7], octaedro[7][7];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicando habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3, 7);
    aplicarHabilidade(tabuleiro, cruz, 6, 2, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 7, 7);

    // Exibição final
    printf("Tabuleiro com navios e habilidades:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
