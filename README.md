# criptografia_transposicao

A mensagem, que nessa implementação deve conter apenas caracteres de 'a' a 'z' (sem espaços), é dividida em blocos 10x10 de caracteres.

A chave também é formada por caracteres dessa forma, e é truncada para 20 caracteres (chave deve ter comprimento ao menos 20).

Cada metade da chave é transformada numa sequência, que representa a ordem alfabética entre os 10 caracteres (caracteres repetidos são decididos pela ordem de ocorrência).

São feitas n (nesse caso, 10) rodadas de transposições, de forma que:

- nas rodadas ímpares, as colunas são transpostas, seguindo a primeira metade da chave, de forma que, se a primeira metade for 1234567890, serão trocadas de posição entre si os pares de colunas (1,2), (3,4), e assim por diante.
após essas operações, a primeira metade da chave também sofre transposição análoga, e a "chave" que indica os pares de caracteres a serem trocados de posição será a segunda metade da chave

- nas rodads pares, a operação é similar às ímpares, mas se invertem as metades das chaves usadas para cada coisa, e são as linhas que são transpostas