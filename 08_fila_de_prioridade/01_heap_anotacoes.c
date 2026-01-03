#include <stdio.h>
#include <stdlib.h>

static int divisaoInteira(int num1, int num2) {
    return (int) (num1 / num2);
}

void heapImprime(int* heap, int tamanho) {
    printf("\nHeap atual: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d, ", heap[i]);
    }
    printf("\b\b]\n");
}

void heapRemove(int* heap, int* tamanho) {
    // remoção do primeiro elemento (possui o maior índice)
    int ultimo = (*tamanho) - 1;
    int valor = heap[ultimo]; // valor do último elemento da heap
    int k = 1; // começa no topo da heap (elemento que será removido)

    // enquanto não chegar no final da heap e o último elemento for menor que os filhos, ocorre a troca de valores
    while (2*k <= ultimo && (valor > heap[2*k] || valor > heap[2*k + 1])) {
        // inserção do lado esquerdo
        if (heap[2*k] > heap[2*k + 1]) {
            heap[k] = heap[2*k];
            k = 2*k;
        }
        // inserção do lado direito
        else {
            heap[k] = heap[2*k + 1];
            k = 2*k + 1;
        }
    }
    heap[k] = valor; // elemento é realocado na posição correta
    (*tamanho)--;
}

void heapInsere(int* heap, int* tamanho, int valor) {
    int k = (*tamanho) ; // k recebe o índice do sucessor do último elemento (que é o tamanho atual da heap)
    // se o elemento for maior do que seu pai (índice k%2), troca os elementos até encontrar a posição correta para o novo elemento
    while (divisaoInteira(k, 2) && (valor < heap[divisaoInteira(k, 2)])) {
        heap[k] = heap[divisaoInteira(k, 2)];
        k = divisaoInteira(k, 2);
    }
    heap[k] = valor; // elemento é inserido na posição correta
    (*tamanho)++;
}

int main () {
    int heap[] = {0};
    int tamanho = 0;
    heapInsere(heap, &tamanho, 1);
    heapInsere(heap, &tamanho, 5);
    heapInsere(heap, &tamanho, 4);

    heapImprime(heap, tamanho);

    heapInsere(heap, &tamanho, 8);
    heapInsere(heap, &tamanho, 3);
    heapInsere(heap, &tamanho, 7);

    heapImprime(heap, tamanho);

    heapRemove(heap, &tamanho);
    heapRemove(heap, &tamanho);

    heapImprime(heap, tamanho);
    exit(EXIT_SUCCESS);
}