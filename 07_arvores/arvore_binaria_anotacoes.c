#include <stdio.h>
#include <stdlib.h>

/* árvores - funçôes baseadas em RECURSÃO! */

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} ARV;

void arvImprime(ARV* arvore) {
    printf("<");
    if(arvore != NULL) {
        printf("%c ", arvore->info);
        arvImprime(arvore->esq);
        arvImprime(arvore->dir);
    }
    printf("> ");
}

int arvPertence(ARV* arvore, int valor) { 
    // retorna valores BOOLEANOS (pertence ou não pertence)
    if (arvore == NULL) return 0;
    else return arvore->info == valor || arvPertence(arvore->esq, valor) || arvPertence(arvore->dir, valor) == valor;
    // recursão para verificação nos ramos 
}

ARV* arvLibera(ARV* arvore) {
    if (arvore != NULL) {
        // recursão para liberar os ramos
        arvLibera(arvore->esq);
        arvLibera(arvore->dir);
        free(arvore);
    }
    return NULL;
}

ARV* arvCria (char valor, ARV* esq, ARV* dir) {
    ARV* no = (ARV*) malloc(sizeof(ARV));
    no->info = valor;
    no->esq = esq;
    no->dir = dir;
    return no;
}

ARV* criaVazia() {
    return NULL;
}

int main () {
    ARV* arvore = criaVazia();
    /* utilização das FUNÇÕES para criar os ramos (TIPO ARV!!!)*/
    arvore = arvCria('a', criaVazia(), criaVazia());
    arvImprime(arvore);
    printf("\n");
    arvore->esq = arvCria('b', criaVazia(), arvCria('d', criaVazia(), criaVazia()));
    arvore->dir = arvCria('c', arvCria('e', criaVazia(), criaVazia()), arvCria('f', criaVazia(), criaVazia()));
    arvImprime(arvore);
    arvLibera(arvore);
    printf("Arvore liberada!\n");
    return 0;
}