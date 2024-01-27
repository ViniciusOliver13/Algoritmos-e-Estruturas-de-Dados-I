#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ret{
    float base, alt;
} Ret;

typedef struct cir{
    float diamentro;
} Circ;

Ret retan_Circunscrito(Circ *p, Ret *h){
    Ret maior;

    maior.alt = p->diamentro;
    maior.base = h->alt;

    return maior;
}

Circ circ_Interno(Ret *p){
    Circ circulo;

    if (p->base / 2 < p->alt / 2){
        circulo.diamentro = p->base / 2;
    }else{
        circulo.diamentro = p->alt / 2;
    }

    return circulo;
}

int main(){
    
    Circ *p = malloc(sizeof(Circ));
    Ret *r = malloc(sizeof(Ret));

    if (p == NULL || r == NULL){
        printf("Erro na alocacao!");
        exit(1);
    }

    printf("1- Informe o diametro do circulo: ");
    scanf(" %f", &p->diamentro);

    printf("   Informe a altura do retangulo: ");
    scanf(" %f", &r->alt);

    printf("2- Digite a base do retangulo: ");
    scanf(" %f", &r->base);

    printf("   Informe a altura do retangulo: ");
    scanf(" %f", &r->alt);


    printf("1- O maior retangulo circunscrito possivel:\nLargura: %.2f\nAltura: %.2f\n",retan_Circunscrito(p, r).alt, retan_Circunscrito(p, r).base);
    printf("2- O maior circulo interno ao retangulo tem:\nRaio:  %.2f\nDiametro: %.2f\n", circ_Interno(r).diamentro, circ_Interno(r).diamentro * 2);

    free(p);
    free(r);
    
    return 0;
}