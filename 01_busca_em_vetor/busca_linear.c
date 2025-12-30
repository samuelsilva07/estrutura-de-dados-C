#include <stdio.h>

int buscaLinear(int tam, int* vet, int n) {
    int i;
    for (i = 0; i < tam; i++) 
        if (vet[i] == n) return i;
    return -1;
}

int main (void) {
    int vetor[10] = {1, 4, 3, 5, 7, 8, 5, 10, 9, 6};
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    int resultado = buscaLinear(10, vetor, n);
    if (resultado != -1)
        printf("Numero encontrado na posicao %d", resultado);
    else
        printf("Numero nao encontrado");
    return 0;
}