#include <stdlib.h>

void troca_colunas(char **bloco, int a, int b)
{
    char tmp;
    for (int i=0; i<10; i++)
    {
        tmp = bloco[i][a];
        bloco[i][a] = bloco[i][b];
        bloco[i][b] = tmp;
    }

    return;
}

void troca_linhas(char **bloco, int a, int b)
{
    char *tmp;
    
    tmp = bloco[a];
    bloco[a] = bloco[b];
    bloco[b] = tmp;

    return;
}

// embaralha uma metade baseada na outra
// ex: 1234 2413
// base = 0, chave = 4
// fica:
// 3412 2413
void troca_nums(int *seq, int base, int chave)
{
    int tmp;
    int a, b;
    for (int j=0; j<(10/2); j++)
    {
        a = seq[chave + j*2] + base;
        b = seq[chave + j*2 + 1] + base;

        tmp = seq[a];
        seq[a] = seq[b];
        seq[b] = tmp;
    }

    return;
}

void sequencia(char *chave, int *seq)
{
    int min, min2;
    int min_pos, min_pos2;

    for (int i=0; i<10; i++)
    {
        min = min2 = __INT_MAX__;
        min_pos = -1;

        for (int j=0; j<10; j++)
        {
            if (chave[j] < min && seq[j] == -1)
            {
                min = chave[j];
                min_pos = j;
            }

            if (chave[j+10] < min2 && seq[j+10] == -1)
            {
                min2 = chave[j+10];
                min_pos2 = j+10;
            }
        }

        seq[min_pos] = seq[min_pos2] = i;

    }

}

void copy_array(int *source, int *dest, int size) 
{
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}