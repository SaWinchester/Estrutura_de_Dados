#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"

int main()
{
    int vetor[MAX];
    vetor[0] = 23;
    vetor[1] = 34;
    vetor[2] = 11;
    vetor[3] = 4;
    vetor[4] = 2;
    vetor[5] = 64;
    vetor[6] = 67;
    vetor[7] = 3;
    vetor[8] = 1;
    vetor[9] = 9;

    merge_sort(vetor,0,9);

    for(int i = 0; i < MAX; i++) printf("\n%d",vetor[i]);

    return 0;
}
