/* Turno B esame 04/02/2013.
La soluzione non č ottimizzata cosě da aderire maggiormente alle possibili soluzioni degli studenti.
Tuttavia necessita, per un minimo di chiarezza, di molte funzioni*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define M 7

void openFile(char [][M], FILE*);
int first_op(char [][M], char []);
int second_op(char [][M], char []);
int ricerca_diagonale_opa(char [][M],char []);
int ricerca_diagonale_opb(char [][M],char []);
int ricerca_orizz_opa(char [][M],char []);
int ricerca_orizz_opb(char [][M],char []);
int ricerca_verticale_opa(char [][M],char []);
int ricerca_verticale_opb(char [][M],char []);

int main(int argc,char* argv[])
{
    FILE* fp;
    char mat[N][M];
    int pos;
    int flag;

    if (argc!=4){
        printf("Errore nel numero dei parametri\n");
        exit(1);
    }
    if (argv[2][0]!='-'|| strlen(argv[2])!=2){
        printf("Errore nel formato dei parametri\n");
        exit(1);
    }
    if ((fp=fopen(argv[1],"r"))==NULL){
        printf("Errore in apertura file\n");
        exit(2);
    }
    openFile(mat,fp);

    switch (argv[2][1]){
        case 'a': flag = first_op(mat,argv[3]);
            switch (flag){
                case 1: printf("Forza 4 in diagonale!\n");
                    break;
                case 2: printf("Forza 4 in orizzontale!\n");
                    break;
                case 3: printf("Forza 4 in verticale!\n");
                    break;
                default: printf("Non sei riuscito ad allineare 4 pedine\n");
                    break;
            }
            break;
        case 'b': pos = second_op(mat,argv[3]);
            if (pos!=-1)
                printf("Metti la pedina nella colonna %d\n", pos+1);
            else
                printf("Non e' possibile vincere con una mossa\n");
            break;
    }
    fclose(fp);
    return 0;
}

void openFile(char mat[][M],FILE* fp){
    int i,j;
    char str[M+1];

    i=0;
    while (fscanf(fp,"%s",str)!=EOF){
        for(j=0;j<M;j++)
            mat[i][j]=str[j];
        i++;
    }
    return;
}

int first_op(char mat[][M],char str[7]){
    int flag=0;

    if ((flag = ricerca_diagonale_opa(mat,str))==0)
        if ((flag = ricerca_orizz_opa(mat,str))==0)
            flag = ricerca_verticale_opa(mat,str);
    return flag;
}

int second_op(char mat[][M],char str[7]){
    int pos=-1;

    if ((pos = ricerca_diagonale_opb(mat,str))==-1)
        if ((pos = ricerca_orizz_opb(mat,str))==-1)
            pos = ricerca_verticale_opb(mat,str);
    return pos;
}

int ricerca_diagonale_opa(char mat[][M],char str[]){
    int i,j, flag=0;

    for(i=N-1;i>=3 && flag==0;i--)
        for(j=M-1;j>=3 && flag==0;j--)
            if (mat[i][j]==str[0])
                if ((mat[i-1][j-1]==str[0])&&(mat[i-2][j-2]==str[0])&&(mat[i-3][j-3]==str[0]))
                    flag=1;
    for(i=N-1;i>=3 && flag==0;i--)
        for(j=0;j<=M-4 && flag==0;j++)
            if (mat[i][j]==str[0])
                if ((mat[i-1][j+1]==str[0])&&(mat[i-2][j+2]==str[0])&&(mat[i-3][j+3]==str[0]))
                    flag=1;
    return flag;
}

int ricerca_diagonale_opb(char mat[][M],char str[]){
    int i,j,pos=-1;

    for(i=N-1;i>=3 && pos==-1;i--)
        for(j=M-1;j>=3 && pos==-1;j--)
            if (mat[i][j]==str[0])
                if ((mat[i-1][j-1]==str[0])&&(mat[i-2][j-2]==str[0])&&(mat[i-3][j-3]=='o') && (mat[i-2][j-3]!='o'))
                    pos=j-3;
    for(i=N-1;i>=3 && pos==-1;i--)
        for(j=0;j<=M-4 && pos==-1;j++)
            if (mat[i][j]==str[0])
                if ((mat[i-1][j+1]==str[0])&&(mat[i-2][j+2]==str[0])&&(mat[i-3][j+3]=='o') && (mat[i-2][j+3]!='o'))
                    pos=j+3;
    return pos;
}

int ricerca_orizz_opa(char mat[][M],char str[]){
    int i,j,flag=0;

    for(i=N-1;i>=0 && flag==0;i--)
        for(j=0;j<=M-4 && flag==0;j++)
            if (mat[i][j]==str[0])
                if ((mat[i][j+1]==str[0])&&(mat[i][j+2]==str[0])&&(mat[i][j+3]==str[0]))
                    flag=2;
    return flag;
}

int ricerca_orizz_opb(char mat[][M],char str[]){
    int i,j,pos=-1;

    for(i=N-1;i>=0 && pos==-1;i--)
        for(j=M-1;j>=3 && pos==-1;j--)
            if (mat[i][j]==str[0])
                if ((mat[i][j-1]==str[0])&&(mat[i][j-2]==str[0])&&(mat[i][j-3]=='o') && ((i<N-1) && mat[i+1][j-3]!='o'))
                    pos=j-3;
    for(i=N-1;i>=0 && pos==-1;i--)
        for(j=0;j<=M-4 && pos==-1;j++)
            if (mat[i][j]==str[0])
                if ((mat[i][j+1]==str[0])&&(mat[i][j+2]==str[0])&&(mat[i][j+3]=='o') && ((i<N-1) && mat[i+1][j+3]!='o'))
                    pos=j+3;
    return pos;
}

int ricerca_verticale_opa(char mat[][M],char str[]){
    int i,j,flag=0;

    for(i=N-1;i>=3 && flag==0;i--)
        for(j=M-1;j>=0 && flag==0;j--)
            if (mat[i][j]==str[0])
                if ((mat[i-1][j]==str[0])&&(mat[i-2][j]==str[0])&&(mat[i-3][j]==str[0]))
                    flag=3;

    return flag;
}

int ricerca_verticale_opb(char mat[][M],char str[]){
    int i,j,pos=-1;

    for(i=N-1;i>=3 && pos==-1;i--)
        for(j=M-1;j>=0 && pos==-1;j--)
            if (mat[i][j]==str[0])
                if ((mat[i-1][j]==str[0])&&(mat[i-2][j]==str[0])&&(mat[i-3][j]=='o'))
                    pos=j;

    return pos;
}