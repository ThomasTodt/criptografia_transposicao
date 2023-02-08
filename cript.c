#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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

int main()
{
    srand(time(NULL)); // seed the random number generator

    char nova[1024*10] = {'\0'};
    char cToStr[2];
    cToStr[1] = '\0';

    char s[1024*10];
    printf("Enter a string to encode: ");
    // fgets(s, 1024*10, stdin);
    scanf("%s", s);

    char k[(10*2)+1];
    printf("Enter key: ");
    scanf("%20s", k);


    int seq[(10*2)];
    memset(seq, -1, sizeof(seq));

    sequencia(k, seq);

    for (int i=0; i<(10*2); i++)
        printf("%d ", seq[i]);
    printf("\n");


    char *bloco[10];
    for (int i=0; i<10; i++)
    {
        bloco[i] = malloc(10 * sizeof(char));
        if(!bloco[i]) return 1;
    }


    int l = 0;
    while (1)
    {
        // le o bloco
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (s[l] != '\0')
                    bloco[i][j] = s[l++];
                    // l++;
                else
                    bloco[i][j] = (char)(rand() % 26 + 'a');
            }
        }

        
        // transposicoes
        for (int i=0; i<10; i++)
        {
            if (i % 2)
            {
                for (int j=0; j<(10/2); j++)
                    troca_colunas(bloco, seq[j*2], seq[(j*2)+1]);

                troca_nums(seq, 0, 10);
            }
            else
            {
                for (int j=0; j<(10/2); j++)
                    troca_linhas(bloco, seq[j*2], seq[(j*2)+1]);

                troca_nums(seq, 10, 0);
            }
        }


        // escreve bloco codificado na nova string
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                cToStr[0] = bloco[i][j];
                strcat(nova, cToStr);
            }
        }


        // acabaram os blocos
        if (s[l] == '\0')
            break;
    }
    

    printf("%s\n", nova);

          
    for (int i=0; i<10; i++)
        free(bloco[i]);

    return 0;
}