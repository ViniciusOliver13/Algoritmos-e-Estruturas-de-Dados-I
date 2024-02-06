#include <stdio.h>
#include "funcoes.h"      

//Arquivo onde é realizado todos os cálculos das funções presentes no arquivo "funcoes.h".

int adicao(int a1, int a2){
    int res;
    res = a1 + a2;

    return res;
}

int subtracao(int a1, int a2){
    int res;
    res = a1 - a2;

    return res;
}

int multiplicacao(int a1, int a2){
    int res;
    res = a1 * a2;

    return res;
}

float divisao(int a1, int a2){
    float res;
    res = a1 / a2;
    
    return res;
}

int potenciacao(int a1, int a2){
    int i, res = 1;
    res = a1;
    for(i = 1; i < a2; i++){
        res *= a1;
    }
    
    return res;
}
