#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_INICIAL 0
typedef int Heap[TAMANHO_INICIAL];

static int divisaoInteira(int num1, int num2) {
    return (int) num1 / num2;
}

void heapImprime(int* heap, int tamanho) {
    printf("\nHeap atual: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d, ", heap[i]);
    }
    printf("\b\b]\n");
}

void heapRemove(int* heap, int* tamanho) {
    int ultimo = (*tamanho) - 1;
    int valor = heap[ultimo];
    int k = 0; 
    while (2*k <= ultimo - 1 && (valor > heap[2*k] || valor > heap[2*k + 1])) {
        if (heap[2*k] < heap[2*k + 1]) {
            heap[k] = heap[2*k];
            k = 2*k;
        }
        else {
            heap[k] = heap[2*k + 1];
            k = 2*k + 1;
        }
    }
    heap[k] = valor; 
    (*tamanho)--;
}

void heapInsere(int* heap, int* tamanho, int valor) {
    int k = (*tamanho);
    while (divisaoInteira(k, 2) && valor < heap[divisaoInteira(k, 2)]) {
        heap[k] = heap[divisaoInteira(k, 2)];
        k = divisaoInteira(k, 2);
    }
    heap[k] = valor; 
    (*tamanho)++;
}
