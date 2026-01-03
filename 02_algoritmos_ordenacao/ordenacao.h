#include <stdio.h>
#include <stdlib.h>

void bubble(int tam, int* vet) {
    int temp, fim = tam - 1, OK = 0;
    do {
        OK = 0; 
        for (int i = 0; i < fim; i++) { 
            if (vet[i] > vet[i + 1]) {
                OK = 1;                   
                temp = vet[i + 1];
                vet[i + 1] = vet[i];
                vet[i] = temp;
            }
        }
        fim--;    
    } while (OK); 
}

void insertion(int tam, int* vet) {
    for (int i = 1; i < tam; i++) { 
        int j = i;  
        while (j > 0 && vet[j - 1] > vet[j]) {
            int temp = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = temp;
            j--;  
        } 
    }
}

void selectionSort(int tam, int* vet) {
    int menor; 
    for (int i = 0; i < tam; i++) {
        menor = i; 
        for (int j = i + 1; j < tam; j++)
            if (vet[j] < vet[menor]) menor = j;
        if (menor != i){
            int temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
        }
    }
}

void quick(int tam, int* vet) {
    if (tam > 1) {
        int pivo = vet[0];
        int a = 1, b = tam - 1;
        do {
            while (a < tam && vet[a] <= pivo) a++;
            while (vet[b] >= pivo) b--;
            if (a < b) {
                int temp = vet[b];
                vet[b] = vet[a];
                vet[a] = temp;
                a++, b--;
            }
        } while (a <= b);
        vet[0] = vet[b];
        vet[b] = pivo;

        quick(b, vet);
        quick(tam - a, &vet[a]);
    }
}

void intercala(int inicio, int meio, int fim, int* vet) {
    int i = inicio, j = meio, k = 0;
    int* vetTemp = (int*) malloc((fim - inicio)*sizeof(int));
    while (i < meio && j < fim) {
        if (vet[i] <= vet[j]) vetTemp[k++] = vet[i++];
        else vetTemp[k++] = vet[j++];
    }
    while (i < meio) vetTemp[k++] = vet[i++];
    while (j < fim) vetTemp[k++] = vet[j++]; 

    for (i = inicio; i < fim; i++) vet[i] = vetTemp[i - inicio];
    free(vetTemp);
}

void merge(int inicio, int tam, int* vet) {
    if (inicio < tam - 1) {
        int meio = (int) ((inicio + tam) / 2);
        merge(inicio, meio, vet);
        merge(meio, tam, vet);
        intercala(inicio, meio, tam, vet);
    }
}