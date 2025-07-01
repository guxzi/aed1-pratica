/******************************************************************************
 * DISCIPLINA: Algoritmos e Estruturas de Dados I
 * AUTOR: Gustavo de Sousa Zimmermann
 *****************************************************************************/

#include "matrizes.h"

void multiplicar_matriz(Vetor matriz, int escalar) {
    // Ponteiro para o primeiro elemento da matriz (matriz[0][0])
    int *ptr = *matriz;

    // Itera por todos os TAM * TAM elementos da matriz de forma linear
    for (int i = 0; i < TAM * TAM; i++) {
        *ptr *= escalar; // Multiplica o valor apontado pelo escalar
        ptr++;           // Avança o ponteiro para o próximo elemento
    }
}

void transposta_matriz(Vetor resultado, const Vetor origem) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            *( *(resultado + j*TAM) + i ) = *( *(origem + i*TAM) + j );
        }
    }
}

void inverter_colunas_matriz(Vetor matriz) {
    for (int i = 0; i < TAM; i++) {
        // Itera somente até a metade das colunas, pois as trocas são simétricas
        for (int j = 0; j < TAM / 2; j++) {
            // Ponteiro para o elemento da esquerda (na coluna j)
            int *ptr_esquerda = *(matriz + i) + j;

            // Ponteiro para o elemento da direita (na coluna simétrica TAM - 1 - j)
            int *ptr_direita = *(matriz + i) + (TAM - 1 - j);

            // Realiza a troca (swap) dos valores
            int temp = *ptr_esquerda;
            *ptr_esquerda = *ptr_direita;
            *ptr_direita = temp;
        }
    }
}

void inverter_linhas_matriz(Vetor matriz) {
    for (int i = 0; i < TAM / 2; i++) {
        // Ponteiro para o início da linha de cima (linha i)
        int *ptr_linha_cima = *(matriz + i);

        // Ponteiro para o início da linha de baixo (linha simétrica TAM - 1 - i)
        int *ptr_linha_baixo = *(matriz + (TAM - 1 - i));

        // Itera por cada um dos TAM elementos (colunas) da linha para fazer a troca
        for (int j = 0; j < TAM; j++) {
            // Realiza a troca (swap) dos elementos correspondentes de cada linha
            int temp = *(ptr_linha_cima + j);
            *(ptr_linha_cima + j) = *(ptr_linha_baixo + j);
            *(ptr_linha_baixo + j) = temp;
        }
    }
}