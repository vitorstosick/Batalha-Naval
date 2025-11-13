#include <stdio.h>

void inicializarTabuleiro(int tab[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tab[i][j] = 0;
        }
    }
}

int podePosicionar(int tab[10][10], int linha[], int coluna[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (tab[linha[i]][coluna[i]] != 0) {
            return 0; 
        }
    }
    return 1;
}

void posicionarNavio(int tab[10][10], int linha[], int coluna[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        tab[linha[i]][coluna[i]] = 3;
    }
}

void imprimirTabuleiro(int tab[10][10]) {
    int i, j;
    printf("\n=== TABULEIRO ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int colocarHorizontal(int tab[10][10], int linha, int coluna) {
    if (coluna + 3 > 10) return 0;

    int l[3] = { linha, linha, linha };
    int c[3] = { coluna, coluna + 1, coluna + 2 };

    if (!podePosicionar(tab, l, c, 3)) return 0;

    posicionarNavio(tab, l, c, 3);
    return 1;
}

int colocarVertical(int tab[10][10], int linha, int coluna) {
    if (linha + 3 > 10) return 0;

    int l[3] = { linha, linha + 1, linha + 2 };
    int c[3] = { coluna, coluna, coluna };

    if (!podePosicionar(tab, l, c, 3)) return 0;

    posicionarNavio(tab, l, c, 3);
    return 1;
}

int colocarDiagonalDescendo(int tab[10][10], int linha, int coluna) {
    if (linha + 3 > 10 || coluna + 3 > 10) return 0;

    int l[3] = { linha, linha + 1, linha + 2 };
    int c[3] = { coluna, coluna + 1, coluna + 2 };

    if (!podePosicionar(tab, l, c, 3)) return 0;

    posicionarNavio(tab, l, c, 3);
    return 1;
}

int colocarDiagonalSubindo(int tab[10][10], int linha, int coluna) {
    if (linha - 2 < 0 || coluna + 3 > 10) return 0;

    int l[3] = { linha, linha - 1, linha - 2 };
    int c[3] = { coluna, coluna + 1, coluna + 2 };

    if (!podePosicionar(tab, l, c, 3)) return 0;

    posicionarNavio(tab, l, c, 3);
    return 1;
}

int main() {
    int tabuleiro[10][10];
    inicializarTabuleiro(tabuleiro);

    if (!colocarHorizontal(tabuleiro, 2, 4))
        printf("Falha ao posicionar navio horizontal!\n");

    if (!colocarVertical(tabuleiro, 5, 1))
        printf("Falha ao posicionar navio vertical!\n");

    if (!colocarDiagonalDescendo(tabuleiro, 0, 0))
        printf("Falha ao posicionar navio diagonal descendo!\n");

    if (!colocarDiagonalSubindo(tabuleiro, 9, 3))
        printf("Falha ao posicionar navio diagonal subindo!\n");

    imprimirTabuleiro(tabuleiro);

    return 0;
}
