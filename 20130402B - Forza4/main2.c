#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define ROW 6
#define COL 7

int board[ROW][COL];

void checkwin(char* colore);
void nextmove(char* colore);

int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1],"r");
    //start boiler plate
    if(argc != 4){
        printf("Numero Non Corretto di argomenti\n");
        return -1;
    }
    if(fp==NULL){
        printf("ERRORE LETTURA FILE\n");
        return -1;
    }
    if(argv[2][0] != '-'){
        printf("ERRORE COMANDO");
        return -1;
    }
    if(strcmp(argv[3],"giallo") != 0 && strcmp(argv[3],"rosso") != 0 ){
        printf("ERRORE COMANDO GIALLO ROSSO");
        return -1;
    }
    //end boilerplate

    int i, j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            board[i][j] =  fgetc(fp);
        }
        fgetc(fp); //prendo \n
    }

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }


    switch(argv[2][1]){
        case 'a':
        case 'A':
            checkwin(argv[3]);
            break;
        case 'b':
        case 'B':
            nextmove(argv[3]);
            break;
        default:break;
    }
    return 0;
}
void checkwin(char* colore){
    printf("%c",colore[0]);
    printf("\n");
    int i, j, k, l;
    int counter = 0;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(board[i][j] == colore[0]){
                counter++;

                l=j+3;
                if( (l>=COL) || (board[i][l] != colore[0]) ){
                    counter=0;
                    break;
                }else{
                    if( (board[i][l-1] == colore[0]) && (board[i][l-2] == colore[0])){
                        counter+=3;
                    }
                }
            }else{
                counter=0;
            }
            if(counter==4){
                printf("%s ha vinto in orizzontale\n",colore);
                return;
            }
        }
        counter = 0;
    }

    for(i=0;i<COL;i++){
        for(j=0;j<ROW;j++){
            if(board[j][i] == colore[0]){
                counter++;

                k=i+3;
                if( (k>=ROW) || (board[k][j] != colore[0]) ){
                    counter=0;
                    break;
                }else{
                    if( (board[k-1][j] == colore[0]) && (board[k-2][j] == colore[0])){
                        counter+=3;
                    }
                }
            }else{
                counter=0;
            }
            if(counter==4){
                printf("%s ha vinto in verticale\n",colore);
                return;
            }
        }
        counter = 0;
    }

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(board[i][j] == colore[0]){
                counter++;

                l=j+3;
                k=i+3;
                if( (k>=ROW) || (l>=COL) || (board[k][l] != colore[0]) ){
                    counter=0;
                    break;
                }else{
                    if( (board[k-1][l-1] == colore[0]) && (board[k-2][l-2] == colore[0])){
                        counter+=3;
                    }
                }
            }else{
                counter=0;
            }
            if(counter==4){
                printf("%s ha vinto in diagonale\n",colore);
                return;
            }
        }
        counter = 0;
    }

    for(i=0;i<ROW;i++){
        for(j=COL;j>0;j--){
            if(board[i][j] == colore[0]){
                counter++;

                l=j-3;
                k=i+3;
                if( (k>=ROW) || (l<0) || (board[k][l] != colore[0]) ){
                    counter=0;
                    break;
                }else{
                    if( (board[k-1][l+1] == colore[0]) && (board[k-2][l+2] == colore[0])){
                        counter+=3;
                    }
                }
            }else{
                counter=0;
            }
            if(counter==4){
                printf("%s ha vinto in diagonale\n",colore);
                return;
            }
        }
        counter = 0;
    }

    printf("Non sei riuscito a mettere 4 pedine allineate");
}

void nextmove(char* colore){
    printf("%c",colore[0]);
    printf("\n");
    int i,j,k,l;
    int counter;
    int sum = 0;
    sum = colore[0]*3;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(board[i][j] == colore[0]){
                l=j+3;
                if( l>=COL ){
                    break;
                }else{
                    sum -= board[i][l] + board[i][l-2] + board[i][l-1];
                    if(sum=='0'){
                        printf("inserimento possibile\n");
                    }
                }
            }
        }
    }

}

