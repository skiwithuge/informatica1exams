#include <stdio.h>

typedef struct Punto_{
    int x;
    int y;
}Punto;

void moltiplica(int a, int b);
void molt(int* a, int* b);
int mul(int a, int b);
void assegnaPunto(Punto *a);

int main() {
    int *p;
    int variabile = 3;
    p = &variabile;

    printf("p: %d\n" , *p);
    int mat[3][4];
    mat[0][0] = 2;
    p = mat;
    //p = &mat[0][0];
    printf("mat: %d\n" , *p);

    int var1 = 3, var2 = 4;
    moltiplica(var1, var2);

    printf("var1: %d, var2:%d\n", var1, var2);

    molt(&var1,&var2);
    printf("var1: %d\n", var1);

    int res;
    res = mul(var1,var2);
    printf("res: %d\n", res);

    Punto z;
    assegnaPunto(&z);
    printf("Punto: x: %d, y:%d", z.x, z.y);
    return 0;
}

void moltiplica(int a, int b){
    a = a*b;
    printf("moltiplica: %d\n", a);
}

void molt(int* a, int* b){
    *a = *a * *b;
}

int mul(int a, int b){
    return a*b;
}

void assegnaPunto(Punto *a){
    (*a).x = 10;
    a->y = 12;
}