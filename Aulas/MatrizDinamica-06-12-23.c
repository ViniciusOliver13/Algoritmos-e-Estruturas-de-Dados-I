#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
        Exerc�cio: Aloque dinamicamente uma matriz de inteiros 5x5 e preencha cada
        elemento da matriz com o seu respectivo �ndice (matriz[i][j] = i*5 + j). Em
        seguida, imprima a matriz.
*/

int main(){
    setlocale(LC_ALL,"Portuguese");

    int **mat, i, j;

    mat = malloc(5 * sizeof(int*));                  //Alocando mem�ria para os vetores de ponteiros para ponteiros (linhas).    

    if (mat == NULL){
        printf("Erro na aloca��o");                  //Verificando se a aloca��o dos vetores de ponteiros
        exit(1);                                     //para ponteiros ocorreu de maneira satisfat�ria.    
    }
    
    
    for ( i = 0; i < 5; i++){
        *(mat + i) = (int*) malloc(5 * sizeof(int)); //Alocando os vetores (colunas) da matriz.

        if (*(mat + i) == NULL){
            printf("Erro na aloca��o de mem�ria!");  //Verificando se a alo��o dos vetores (colunas) est�
            exit(1);                                 //ocorrendo de maneira satisfat�ria.
        }
    }
    
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            *(*(mat + i) + j) = i * 5 + j;           //Preenchedo a matriz de n�meros inteiros.
        }
    }

    for ( i = 0; i < 5; i++){
        for ( j = 0; j < 5; j++){
            printf("%2d ", *(*(mat + i) + j));       //Imprimindo a matriz 5x5.
        }   
        printf("\n");
    }
    
    for ( i = 0; i < 5; i++){
        free(*(mat + i ));                           //Liberando a mem�ra dos vetores (colunas) da matriz.  
    }

    free(mat);                                       //Liberando a mem�ria dos vetores de ponteiros para ponteiros (linhas).

    return 0;
}