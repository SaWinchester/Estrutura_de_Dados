#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

Pilha cria_pilha(){
    Pilha p = (tipo_pilha*) malloc(sizeof(tipo_pilha));
    if(!p) return NULL;

    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

int push(Pilha pilha, tipo_elemento elemento){
    if(!pilha) return -1;

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo));

    if(!no) return 1;

    no->info = elemento;
    no->prox = pilha->topo;
    pilha->topo = no;
    pilha->tamanho++;
    return 0;
}

int pop(Pilha pilha, tipo_elemento *elemento){
    if(!pilha || !pilha->topo) return -1;

    tipo_nodo *no = pilha->topo;
    (*elemento) = no->info;
    pilha->topo = no->prox;
    free(no);
    pilha->tamanho--;
    return 0;
}

int pilha_vazia(Pilha pilha){
    return (!pilha->topo);
}

void termina_pilha(Pilha pilha){
    tipo_nodo *aux;
    while(pilha->topo){
        aux=pilha->topo;
        pilha->topo = aux->prox;
        pilha->tamanho--;
        free(aux);
    }
    free(pilha);
}

void exibe_pilha(Pilha pilha){
    tipo_nodo *aux = pilha->topo;
    printf("\n\n%d\n",pilha->tamanho);
    while(aux){
        printf("\n\t%ld\n",aux->info.chave);
        aux = aux->prox;
    }
}
