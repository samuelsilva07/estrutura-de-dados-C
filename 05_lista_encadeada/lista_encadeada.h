#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// biblioteca com as funções para a manutenção de listas encadeadas simples

typedef struct lista LISTA;

void listaLibera(LISTA* lista);
void listaImprimeCiclo(LISTA* lista);
int listaVerificaCiclo(LISTA* lista);
LISTA* listaCriarCiclo(LISTA* lista);
int listaPesquisa(LISTA* lista, int num);
LISTA* listaRemove(LISTA* lista, int num);
void listaImprime(LISTA* lista);
LISTA* listaInsereOrdenado(LISTA* lista, int num);
LISTA* listaInsere(LISTA* lista, int num);
LISTA* listaCria();

#endif