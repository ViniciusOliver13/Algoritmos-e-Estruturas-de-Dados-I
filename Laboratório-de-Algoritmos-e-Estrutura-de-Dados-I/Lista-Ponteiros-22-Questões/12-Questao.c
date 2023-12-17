#include <stdio.h>
#include <stdlib.h>
void fatorial(int *point, int num){
    int i = 0;
    for ( i = 1; i < num; i++){
        *point *= i;
    }
}
int main(){

    int num = 0;

    printf("Digite um valor para ver seu fatorial: ");
    scanf("%d", &num);
    fatorial(&num, num);
    printf("Fatorial: %d ", num);

    return 0;
}