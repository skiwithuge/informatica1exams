#include <stdio.h>

typedef struct nodo{
    int year;
    char quad[3];
    float vht;
}NODO;

int main(int argc, char* argv[]) {
    FILE* fp=fopen(argv[1], "r");
    if(fp==NULL){
        printf("ERRORE");
        return 1;
    }
    float value;
    int num;
    //scanf("%f%d",&value,&num);
    value=1.53;num=2;

    NODO lista[24] = {0};
    NODO element;
    int counter=0;
    int flag=0;
    while(fscanf(fp,"%d %s %f",&element.year,element.quad,&element.vht) != EOF){
        if(element.vht >= value){
            lista[counter] = element;
            counter++;
        }else{
            if(counter >= num){
                int i;
                for(i=0;i<counter;i++){
                    printf("%d %s %f\n", lista[i].year,lista[i].quad,lista[i].vht);
                }
                flag=1;
            }
            counter=0;
        }
    }
    if (flag==0)
        printf("Match not found\n");
    return 0;
}