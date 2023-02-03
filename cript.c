#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void sequencia(char *chave, char *seq)
{
    int min = __INT_MAX__;
    int min_pos = 0;

    // criar mais duas variaveis de min e fazer a segunda metade no mesmo loop?
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (chave[j] < min && seq[j] == -1)
            {
                min = chave[j];
                min_pos = j;
            }
        }

        seq[min_pos] = i;
    }

}

int main()
{
    char s[1024*10];
    printf("Enter a string to encode: ");
    fgets(s, 1024*10, stdin);

    char k[21];
    printf("Enter key: ");
    scanf("%20s", k);


    int seq[20] = {-1};
    sequencia(s, seq);


    return 0;
}