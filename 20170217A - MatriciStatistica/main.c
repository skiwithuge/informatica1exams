#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX 10
#define M_MAX 10

typedef struct Element_{
    int value;
    int freq;
}Element;

int main(int argc, char * argv[]) {
    char nomeFile[20+1];
    Element vettore[N_MAX*M_MAX];
    printf("Inserire nome file: ");
    scanf("%s", nomeFile);
    printf("\n%s\n", nomeFile);
    //strcpy(nomeFile, "matr.txt");
    int matrix[N_MAX][M_MAX] = {0};
    int N = 0, M = 0;
    FILE* fp;
    //fp = fopen("matr.txt", "r");
    if(!(fp=fopen(nomeFile, "r")))
        return -1;
    //printf("%d %d \n", atoi(argv[1]), atoi(argv[2]));
    if(sscanf(argv[1], "%d", &N) == -1 || sscanf(argv[2], "%d", &M) == -1 )
        return -1;
    int dimensione = 0;
    int i, j, k;


    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            fscanf(fp,"%d", &matrix[i][j]);
        }
    }
    fclose(fp);

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
    int trovato = 0;
    for(i=0;i<N;i++) {
        for (j = 0; j < M; j++) {
            //cercaInserisci();
            for(k=0; k<dimensione;k++){
                if(matrix[i][j] == vettore[k].value){
                    vettore[k].freq++;
                    trovato = 1;
                    break;
                }
            }
            if(!trovato){
                vettore[k].value = matrix[i][j];
                vettore[k].freq = 1;
                dimensione++;
            }
            trovato = 0;
        }
    }

    for(k=0; k<dimensione;k++){
        printf("%d : %d\n", vettore[k].value, vettore[k].freq);
    }
}