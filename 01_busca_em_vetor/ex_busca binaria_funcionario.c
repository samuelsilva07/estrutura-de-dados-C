#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct funcionario2 {
    char nome[81];
    float valor_hora;
    int horas_mes;
} FUNCIONARIO;

FUNCIONARIO* busca(int inicio, int tam, FUNCIONARIO** v, char* nome) {
    int meio = (inicio + tam) / 2;
    if (strcmp(v[meio]->nome, nome)) return v[meio];
    for (int i = 0; nome[i] != '\0'; i++) {
        if (v[meio]->nome[i] > nome[i]) return busca(meio, tam, v, nome);
        else if (v[meio]->nome[i] < nome[i]) return busca(inicio, meio, v, nome);
    }
    return NULL;
}

int main (void) {
    FUNCIONARIO funcionarios[10];
    FUNCIONARIO* funcionario =  malloc(sizeof(FUNCIONARIO));
    funcionario = busca(0, 10, funcionario, funcionario->nome);
    return 0;
}