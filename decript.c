#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"

int main()
{
    char decod[1024*10] = {'\0'};
    char cToStr[2];
    cToStr[1] = '\0';

    char cod[1024*10];
    printf("Enter a string to decode: ");
    scanf("%s", cod);

    char k[(10*2)+1];
    printf("Enter key: ");
    scanf("%20s", k);

    int seq[(10*2)];
    int copia_seq[(10*2)];
    memset(seq, -1, sizeof(seq));

    sequencia(k, seq);


    char *bloco[10];
    for (int i=0; i<10; i++)
    {
        bloco[i] = malloc(10 * sizeof(char));
        if(!bloco[i]) return 1;
    }

    int len = strlen(cod);
    // int qtd_blocos = (len / 100);
    int l = 0; // para leitura do bloco                                           
    while (l < len)
    {
        // faz a chave se igualar ao estado no final da codificação em cada bloco
        // for (int i=0; i<10; i++)
        //     (i % 2) ? troca_nums(seq, 0, 10) : troca_nums(seq, 10, 0);

        // restaura a sequencia de acordo com o comeco do proximo bloco
        if (l != 0)
            strcpy(seq, copia_seq);

        // le o bloco
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                bloco[i][j] = cod[l++];
                // printf("%c\n", bloco[i][j]);
            }

            // prepara sequencia para ficar no estado final do bloco
            (i % 2) ? troca_nums(seq, 0, 10) : troca_nums(seq, 10, 0);
        }

        // guarda a sequencia ao final na copia
        strcpy(copia_seq, seq);

        for (int i=0; i<10; i++)
        {
            if (i % 2)
            {
                for (int j=0; j<(10/2); j++)
                    troca_colunas(bloco, seq[j*2], seq[(j*2)+1]);

                troca_nums(seq, 10, 0);
            }
            else
            {
                for (int j=0; j<(10/2); j++)
                    troca_linhas(bloco, seq[j*2], seq[(j*2)+1]);

                troca_nums(seq, 0, 10);
            }
        }


        // escreve bloco codificado na nova string
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                cToStr[0] = bloco[i][j];
                strcat(decod, cToStr);
            }
        }
        // printf("%s\n", decod);

    }

    
    printf("%s\n", decod);


    for (int i=0; i<10; i++)
        free(bloco[i]);


    return 0;
}