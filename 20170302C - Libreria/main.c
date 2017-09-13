#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SURL 25
#define TITL 50

int main(int argc, char* argv[]) {
    // -- boilerplate starts here
    if(argc != 4) {
        printf("ERRORE: Necessari tre argomenti.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("ERRORE: Non posso aprire il file\"%s\".\n", argv[1]);
        return 1;
    }
    int i;
    if(argv[2][0] != '-' || strlen(argv[2]) != 2) {
        printf("ERRORE: Opzione sconosciuta \"%s\".\n", argv[2]);
        return 1;
    }
    // -- boilerplate ends here
    int year;
    int pages;
    char surname[SURL+1];
    char title[TITL+1];
    int totalpages=0;
    int counter=0;
    switch(argv[2][1]) {
        case 'p':
        case 'P':
            //filter_by_year(input, atoi(argv[3]));
            while(fscanf(fp,"%d%s%s%d",&year, surname, title, &pages) != EOF){
                if(year < 1966 ){
                    printf("Wrong Year Format");
                    return 1;
                }
                if(pages > 9999){
                    printf("Wrong Number of pages");
                    return 1;
                }
                if(year == atoi(argv[3])){
                    printf("%d %s %s %d\n", year, surname, title, pages);
                    ++counter;
                    totalpages += pages;
                }
            }
            if(counter == 0)
                printf("Non esistono libri pubblicati quell anno\n");
            else
                printf("Lunghezza media: %d pagine\n", totalpages/counter);
            break;
        case 't':
        case 'T':
            //find_title(input, argv[3]);
            while(fscanf(fp,"%d%s%s%d",&year, surname, title, &pages) != EOF) {
                if (year < 1966) {
                    printf("Wrong Year Format");
                    return 1;
                }
                if (pages > 9999) {
                    printf("Wrong Number of pages");
                    return 1;
                }
                if( strcmp(title,argv[3]) == 0 ){
                    printf("%d %s \n", year, surname);
                    ++counter;
                }
            }
            if(counter == 0)
                printf("Non esistono libri con quel titolo.\n");
            break;
        default:
            printf("ERROR: Unknown option \"-%c\".\n", argv[2][1]);
            exit(EXIT_FAILURE);
    }


    return 0;
}