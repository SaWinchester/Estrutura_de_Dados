#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int main()
{

    Lista l = cria_lista();

    tipo_elemento e;

    e.chave = 233237475;
    insere_lista_inicio(l,e);
    exibe_lista(l);

    e.chave = 124346344;
    insere_lista_inicio(l,e);
    exibe_lista(l);

    e.chave = 1243546344;
    insere_lista_fim(l,e);
    exibe_lista(l);

    e.chave = 126344;
    insere_lista_fim(l,e);
    exibe_lista(l);

    e.chave = 144;
    insere_lista_fim(l,e);
    exibe_lista(l);

    e.chave = 12496754;
    insere_lista_fim(l,e);
    exibe_lista(l);

    e.chave = 13615650638;
    int indice = 4;
    insere_lista_posicao(l,e,indice);
    exibe_lista(l);

    remove_lista_inicio(l,&e);
    exibe_lista(l);

    remove_lista_final(l,&e);
    exibe_lista(l);

    tipo_elemento ee;
    remove_lista_posicao(l,&ee,5);
    printf("\n\n%ld\n\n",ee.chave);
    exibe_lista(l);

    termina_lista(l);
    return 0;
}
