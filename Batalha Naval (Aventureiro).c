// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

#include <stdio.h>
#include <stdlib.h>

int main() {

    #define matriz_tabuleiro_i 10
    #define matriz_tabuleiro_j 10

    int tabuleiro[matriz_tabuleiro_i][matriz_tabuleiro_j];

    // PRIMEIRO NAVIO (Horizontal) - COORDENADAS [fila = 'i' (ou 'x'); coluna = 'j' (ou 'y')]
    int fila1 = 2;
    int coluna1 = 3;

    // SEGUNDO NAVIO (Vertical) - COORDENADAS [fila = 'i' (ou 'x'); coluna = 'j' (ou 'y')]
    int fila2 = 5;
    int coluna2 = 7;

    // TERCEIRO NAVIO (Diagonal) - COORDENADAS [fila = 'i' (ou 'x'); coluna = 'j' (ou 'y')]
    int fila3 = 4;
    int coluna3 = 2;

    // QUARTO NAVIO (Diagonal) - COORDENADAS [fila = 'i' (ou 'x'); coluna = 'j' (ou 'y')]
    int fila4 = 7;
    int coluna4 = 1;


    // Água [representada pelo número 0 na visualização do tabuleiro]
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }



    // Posicionamento dos Navios

    // **** NAVIO 1 [HORIZONTAL] ****
    if (coluna1 + 2 < 10) { // Visto que o navio tem tamanho 3, "fila2 + 2" tem que ser menos que 10.
        int sobreposicao = 0; // Flag pra detectar sobreposicao.

        // Checar por Sobreposição Entre Navios
        for (int i = 0; i < 3; i++) {
            int col = coluna1 + i;
            if (tabuleiro[fila1][col] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // 1. CASO O NAVIO 1 NÃO ESTEJA FORA DOS LIMITES E NEM HAJA SOBREPOSIÇÃO:

        // Coloca o Navio 1 Horizontal
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                int col = coluna1 + i;
                tabuleiro[fila1][col] = 3;
            }
        } else {
            // A. CASO HAJA SOBREPOSIÇÃO:
            printf("Sobreposição detectada! Não é possível inserir o Navio 1 na localização especificada.\n\n");
            printf("Digite algo para encerrar o programa.\n");
            getchar(); // Espera por caractere
            exit(1); // Força o prompt a encerrar após o caractere for digitado
        }
    } else {
        // B. CASO O NAVIO 1 ESTEJA FORA DOS LIMITES:
        printf("Navio 1 está fora dos limites do tabuleiro!\n");
        printf("Digite algo para encerrar o programa.\n");
        getchar(); // Espera por caractere
        exit(1); // Força o prompt a encerrar após o caractere for digitado
    }



    // **** NAVIO 2 [VERTICAL] ****

    // Detectar Limites do Tabuleiro
    if (fila2 + 2 < 10) { // Visto que o navio tem tamanho 3, "fila2 + 2" tem que ser menos que 10.
        int sobreposicao = 0; // Flag pra detectar sobreposição.

        // Checar por Sobreposição Entre Navios
        for (int i = 0; i < 3; i++) {
            int linha2 = fila2 + i;
            if (tabuleiro[linha2][coluna2] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // 1. CASO O NAVIO 2 NÃO ESTEJA FORA DOS LIMITES E NEM HAJA SOBREPOSIÇÃO:

        // Coloca o Navio 2 Vertical
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                int linha = fila2 + i;
                tabuleiro[linha][coluna2] = 3;
            }
        } else {
            // A. CASO HAJA SOBREPOSIÇÃO:
            printf("Sobreposição detectada! Não é possível inserir o Navio 2 na localização especificada.\n\n");
            printf("Digite algo para encerrar o programa.\n");
            getchar(); // Espera por caractere
            exit(1); // Força o prompt a encerrar após o caractere for digitado
        }
    } else {
        // B. CASO O NAVIO 2 ESTEJA FORA DOS LIMITES:
        printf("Navio 2 está fora dos limites do tabuleiro!\n");
        printf("Digite algo para encerrar o programa.\n");
        getchar(); // Espera por caractere
        exit(1); // Força o prompt a encerrar após o caractere for digitado
    }



    // **** NAVIO 3 [DIAGONAL] ****

    // Detectar Limites do Tabuleiro
    if (fila3 + 2 < 10 && coluna3 + 2 < 10) { // Visto que o navio tem tamanho 3, ambos "fila3 + 2" e "coluna3 + 2" têm que ser menos que 10.
                                              // No Navio Diagonal, deve-se também checar a coluna (coluna3).

        int sobreposicao = 0; // Flag pra detectar sobreposição.

        // Checar por Sobreposição Entre Navios
        for (int i = 0; i < 3; i++) {
            int linha3 = fila3 + i;
            int coluna = coluna3 + i;
            if (tabuleiro[linha3][coluna] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // 1. CASO O NAVIO 3 NÃO ESTEJA FORA DOS LIMITES E NEM HAJA SOBREPOSIÇÃO:

        // Coloca o Navio 3 Diagonal
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                int linha = fila3 + i;
                int coluna = coluna3 + i;
                tabuleiro[linha][coluna] = 3;
            }
        } else {
            // A. CASO HAJA SOBREPOSIÇÃO:
            printf("Sobreposição detectada! Não é possível inserir o Navio 3 na localização especificada.\n\n");
            printf("Digite algo para encerrar o programa.\n");
            getchar(); // Espera por caractere
            exit(1); // Força o prompt a encerrar após o caractere for digitado
        }

    } else {
        // B. CASO O NAVIO 3 ESTEJA FORA DOS LIMITES:
        printf("Navio 3 está fora dos limites do tabuleiro!\n");
        printf("Digite algo para encerrar o programa.\n");
        getchar(); // Espera por caractere
        exit(1); // Força o prompt a encerrar após o caractere for digitado
    }
	

    
	    // **** NAVIO 4 [DIAGONAL] ****

    // Detectar Limites do Tabuleiro
    if (fila4 + 2 < 10 && coluna4 + 2 < 10) { // Visto que o navio tem tamanho 3, ambos "fila3 + 2" e "coluna3 + 2" têm que ser menos que 10.
                                              // No Navio Diagonal, deve-se também checar a coluna (coluna4).

        int sobreposicao = 0; // Flag pra detectar sobreposição.

        // Checar por Sobreposição Entre Navios
        for (int i = 0; i < 3; i++) {
            int linha4 = fila4 + i;
            int coluna = coluna4 + i;
            if (tabuleiro[linha4][coluna] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // 1. CASO O NAVIO 4 NÃO ESTEJA FORA DOS LIMITES E NEM HAJA SOBREPOSIÇÃO:

        // Coloca o Navio 3 Diagonal
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                int linha = fila4 + i;
                int coluna = coluna4 + i;
                tabuleiro[linha][coluna] = 3;
            }
        } else {
            // A. CASO HAJA SOBREPOSIÇÃO:
            printf("Sobreposição detectada! Não é possível inserir o Navio 4 na localização especificada.\n\n");
            printf("Digite algo para encerrar o programa.\n");
            getchar(); // Espera por caractere
            exit(1); // Força o prompt a encerrar após o caractere for digitado
        }

    } else {
        // B. CASO O NAVIO 4 ESTEJA FORA DOS LIMITES:
        printf("Navio 4 está fora dos limites do tabuleiro!\n");
        printf("Digite algo para encerrar o programa.\n");
        getchar(); // Espera por caractere
        exit(1); // Força o prompt a encerrar após o caractere for digitado
		}
	


    // Tela Inicial
    printf("  TABULEIRO BATALHA NAVAL (Aventureiro)\n");
    printf("  Aventureiro: Mesmo que Novato, porem com Navios 3 e 4 adicionados.\n\n");

    // Print Cabeçalho
    printf("    A B C D E F G H I J\n");

    // Print Numeração Vertical e Tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
    
}
