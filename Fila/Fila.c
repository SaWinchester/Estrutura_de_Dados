#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

Fila cria_fila(){
    Fila f = (tipo_fila*) malloc(sizeof(tipo_fila));

    if(!f) return NULL;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;

    return f;
}

int enfileirar(Fila fila, tipo_elemento elemento){
    if(!fila) return -1;

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo));

    if(!no) return 1;

    no->prox = NULL;
    no->info = elemento;

    if(!fila->inicio){
        fila->inicio = no;
        fila->fim = no;
    }else{
        fila->fim->prox = no;
        fila->fim = no;
    }
    fila->tamanho++;

    return 0;
}

int desenfileirar(Fila fila, tipo_elemento *elemento){
    if(!fila || !fila->inicio) return -1;

    tipo_nodo *aux = fila->inicio;

    (*elemento) = aux->info;

    fila->inicio = aux->prox;

    free(aux);

    fila->tamanho--;
    return 0;
}

int fila_vazia(Fila fila){
    return (!fila->inicio);
}

void destroi_fila(Fila fila){
    tipo_nodo *aux;
    while(fila->inicio){
        aux = fila->inicio;
        fila->inicio = aux->prox;
        fila->tamanho = 0;
        free(aux);
    }
    free(fila);
}

void exibe_fila(Fila fila){
    tipo_nodo *aux = fila->inicio;
    printf("\n\n%d\n",fila->tamanho);
    while(aux){
        printf("\n\t%ld\n",aux->info.chave);
        aux = aux->prox;
    }
}
