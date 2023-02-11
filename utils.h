// embaralha uma metade baseada na outra
// ex: 1234 2413
// base = 0, chave = 4
// fica:
// 3412 2413
void troca_nums(int *seq, int base, int chave);

void troca_linhas(char **bloco, int a, int b);

void troca_colunas(char **bloco, int a, int b);

// faz cada metade da chave ser representada por digitos de 0 a 9, indicando sua ordem alfabética
// ex: abc ere
// vira: 012 021
void sequencia(char *chave, int *seq);