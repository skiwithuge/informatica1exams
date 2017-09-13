#include <stdio.h>

#define R 7
#define C 10
#define KDIM 3

typedef struct Pos_{
    int r,c;
}Pos;

int main(int argc, char* argv[]) {
    if(argc != 3){
        printf("Errore\n");
        return -1;
    }
    int i, j, k,l;
    FILE * immagine = fopen(argv[1], "r");
    FILE * kernel = fopen(argv[2], "r");
    int kernelMat[KDIM][KDIM] = {0};
    int immagineMat[R][C] = {0};

    for(i=0; i < KDIM; i++){
        for(j=0; j < KDIM; j++){
            fscanf(kernel,"%d", &kernelMat[i][j]);
        }
    }

    for(i=0; i < R; i++){
        for(j=0; j < C; j++){
            fscanf(immagine,"%d", &immagineMat[i][j]);
        }
    }
    //start the convolution
    //consider all the edges
    //topleft, top, topright, centerleft, center,centerright, bottomleft,bottomcenter, bottomright
    int res;
    Pos vec[KDIM][KDIM];
    for(i=0; i < R; i++){
        for(j=0; j < C; j++){
            //fscanf(immagine,"%d", &immagineMat[i][j]);
            //top
            vec[0][0].c = j-1;
            vec[0][0].r = i-1;

            vec[0][1].c = j;
            vec[0][1].r = i-1;

            vec[0][2].c = j+1;
            vec[0][2].r = i-1;
            //center
            vec[1][0].c = j-1;
            vec[1][0].r = i;

            vec[1][1].c = j;
            vec[1][1].r = i;

            vec[1][2].c = j+1;
            vec[1][2].r = i;
            //bottom
            vec[2][0].c = j-1;
            vec[2][0].r = i+1;

            vec[2][1].c = j;
            vec[2][1].r = i+1;

            vec[2][2].c = j+1;
            vec[2][2].r = i+1;

            res = 0;
            for(k=0;k<KDIM;k++){
                for(l=0;l<KDIM;l++){
                    if(vec[k][l].c >= 0 && vec[k][l].c < C && vec[k][l].r >= 0 && vec[k][l].r < R){
                        res += kernelMat[k][l] * immagineMat[vec[k][l].r][vec[k][l].c];
                    }
                }
                //if(vec[k][l].c < 0);
            }

            //res = kernelMat[0][0] * immagineMat[vec[0].r][vec[0].c];

            printf("%d ", res);
        }
        printf("\n");
    }
    return 0;
}