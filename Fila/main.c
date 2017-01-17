#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main()
{
    Fila f = cria_fila();
    exibe_fila(f);

    tipo_elemento e;

    e.chave = 92359232;
    enfileirar(f,e);
    exibe_fila(f);

    e.chave = 84534534;
    enfileirar(f,e);
    exibe_fila(f);

    e.chave = 10923423;
    enfileirar(f,e);
    exibe_fila(f);

    e.chave = 67554323;
    enfileirar(f,e);
    exibe_fila(f);

    desenfileirar(f,&e);
    exibe_fila(f);

    desenfileirar(f,&e);
    exibe_fila(f);

    desenfileirar(f,&e);
    exibe_fila(f);

    desenfileirar(f,&e);
    exibe_fila(f);

    destroi_fila(f);
    return 0;
}
