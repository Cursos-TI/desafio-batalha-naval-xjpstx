#include <stdio.h>

// declaração das constantes
#define LINHA_TABULEIRO 10
#define COLUNA_TABULEIRO 10
#define LINHA_CONE 5
#define COLUNA_CONE 5
#define LINHA_CRUZ 5
#define COLUNA_CRUZ 5
#define LINHA_OCTAEDRO 5
#define COLUNA_OCTAEDRO 5
#define LINHA_NAVIO 5
#define COLUNA_NAVIO 5

// função para sobrepor o tabuleiro com as matrizes já definidas
void sobreporTabuleiro(int tabuleiro[LINHA_TABULEIRO][COLUNA_TABULEIRO], int figura[LINHA_CONE][COLUNA_CONE], int inicioLinha, int inicioColuna){
    for(int i = 0; i < LINHA_CONE; i++){
        for(int j = 0; j < COLUNA_CONE; j++){
            if (figura[i][j] != 0) {
                tabuleiro[inicioLinha + i][inicioColuna + j] = figura[i][j];
            }
        }
    }
}

// função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[LINHA_TABULEIRO][COLUNA_TABULEIRO]){
    for(int i = 0; i < LINHA_TABULEIRO; i++){
        for(int j = 0; j < COLUNA_TABULEIRO; j++){
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int tabuleiro[LINHA_TABULEIRO][COLUNA_TABULEIRO] = {0}; // matriz tabuleiro 10x10 

    int cone[LINHA_CONE][COLUNA_CONE] = { // matriz cone 5x5
        {0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[LINHA_CRUZ][COLUNA_CRUZ] = { // matriz cruz 5x5
        {0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int octaedro[LINHA_OCTAEDRO][COLUNA_OCTAEDRO] = { // matriz octaedro 5x5
        {0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int navioHorizontal[LINHA_NAVIO][COLUNA_NAVIO] = { // matriz navioHorizontal 5x5 (construída como 3x3)
        {0, 0, 0},
        {3, 3, 3},
        {0, 0, 0}
    };

    int navioVertical[LINHA_NAVIO][COLUNA_NAVIO] = { // matriz navioVertical 5x5 (construída como 3x3)
        {0, 3, 0},
        {0, 3, 0},
        {0, 3, 0}
    };

    int navioDiagonal1[LINHA_NAVIO][COLUNA_NAVIO] = { // matriz navioDiagonal1 5x5 (construída como 3x3)
        {3, 0, 0},
        {0, 3, 0},
        {0, 0, 3}
    };

    int navioDiagonal2[LINHA_NAVIO][COLUNA_NAVIO] = { // matriz navioDiagonal2 5x5 (construída como 3x3)
        {0, 0, 3},
        {0, 3, 0},
        {3, 0, 0}
    };

    // chama as funções void e retorna para sobrepor a matriz tabuleiro através da posição inicial definida para outras matrizes
    sobreporTabuleiro(tabuleiro, cone, 0, 0);
    sobreporTabuleiro(tabuleiro, cruz, 3, 3);
    sobreporTabuleiro(tabuleiro, octaedro, 6, 5);
    sobreporTabuleiro(tabuleiro, navioHorizontal, 3, 1);
    sobreporTabuleiro(tabuleiro, navioVertical, 2, 5);
    sobreporTabuleiro(tabuleiro, navioDiagonal1, 7, 1);
    sobreporTabuleiro(tabuleiro, navioDiagonal2, 0, 7);

    printf("Tabuleiro após a ativação dos poderes\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}