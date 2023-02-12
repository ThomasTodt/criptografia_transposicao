#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"

int main()
{
    srand(time(NULL)); // seed the random number generator

    char nova[1024*10] = {'\0'};
    char cToStr[2];
    cToStr[1] = '\0';

    char s[1024*10];
    printf("Insira a mensagem a ser criptografada (somente [a-z]): ");
    scanf("%s", s);

    // prepara o sinal de final da string para a decodificacao
    int len = strlen(s);
    char ultima = s[len-1];
    s[len] = ultima;
    s[len+1] = ultima;
    s[len+2] = ultima;
    s[len+3] = '\0';


    char k[(10*2)+1];
    printf("Insira a chave (pelo menos 20 char): ");
    scanf("%20s", k);


    int seq[(10*2)];
    memset(seq, -1, sizeof(seq));

    sequencia(k, seq);


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
                    troca_linhas(bloco, seq[(j*2)+10], seq[(j*2)+1+10]);

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
    

    printf("Mensagem criptografada:\n\t%s\n", nova);

          
    for (int i=0; i<10; i++)
        free(bloco[i]);

    return 0;
}