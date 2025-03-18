#include <stdio.h>
#include <stdlib.h>

int main() {

    #define matriz_tabuleiro_i 10
    #define matriz_tabuleiro_j 10

    int tabuleiro[matriz_tabuleiro_i][matriz_tabuleiro_j];

    // PRIMEIRO SÍMBOLO - Cruz
    int fila1 = 3;
    int coluna1 = 1;

    // SEGUNDO SÍMBOLO - Losango
    int fila2 = 5;
    int coluna2 = 5;

    // TERCEIRO SÍMBOLO - Cone
    int fila3 = 8;
    int coluna3 = 0;

    // Água [representada pelo número 0 na visualização do tabuleiro]
    for (int i = 0; i < matriz_tabuleiro_i; i++) {
        for (int j = 0; j < matriz_tabuleiro_j; j++) {
            tabuleiro[i][j] = 0;
        }
    }



    // Posicionamento das Figuras

    // **** CRUZ [CÓDIGO 3] ****

    // Detectar Limites do Tabuleiro
    if ((coluna1 + 4 < matriz_tabuleiro_j) && (fila1 - 2 >= 0) && (fila1 + 2 < matriz_tabuleiro_i)) {
        int sobreposicao = 0; // Flag para detectar sobreposição.

        // Checar sobreposição para o braço horizontal (linha fila1 de coluna1 a coluna1+4)
        for (int i = 0; i < 5; i++) {
            if (tabuleiro[fila1][coluna1 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Checar sobreposição para o braço vertical (coluna coluna1+2 de fila1-2 a fila1+2)
        // A célula central já foi verificada no braço horizontal.
        for (int i = -2; i <= 2; i++) {
            if (i == 0)
                continue;
            if (tabuleiro[fila1 + i][coluna1 + 2] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Caso a Cruz não esteja fora dos limites nem haja sobreposição:
        if (!sobreposicao) {

            // Coloca o braço horizontal da Cruz
            for (int i = 0; i < 2; i++) {
            tabuleiro[fila1][coluna1 + i] = 3;

            // Coloca o braço horizontal da Cruz
                for (int k = 0; k < 5; k++) {
                tabuleiro[fila1][coluna1 + k] = 3;

            }

            // Coloca o braço vertical da Cruz (pulando o centro, já marcado)
            for (int k = -2; k <= 2; k++) {
                if (k == 0)
                    continue;
                tabuleiro[fila1 + k][coluna1 + 2] = 3;
            }
        }

        } else {
            // Caso haja sobreposição:
            printf("Sobreposição detectada! Não é possível inserir a Cruz na localização especificada.\n\n");
            printf("Digite algo para encerrar o programa.\n");
            getchar();
            exit(1);
        }
    } else {
        // Caso a Cruz esteja fora dos limites:
        printf("Cruz está fora dos limites do tabuleiro!\n");
        printf("Digite algo para encerrar o programa.\n");
        getchar();
        exit(1);
    }



    // **** LOSANGO [CÓDIGO 2] ****

    // Detectar Limites do Tabuleiro
    if ((coluna2 + 1 < matriz_tabuleiro_j) && (fila2 - 2 >= 0) && (fila2 + 2 < matriz_tabuleiro_i)) {
        int sobreposicao = 0; // Flag para detectar sobreposição.

        // Checar sobreposição para o braço horizontal (linha fila2 de coluna2 a coluna2+4)
        for (int i = 0; i < 5; i++) {
            if (tabuleiro[fila2][coluna2 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Checar sobreposição para o braço vertical (coluna coluna2+2 de fila2-2 a fila2+2)
        // A célula central já foi verificada no braço horizontal.
        for (int i = -2; i <= 2; i++) {
            if (i == 0)
                continue;
            if (tabuleiro[fila2 + i][coluna2 + 2] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Caso o Losango não esteja fora dos limites nem haja sobreposição:
        if (!sobreposicao) {

            // Coloca o braço horizontal do Losango
            for (int a = 0; a < 3; a++) {
                tabuleiro[fila2 + a][coluna2 + a] = 2;

                // Parte inferior do Losango
                for (int b = 0; b < 3; b++) {
                    tabuleiro[fila2 + b - 1][coluna2 + b + 1] = 2;

                    // Parte superior do Losango
                    for (int c = 0; c < 3; c++) {
                        tabuleiro[fila2 + c - 2][coluna2 + c + 2] = 2;          // Reaproveitando o código da Cruz, mas adicionando
                                                                                // os 4 números "2" faltando aos arredores.
            }
            for (int k = 0; k < 5; k++) {
                tabuleiro[fila2][coluna2 + k] = 2;
            }

            // Coloca o braço vertical do Losango (pulando o centro, já marcado)
            for (int k = -2; k <= 2; k++) {
                if (k == 0)
                    continue;
                tabuleiro[fila2 + k][coluna2 + 2] = 2;
            }
        }
    }

// **** CONE [CÓDIGO 1] ****

    // Detectar Limites do Tabuleiro
if ((coluna3 + 4 < matriz_tabuleiro_j) && (fila3 < matriz_tabuleiro_i)) {
    int sobreposicao = 0;
    
    // Checa sobreposição apenas para a base horizontal (que é a maior)
    for (int i = 0; i < 5; i++) {
        if (tabuleiro[fila3][coluna3 + i] != 0) {
            sobreposicao = 1;
            break;
        }
    }
    
    if (!sobreposicao) {

        // Coloca a base do Cone
        for (int a = 0; a < 5; a++) {
            tabuleiro[fila3][coluna3 + a] = 1;

            // Coloca a parte do meio do Cone
            for (int b = 0; b < 3; b++) {
                tabuleiro[fila3 - 1][coluna3 + b + 1] = 1;

                // Coloca o topo do Cone
                for (int c = 0; c < 1; c++) {
                    tabuleiro[fila3 - 2][coluna3 + c + 2] = 1;

        }
    }
}

    } else {
        printf("Sobreposição detectada! Não é possível inserir o Cone na localização especificada.\n\n");
        getchar();
        exit(1);
    }
    } else {
        printf("Cone está fora dos limites do tabuleiro!\n");
        getchar();
        exit(1);
}


    // Tela Inicial
    printf("  TABULEIRO BATALHA NAVAL (Mestre)\n\n");

    // Print Cabeçalho
    printf("    A B C D E F G H I J\n");

    // Print Numeração Vertical e Tabuleiro
    for (int i = 0; i < matriz_tabuleiro_i; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < matriz_tabuleiro_j; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;

}
    }
}
