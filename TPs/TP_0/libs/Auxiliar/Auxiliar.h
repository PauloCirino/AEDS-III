#ifndef AUXILIAR_H_INCLUDED
#define AUXILIAR_H_INCLUDED

/*Funcoes utilizadas pela main() e nao pelos outros arquivos*/

/*Transforma todas as letras em letras maiusculas para que nao haja problemas com casos como "Amar" e "rama"*/
void maiuscula(char * palavra, int sizePalavra);

/*Metodo para compara char para que pudessemos ordenar as palavras via funcao qsort da stdlib.h*/
int comparaChar(const void * a, const void * b);

/*Metodo para comparar inteiros, para ordenar o vetor de com as resposta via funcao qsort da stdlib.h */
int comparaInt(const void * a, const void * b);

#endif // AUXILIAR_H_INCLUDED
