#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
void calcula_hexagono(float l, float *area, float *perimetro){

    *area = (3 * pow(l, 2) * sqrt(3) / 2);
    *perimetro = 6 * l;

}
int main(){
    setlocale(LC_ALL,"Portuguese");
    float lado, a, p = 0;

    printf("Qual � o tamanho do lado do hex�gono regular? ");
    scanf("%f", &lado);

    calcula_hexagono(lado, &a, &p);

    printf("A �rea do hex�gono regular � %.3f com Per�metro %.2f.", a, p);

    return 0;
}