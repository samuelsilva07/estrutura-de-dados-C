#include <stdio.h>
#define TAM 10
#define NAOENCONTRADO -1

int buscaBinaria (int n, int* vet, int inicio, int fim) {  
    int meio = ((int) (inicio + fim) / 2);
    printf("\nInicio = %d | Meio = %d | Fim = %d\n", inicio + 1, meio + 1, fim + 1);
    if (inicio > fim) return NAOENCONTRADO;
    else { 
        if (n == vet[meio]) return meio;
        if (n > vet[meio]) return buscaBinaria(n, vet, meio + 1, fim);
        if (n < vet[meio]) return buscaBinaria(n, vet, inicio, meio - 1);
        /* não há necessidade de elses (função é recursiva) - programa levemente mais rápido */
    }
}

int main () {
    int vetor[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    int resultado = buscaBinaria(n, vetor, 0, 10 - 1);
    if (resultado != NAOENCONTRADO)
        printf("Numero encontrado na posicao %d", resultado);
    else
        printf("Numero nao encontrado");
    return 0;
}