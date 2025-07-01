/*
 * Nome: Gustavo de Sousa Zimmermann
 * Matéria: AEDs I
 * Professor: Paulo Bressan
 */

#include "Ordena.h"

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* head, int tamanho) {
    if (head == nullptr || tamanho <= 1) {
        return;
    }
    for (int i = 0; i < tamanho - 1; i++) {
        int* ptr = head;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (*ptr > *(ptr + 1)) {
                troca(ptr, ptr + 1);
            }
            ptr++;
        }
    }
}

void selectionSort(int* head, int tamanho) {
    if (head == nullptr || tamanho <= 1) {
        return;
    }
    int* ptr_i = head;
    for (int i = 0; i < tamanho - 1; i++) {
        int* ponteiroMenor = ptr_i;
        int* ptr_j = ptr_i + 1;

        for (int j = i + 1; j < tamanho; j++) {
            if (*ptr_j < *ponteiroMenor) {
                ponteiroMenor = ptr_j;
            }
            ptr_j++;
        }
        troca(ptr_i, ponteiroMenor);
        ptr_i++;
    }
}

void insertionSort(int* head, int tamanho) {
    if (head == nullptr || tamanho <= 1) {
        return;
    }
    for (int i = 1; i < tamanho; i++) {
        int chave = *(head + i);
        int* ptr = head + i;

        while (ptr > head && *(ptr - 1) > chave) {
            *ptr = *(ptr - 1);
            ptr--;
        }
        *ptr = chave;
    }
}