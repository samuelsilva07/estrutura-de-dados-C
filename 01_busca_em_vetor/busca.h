#include <stdio.h>

int buscaLinear(int tam, int* vet, int n) {
    int i;
    for (i = 0; i < tam; i++) 
        if (vet[i] == n) return i;
    return -1;
}

int buscaBinaria (int tam, int* vet, int n) {
    int meio, inicio = 0, fim = tam;
    while (inicio <= meio) {
        meio = (int) (inicio + fim) / 2;
        if (n > vet[meio]) inicio = meio + 1;
        else if (n < vet[meio]) fim = meio - 1;
        else return meio;
    }
    return -1;
}