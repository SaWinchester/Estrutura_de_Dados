#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

Lista cria_lista(){
    Lista l = (tipo_lista*) malloc(sizeof(tipo_lista));

    if(!l) return NULL;

    l->inicio = NULL;
    l->tamanho = 0;

    return l;
}

int insere_lista_inicio(Lista lista, tipo_elemento elemento){
    if(!lista) return -1;

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo));

    if(!no) return 1;

    no->ant = NULL;
    no->prox = NULL;
    no->info = elemento;

    if(!lista->inicio) lista->inicio = no;
    else{
        no->prox = lista->inicio;
        lista->inicio->ant = no;
        lista->inicio = no;
    }
    lista->tamanho++;
    return 0;
}

int insere_lista_fim(Lista lista, tipo_elemento elemento){
    if(!lista) return -1;

    if(!lista->inicio) return insere_lista_inicio(lista,elemento);

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo)),
    *aux = lista->inicio;

    if(!no) return 1;

    no->ant = NULL;
    no->prox = NULL;
    no->info = elemento;

    while(aux->prox) aux = aux->prox;

    aux->prox = no;
    no->ant = aux;

    lista->tamanho++;
    return 0;
}

int insere_lista_posicao(Lista lista, tipo_elemento elemento, int posicao){
    if(!lista) return -1;

    if(posicao <= 0 || posicao > lista->tamanho) return -2;

    if(posicao == 1) return insere_lista_inicio(lista,elemento);

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo)),
    *aux = lista->inicio;

    if(!no) return 1;

    no->ant = NULL;
    no->prox = NULL;
    no->info = elemento;

    int pecorrido = 1;

    while(aux->prox){
        if(pecorrido < posicao) aux = aux->prox;
        else break;
        pecorrido++;
    }

    no->prox = aux;
    no->ant = aux->ant;
    aux->ant->prox = no;
    aux->ant = no;

    lista->tamanho++;
    return 0;
}

int remove_lista_inicio(Lista lista, tipo_elemento* elemento){
    if(!lista || !lista->inicio) return -1;

    tipo_nodo *aux = lista->inicio;
    (*elemento) = aux->info;

    lista->inicio = aux->prox;
    lista->inicio->ant = NULL;
    lista->tamanho--;
    free(aux);
    return 0;
}

int remove_lista_final(Lista lista, tipo_elemento* elemento){
    if(!lista || !lista->inicio) return -1;

    tipo_nodo *aux = lista->inicio;

    while(aux->prox) aux = aux->prox;

    if(lista->inicio == aux) lista->inicio = NULL;
    else aux->ant->prox = NULL;

    (*elemento) = aux->info;
    lista->tamanho--;
    free(aux);

    return 0;
}

int remove_lista_posicao(Lista lista, tipo_elemento* elemento, int posicao){
    if(!lista || !lista->inicio) return -1;

    if(posicao <= 0 || posicao > lista->tamanho) return -2;

    if(posicao == 1) return remove_lista_inicio(lista,elemento);

    if(posicao == lista->tamanho) return remove_lista_final(lista,elemento);

    tipo_nodo *aux = lista->inicio;

    int pecorrido = 1;

    while(aux->prox){
        if(pecorrido != posicao) aux = aux->prox;
        else break;
        pecorrido++;
    }

    (*elemento) = aux->info;

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;

    aux->prox = NULL;
    aux->ant = NULL;

    lista->tamanho--;
    free(aux);

    return 0;
}

int lista_vazia(Lista lista){
    return (!lista->inicio);
}

void termina_lista(Lista lista){
    tipo_nodo *aux;

    while(lista->inicio){
        aux = lista->inicio;
        lista->inicio = aux->prox;
        lista->tamanho--;
        free(aux);
    }
    free(lista);
}

void exibe_lista(Lista lista){
    tipo_nodo* aux = lista->inicio;
    printf("\n%d",lista->tamanho);
    while(aux != NULL){
        printf("\n\t%ld\n",aux->info.chave);
        aux = aux->prox;
    }
}
