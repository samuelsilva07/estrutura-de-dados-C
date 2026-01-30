#include <stdio.h>
#include <stdlib.h>
// #define TAMANHO_INICIAL 0
// typedef int Heap[TAMANHO_INICIAL];

int divInt(int num1, int num2);
void bolha (int* vet, int i);
void heapImprime(int* heap, int tamanho);
void heapRemove(int* heap, int* tamanho);
void heapInsere(int* heap, int* tamanho, int valor);