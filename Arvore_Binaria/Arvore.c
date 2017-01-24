#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"

Apontador cria_arvore(){
    return NULL;
}

int insere_arvore(Apontador *raiz,tipo_elemento elemento){
    if(!*raiz){
        *raiz =(Apontador)malloc(sizeof(tipo_nodo));
        (*raiz)->direita = NULL;
        (*raiz)->esquerda = NULL;
        (*raiz)->info = elemento;
        return 0;
    }else{
        if(elemento.chave > (*raiz)->info.chave) return insere_arvore(&(*raiz)->direita,elemento);
        else if(elemento.chave < (*raiz)->info.chave) return insere_arvore(&(*raiz)->esquerda,elemento);

    }
    return -1;
}

int insere_arvore_sem_recursao(Apontador *raiz,tipo_elemento elemento){
    Apontador *aux = raiz;
    while(*aux){
        if(elemento.chave > (*aux)->info.chave) aux = &(*aux)->direita;
        else if(elemento.chave < (*aux)->info.chave) aux = &(*aux)->esquerda;
                else return -1;
    }

    *aux=(Apontador)malloc(sizeof(tipo_nodo));
    (*aux)->esquerda = NULL;
    (*aux)->direita = NULL;
    (*aux)->info = elemento;
    return 0;
}

int exclui_arvore(Apontador *raiz,tipo_elemento *elemento){
    if((*raiz)) printf("\n\n%d --- %d\n\n",(*raiz)->info.chave, elemento->chave);
    if((*elemento).chave == (*raiz)->info.chave){
        (*elemento) = (*raiz)->info;
        Apontador aux;
        if((*raiz)->direita && (*raiz)->esquerda){
             aux = minimo((*raiz)->direita);
             (*raiz)->info = aux->info;
             (*elemento) = aux->info;
             exclui_arvore(&(*raiz)->direita,elemento);
        }else{
            aux = *raiz;
            if(!(*raiz)->esquerda) (*raiz) = (*raiz)->direita;
            else if(!(*raiz)->direita) (*raiz) = (*raiz)->esquerda;
            free(aux);
        }
        return 0;
    }else{
        if(elemento->chave > (*raiz)->info.chave) return exclui_arvore(&(*raiz)->direita,elemento);
        else if(elemento->chave < (*raiz)->info.chave) return exclui_arvore(&(*raiz)->esquerda,elemento);
    }
    return -1;
}

int exclui_arvore_sem_recursao(Apontador *raiz,tipo_elemento *elemento){
    Apontador *p,*aux;
    p = raiz;
    while(*p){
        if(elemento->chave > (*p)->info.chave) p = &(*p)->direita;
        else if(elemento->chave < (*p)->info.chave) p = &(*p)->esquerda;
        else if(elemento->chave == (*p)->info.chave){
            aux = &(*p);

            if(!(*p)->direita) *p = (*p)->esquerda;
            else if(!(*p)->esquerda) *p = (*p)->direita;
            else{
                    p=&(*aux)->esquerda;
                    while((*p)->direita) p = &(*p)->direita;
                    (*aux)->info = (*p)->info;
                    *aux = *p;
                    *p = (*p)->esquerda;

                }
                free(aux);

        }else return -1;
    }

    return 0;
}

void in_ordem(Apontador raiz){
    if(raiz){
        in_ordem(raiz->esquerda);
        printf("\n\t%d\n",raiz->info.chave);
        in_ordem(raiz->direita);
    }
}

Apontador minimo(Apontador raiz){
    if(!raiz) return NULL;
    else{
        if(!raiz->esquerda) return raiz;
        else return minimo(raiz->esquerda);
    }
}

Apontador maximo(Apontador raiz){
     if(!raiz) return NULL;
    else{
        if(!raiz->direita) return raiz;
        else return minimo(raiz->direita);
    }
}

void termina_arvore(Apontador raiz){
    if(raiz){
        termina_arvore(raiz->esquerda);
        termina_arvore(raiz->direita);
        free(raiz);
    }
}

int altura(Apontador raiz){
    if(!raiz) return -1;
    else{
        int ae = altura(raiz->esquerda),
            ad = altura(raiz->direita);
        return ae < ad ? ad+1 : ae+1;
    }
}

int numero_nos(Apontador raiz){
    return !raiz ? 0 : (1+numero_nos(raiz->esquerda)+numero_nos(raiz->direita));
}

int iguais(Apontador a, Apontador b){
    return (!a && !b ||
            (a && b && a->info.chave == b->info.chave &&
              iguais(a->esquerda, b->esquerda) && iguais(a->direita, b->direita)));
}
