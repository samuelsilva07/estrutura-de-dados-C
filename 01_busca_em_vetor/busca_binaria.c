#include <stdio.h>

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

int main () {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    int resultado = buscaBinaria(10, vetor, n);
    if (resultado != -1)
        printf("Numero encontrado na posicao %d", resultado);
    else
        printf("Numero nao encontrado");
    return 0;
}