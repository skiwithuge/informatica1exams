#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Per ogni lettera dell’alfabeto il numero di parole del testo che hanno quella lettera come iniziale
//L’iniziale con maggior numero di parole nel testo. Pari Merito <- ultima in ordine alfabetico
//numero di frasi contenute nel testo
//. , ; ? !
//La lunghezza massima di una frase
//ogni parola nel file abbia una lunghezza massima di 20 caratteri
//testo sia contenuto su un’unica riga priva di caratteri di invio e terminata da un punto
//il testo non contenga lettere accentate
#define L 20
int main(int argc, char *argv[]) {
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL)
        return 1;
    char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int freq[26] = { 0 };
    char parola[L+1];
    int max_sentence_length = 0;
    int sentence_length = 0;
    int number_of_sentences = 0;
    while( fscanf(fp,"%s", parola) != EOF){
        int letter = tolower(parola[0]) - 97;
        ++freq[letter];
        sentence_length += strlen(parola);

        switch(parola[strlen(parola)-1]) {
            case '.':
            case ',':
            case ';':
            case '?':
            case '!':
                number_of_sentences++;
                if(sentence_length > max_sentence_length)
                    max_sentence_length = sentence_length -1; //tolgo l'ultimo carattere
                sentence_length = 0;
            default:
                ;
        }
    }
    fclose(fp);
    int i;
    for(i=0;i<26;++i)
        printf("%c:%d ", alphabet[i],freq[i]);
    printf("\n");
    int max = freq[0];
    char maxletter = alphabet[0];
    for(i=1;i<26;i++){
        if(freq[i] >= max){
            maxletter = alphabet[i];
            max = freq[i];
        }
    }
    printf("Iniziale con maggior numero di parole: %c \n", maxletter);
    printf("Numero di frasi nel testo: %d\n", number_of_sentences);
    printf("Lunghezza massima di una frase: %d\n", max_sentence_length);
    return 0;
}