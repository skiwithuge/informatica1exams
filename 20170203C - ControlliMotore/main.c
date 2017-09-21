#include <stdio.h>
#include <stdlib.h>

typedef struct valori{
    double min;
    double max;
}VALORI;

int main(int argc, char* argv[]) {
    FILE * fp = fopen("misure.txt","r");
    FILE * fl = fopen("limiti.txt","r");

    //start boilerplate
    if(argc != 2){
        printf("ERRORE NUMERO PARAMETRI \n");
        return -1;
    }
    if( (fp == NULL) || (fl == NULL) ){
        printf("ERRORE LETTURA FILE \n");
        return -1;
    }
    //end boilerplate

    VALORI parametri[10];
    float   lista[5][10];

    int i,j;
    for(i = 0; i <10;){
        while(fscanf(fl,"%lf %lf",&parametri[i].min,&parametri[i].max) != EOF){
            i++;
        }
    }

    int riga= 0 , contatore = 0;
    int pieno = 0, anomalie, totale = 0;
    float results = 0;
    while(fscanf(fp,"%f %f %f %f %f %f %f %f %f %f", &lista[riga][0], &lista[riga][1], &lista[riga][2],
                 &lista[riga][3], &lista[riga][4], &lista[riga][5], &lista[riga][6], &lista[riga][7], &lista[riga][8],
                 &lista[riga][9] ) != EOF ){
        ++riga;
        ++contatore;
        if(riga == 5){
            riga = 0;
            pieno = 1;
        }
        if(pieno){
            //fai statistiche
            anomalie = 0;
            for(i=0; i<10; i++){
                results = 0;
                for(j=0;j<5;j++){
                    results += lista[j][i];
                }
                results /= 5;
                if(results < parametri[i].min || results > parametri[i].max)
                    anomalie++;
            }
            if(anomalie > atoi(argv[1])){
                printf("Anomalia %d\n", contatore);
                totale++;
            }
        }
    }
    printf("Totale anomalie:%d\n",totale);
    return 0;
}