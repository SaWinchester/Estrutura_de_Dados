#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

Lista cria_lista(){
    Lista l = (tipo_lista*)malloc(sizeof(tipo_lista));
    if(!l) return NULL;

    l->tamanho = 0;
    l->inicio = NULL;
    return l;
}
int insere_lista_inicio(Lista lista, tipo_elemento elemento){
    if(!lista) return -1;

    tipo_nodo* no = (tipo_nodo*) malloc(sizeof(tipo_nodo));

    if(!no) return 1;

    no->info = elemento;
    no->prox = lista->inicio;
    lista->inicio = no;
    lista->tamanho++;
    return 0;
}

int insere_lista_fim(Lista lista, tipo_elemento elemento){
    if(!lista) return -1;

    if(!lista->inicio)return insere_lista_inicio(lista,elemento);

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo)),
    *aux = lista->inicio;

    if(!no) return 1;

    no->prox = NULL;
    no->info = elemento;

    while(aux->prox) aux = aux->prox;

    aux->prox = no;
    lista->tamanho++;

    return 0;
}

int insere_lista_posicao(Lista lista, tipo_elemento elemento, int posicao){
    if(!lista) return -1;

    if(posicao <= 0 || posicao > lista->tamanho) return -2;

    if(posicao == 1) return insere_lista_inicio(lista,elemento);

    if(!lista->inicio) return insere_lista_inicio(lista,elemento);

    tipo_nodo *no = (tipo_nodo*) malloc(sizeof(tipo_nodo)),
    *aux = lista->inicio, *aux1;

    if(!no) return 1;

    no->prox = NULL;
    no->info = elemento;

    int pecorrido = 1;

    while(aux->prox){
        if(pecorrido < posicao){
            aux1 = aux;
            aux = aux->prox;
        }else break;
        pecorrido++;
    }

    no->prox = aux;
    aux1->prox = no;
    lista->tamanho++;

    return 0;
}

int remove_lista_inicio(Lista lista, tipo_elemento* elemento){
    if(!lista || !lista->inicio) return -1;

    tipo_nodo *aux = lista->inicio;
    lista->inicio = aux->prox;
    lista->tamanho--;
    (*elemento) = aux->info;
    free(aux);
    return 0;
}

int remove_lista_posicao(Lista lista, tipo_elemento* elemento, int posicao){
    if(!lista || !lista->inicio) return -1;

    if(posicao < 0 || posicao > lista->tamanho) return -2;

    if(posicao == 1) return remove_lista_inicio(lista,elemento);

    //if(posicao == lista->tamanho) return remove_lista_final(lista,elemento);

    tipo_nodo *aux = lista->inicio, *aux1;
    int pecorrido = 1;

    while(aux->prox){
        if(pecorrido != posicao){
            aux1 = aux;
            aux = aux->prox;
        }else break;
        pecorrido++;
    }

    (*elemento) = aux->info;
    aux1->prox = aux->prox;
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
