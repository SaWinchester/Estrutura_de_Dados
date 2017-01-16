#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main()
{
    Lista l = cria_lista();
    if(l) printf("Lista criada\n");
    else printf("Lista nao criada\n");

    if(lista_vazia(l))printf("Lista vazia\n");
    else printf("Lista nao vazia\n");

    tipo_elemento e;

    e.chave = 123456789;
    insere_lista_inicio(l,e);

    e.chave = 987654321;
    insere_lista_inicio(l,e);

    e.chave = 1235813;
    insere_lista_inicio(l,e);

    e.chave = 3747783853;
    insere_lista_inicio(l,e);

    e.chave = 389758972;
    insere_lista_inicio(l,e);

    e.chave = 3074230942;
    insere_lista_inicio(l,e);

    exibe_lista(l);

    remove_lista_inicio(l,&e);
    printf("\n\n%ld\n\n",e.chave);
    exibe_lista(l);

    insere_lista_fim(l,e);
    exibe_lista(l);

    e.chave=13615650638;
    insere_lista_posicao(l,e,6);
    exibe_lista(l);

    remove_lista_posicao(l,&e,6);
    exibe_lista(l);

    termina_lista(l);
    return 0;
}
