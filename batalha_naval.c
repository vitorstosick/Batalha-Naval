#include <stdio.h>

void inicializarTabuleiro(int tab[10][10])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tab[i][j] = 0;
        }
    }
}

int posicionarHorizontal(int tab[10][10], int linha, int coluna)
{
    if (coluna + 3 > 10)
    {
        return 0;
    }

    int i;
    for (i = 0; i < 3; i++)
    {
        tab[linha][coluna + i] = 3;
    }

    return 1;
}

int posicionarVertical(int tab[10][10], int linha, int coluna)
{
    if (linha + 3 > 10)
    {
        return 0;
    }

    int i;
    for (i = 0; i < 3; i++)
    {
        tab[linha + i][coluna] = 3;
    }

    return 1;
}

void imprimirTabuleiro(int tab[10][10])
{
    int i, j;
    printf("\n=== TABULEIRO ===\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int tabuleiro[10][10];

    inicializarTabuleiro(tabuleiro);

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    if (!posicionarHorizontal(tabuleiro, linhaH, colunaH))
    {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    if (!posicionarVertical(tabuleiro, linhaV, colunaV))
    {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    imprimirTabuleiro(tabuleiro);

    return 0;
}
