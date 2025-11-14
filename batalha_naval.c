#include <stdio.h>

void inicializarTabuleiro(int tab[10][10])
{
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            tab[i][j] = 0;
}

int podePosicionar(int tab[10][10], int linha[], int coluna[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (tab[linha[i]][coluna[i]] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void posicionarNavio(int tab[10][10], int linha[], int coluna[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        tab[linha[i]][coluna[i]] = 3;
    }
}

int colocarHorizontal(int tab[10][10], int linha, int coluna)
{
    if (coluna + 3 > 10)
        return 0;
    int l[3] = {linha, linha, linha};
    int c[3] = {coluna, coluna + 1, coluna + 2};
    if (!podePosicionar(tab, l, c, 3))
        return 0;
    posicionarNavio(tab, l, c, 3);
    return 1;
}

int colocarVertical(int tab[10][10], int linha, int coluna)
{
    if (linha + 3 > 10)
        return 0; 
    int l[3] = {linha, linha + 1, linha + 2};
    int c[3] = {coluna, coluna, coluna};
    if (!podePosicionar(tab, l, c, 3))
        return 0;
    posicionarNavio(tab, l, c, 3);
    return 1;
}

int colocarDiagonalDescendo(int tab[10][10], int linha, int coluna)
{
    if (linha + 3 > 10 || coluna + 3 > 10)
        return 0;
    int l[3] = {linha, linha + 1, linha + 2};
    int c[3] = {coluna, coluna + 1, coluna + 2};
    if (!podePosicionar(tab, l, c, 3))
        return 0;
    posicionarNavio(tab, l, c, 3);
    return 1;
}

int colocarDiagonalSubindo(int tab[10][10], int linha, int coluna)
{
    if (linha - 2 < 0 || coluna + 3 > 10)
        return 0;
    int l[3] = {linha, linha - 1, linha - 2};
    int c[3] = {coluna, coluna + 1, coluna + 2};
    if (!podePosicionar(tab, l, c, 3))
        return 0;
    posicionarNavio(tab, l, c, 3);
    return 1;
}

void imprimirTabuleiro(int tab[10][10])
{
    int i, j;
    printf("\n=== TABULEIRO (0=agua, 3=navio, 5=habilidade) ===\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void construirCone(int mat[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            mat[i][j] = 0;

    mat[0][2] = 1;

    mat[1][1] = 1;
    mat[1][2] = 1;
    mat[1][3] = 1;

    for (j = 0; j < 5; j++)
        mat[2][j] = 1;
}

void construirCruz(int mat[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            mat[i][j] = 0;

    for (j = 0; j < 5; j++)
        mat[2][j] = 1;

    for (i = 0; i < 5; i++)
        mat[i][2] = 1;
}

void construirOctaedro(int mat[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            mat[i][j] = 0;

    mat[0][2] = 1;

    mat[1][1] = 1;
    mat[1][2] = 1;
    mat[1][3] = 1;

    for (j = 0; j < 5; j++)
        mat[2][j] = 1;

    mat[3][1] = 1;
    mat[3][2] = 1;
    mat[3][3] = 1;

    mat[4][2] = 1;
}

void aplicarHabilidade(int tab[10][10], int skill[5][5], int skillSize,
                       int origemLinha, int origemColuna, int marca)
{
    int meio = skillSize / 2; 
    int si, sj;
    for (si = 0; si < skillSize; si++)
    {
        for (sj = 0; sj < skillSize; sj++)
        {
            if (skill[si][sj] == 1)
            {
                int linhaTab = origemLinha + (si - meio);
                int colTab = origemColuna + (sj - meio);

                if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10)
                {
                    tab[linhaTab][colTab] = marca;
                }
            }
        }
    }
}

void imprimirMatriz5(int mat[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int tabuleiro[10][10];

    inicializarTabuleiro(tabuleiro);

    if (!colocarHorizontal(tabuleiro, 2, 4))
    {
        printf("Falha ao posicionar navio horizontal!\n");
    }
    if (!colocarVertical(tabuleiro, 5, 1))
    {
        printf("Falha ao posicionar navio vertical!\n");
    }
    if (!colocarDiagonalDescendo(tabuleiro, 0, 0))
    {
        printf("Falha ao posicionar navio diagonal descendo!\n");
    }
    if (!colocarDiagonalSubindo(tabuleiro, 9, 3))
    {
        printf("Falha ao posicionar navio diagonal subindo!\n");
    }

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    printf("\nMatriz - Cone (5x5):\n");
    imprimirMatriz5(cone);
    printf("\nMatriz - Cruz (5x5):\n");
    imprimirMatriz5(cruz);
    printf("\nMatriz - Octaedro (5x5):\n");
    imprimirMatriz5(octaedro);

    int origemConeLinha = 1, origemConeColuna = 2; 
    int origemCruzLinha = 4, origemCruzColuna = 6;
    int origemOctLinha = 7, origemOctColuna = 5;   

    int marcaHabilidade = 5;

    aplicarHabilidade(tabuleiro, cone, 5, origemConeLinha, origemConeColuna, marcaHabilidade);
    aplicarHabilidade(tabuleiro, cruz, 5, origemCruzLinha, origemCruzColuna, marcaHabilidade);
    aplicarHabilidade(tabuleiro, octaedro, 5, origemOctLinha, origemOctColuna, marcaHabilidade);

    imprimirTabuleiro(tabuleiro);

    return 0;
}
