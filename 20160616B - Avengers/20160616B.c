#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 20
char* direzioni[] = {"sud","nord","est","ovest"};
typedef struct Avenger_{
    char nome[32+1];
    int r;
    int c;
    int dir;
}Avenger;

void leggiMappa(FILE* fp, char mappa[N][N], int* bombs);
void stampaMappa(char mappa[N][N], int * dim);
void sposta(char mappa[N][N], Avenger* a, int* time, int* dim, int* bombs);
void posiziona(Avenger* a, int r, int c);
int controlla(int* a, int *b, int* dim);

int main(int argc, char** argv)
{
    //inizializzo con un seed random
    int seed = time(NULL);
    printf("%d\n",seed);
    srand(seed);
    //definisco la matrice
    char mappa[N][N];
    int bombs = 0;
    //leggo il file
    FILE* fp;
    fp = fopen("segovia.txt", "r");
    int dim=N;
    //endtime e' il tempo residuo
    int endtime = atoi(argv[1]);

    //carico dal file la matrice e conto il numero di bombe
    leggiMappa(fp, mappa, &bombs);
    //stampaMappa(mappa, &dim);
    //preparo i due avenger
    Avenger thor, ironman;
    //gli do un nome(non serve a niente)
    strcpy(thor.nome,"Thor");
    strcpy(ironman.nome,"IronMan");
    //posiziono thor e ironman nell'origine
    posiziona(&thor,0,0);
    posiziona(&ironman,0,0);
    //time e' il tempo che passa
    int time = 0;

    while(time < endtime && bombs>0){
        printf("Time %d T(%d,%d) I(%d,%d)\n", time, thor.r, thor.c, ironman.r, ironman.c);
        sposta(mappa, &thor, &time, &dim, &bombs);
        sposta(mappa, &ironman, &time, &dim, &bombs);
        printf("T next: %d (%s); I next: %d (%s)\n",
               thor.dir, direzioni[thor.dir], ironman.dir, direzioni[ironman.dir]);
        time += 10;
    }
    if(bombs>0){
        printf("MISSIONE FALLITA\n");
    }else{
        printf("MISSIONE COMPIUTA\n");
    }
    //stampaMappa(mappa,&dim);
    return 0;
}

void leggiMappa(FILE* fp, char mappa[N][N], int* bombs){
    char c;
    int i = 0, j = 0;

    do{
        c=fgetc(fp);
        if(c != '\n'){
            mappa[i][j] = c;
            if(c == 'B')
                (*bombs)++;
            j++;
        }else{
            //fscanf(fp, "%c", &c); //skip \n
            i++;
            j=0;
        }
    }while( c != EOF);
}

void stampaMappa(char mappa[N][N], int * dim){
    int i, j;
    for(i = 0; i < *dim;i++){
        for(j=0; j< *dim; j++){
            printf("%c", mappa[i][j]);
        }
        printf("\n");
    }
}

// (0=sud, 1=nord, 2=est, 3=ovest)
void sposta(char mappa[N][N], Avenger* a, int* time, int* dim, int* bombs){
    int dir = rand()%4;
    int r,c;
    r = (*a).r;
    c = (*a).c;
    switch(dir){
        case 0:
            r++; //per scendere devo incrementare
            break;
        case 1:
            r--;
            break;
        case 2:
            c++;
            break;
        case 3:
            c--;
            break;
    }
    (*a).dir = dir;
    if(controlla(&r,&c,dim)){
        //e' giusto, controllo cosa c' e'
        if(mappa[r][c] == '*'){// e' un muro
            ;
        }
        if(mappa[r][c] == 'o'){// posso muovermi
            posiziona(a, r, c);
        }
        if(mappa[r][c] == 'B'){// e' una bomba, disinnesco e mi posiziono
            mappa[r][c] = 'o';
            posiziona(a, r, c);
            (*bombs)--;
        }
    }
}

void posiziona(Avenger* a, int r, int c){
    (*a).r = r;
    (*a).c = c;
}
int controlla(int* a, int *b, int* dim){
    //printf("%d\n", *dim);
    if(*a > *dim || *a <= 0 || *b > *dim || *b <= 0 )
        return 0;
    else
        return 1;
}