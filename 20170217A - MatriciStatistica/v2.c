#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX 10
#define M_MAX 10

int main(int argc, char * argv[]) {
    char nomeFile[20+1];
    printf("Inserire nome file: ");
    scanf("%s", nomeFile);
    printf("\n%s\n", nomeFile);

    int matrix[N_MAX][M_MAX] = {0};
    int N = 0, M = 0;
    FILE* fp;
    if(!(fp=fopen(nomeFile, "r")))
        return -1;

    if(sscanf(argv[1], "%d", &N) == -1 || sscanf(argv[2], "%d", &M) == -1 )
        return -1;
    int i, j, k, l;;

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            fscanf(fp,"%d", &matrix[i][j]);
        }
    }
    fclose(fp);
    int curr,next,frequenza;
    for(i=0; i < N; i++){
        for(j=0;j<M;j++){
            if(matrix[i][j] != 0){
                frequenza = 1;
                curr = matrix[i][j];
                //frequenza++;
                l=j+1;
                for(k=i; k<N;k++){
                    for(;l<M;l++){
                        next = matrix[k][l];
                        if(curr == next){
                            matrix[k][l] = 0;
                            frequenza++;
                        }
                    }
                    l=0;
                }
                printf("%d: %d\n", curr, frequenza);
            }
        }
    }


    return 0;
}