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
    printf("Insira a mensagem a ser descriptografada: ");
    scanf("%s", cod);

    char k[(10*2)+1];
    printf("Insira a chave: ");
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
    int l = 0; // para leitura do bloco                                           
    while (l < len)
    {
        // restaura a sequencia de acordo com o comeco do proximo bloco
        if (l != 0)
            copy_array(copia_seq, seq, (10*2));

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
        copy_array(seq, copia_seq, (10*2));

        for (int i=9; i>=0; i--)
        {
            if (i % 2)
            {
                troca_nums(seq, 0, 10);

                for (int j=0; j<(10/2); j++)
                    troca_colunas(bloco, seq[j*2], seq[(j*2)+1]);
            }
            else
            {
                troca_nums(seq, 10, 0);

                for (int j=0; j<(10/2); j++)
                    troca_linhas(bloco, seq[(j*2)+10], seq[(j*2)+1+10]);
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


    // procura pelo sinal de final da mensagem original
    int count = 1;
    int final = -1;
    for (int i = 1; i < len; i++) {

        if (decod[i] == decod[i - 1])
            count++;      
        else 
            count = 1;

        if (count == 4) 
        {
            final = i - 3;
            break;
        }
    }

    decod[final+1] = '\0';


    printf("Mensagem descriptografada:\n\t%s\n", decod);


    for (int i=0; i<10; i++)
        free(bloco[i]);

    return 0;
}