#include <stdio.h>
#include <ctype.h>
#include "string.h"
#define L 20
#define P 50
int main(int argc, char** argv) {
    if(argc != 3){
        printf("Errore\n");
        return -1;
    }
    char frase[P*(L+1)];
    char parola[L+1];
    printf("Inserire testo\n");
    int i=0,j=0,k=0,l=0;
    FILE* fp = fopen(argv[2], "w");
    //controllo su fopen
    char c;
    int trovato = 0;

    FILE* rd = fopen("text.txt", "r");
    while( (c = getc(rd)) != EOF){
        frase[i] = c;
        i++;
        if( c == '?' || c == '.' || c == '!'){
        //putc(c ,stdout);
        //getc(rd);
            for(j=0; j < i; ){
                for(k=0; k< L; k++){
                    parola[k] = frase[j];
                    j++;
                    if(parola[k] == ' ' || parola[k] == '\n' || parola[k] == ','){
                        parola[k] = '\0';
                        for(l=0;l<k;l++){
                            parola[l] = tolower(parola[l]);
                        }
                        if(strcmp(parola, argv[1]) == 0){
                            trovato = 1;
                        }
                        break;
                    }
                }
            }
            if(trovato){
                for(j=0;j<i;j++)
                    putc(frase[j], fp);
                putc('\n', fp);
                trovato = 0;
            }
            i=0;
        }
    }
    /*while(scanf("%s", parola) != EOF){
        //printf("%s\n", parola);
        strcpy(frase[i],parola);
        i++;
        if( parola[strlen(parola)-1] == ','
                || parola[strlen(parola)-1] == '.'
                || parola[strlen(parola)-1] == '!'){
            //printf("%s\n", parola);
            int trovato = 0;
            for(j=0;j<i;j++){
                if(strcmp(frase[j],argv[1]) == 0)
                    trovato = 1;
            }
            if(trovato) {
                for (j = 0; j < i; j++) {
                    fprintf(fp, "%s ", frase[j]);
                }
            }
            i = 0;
            continue;
        }
    };*/
    fclose(fp);
    return 0;
}