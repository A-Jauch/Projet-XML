#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void openFile(FILE * f,char *name, char *code);
void readFile(FILE * f,char *name, char *code);
int countOccurence(char *buffer, char *word);

int main(){

    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";
    char *name1 = "classrooms.dtd";
    char *fileCode1 = "r+";
    char * word = "<classroom>";

    int test = fseek(f, 0, SEEK_END);

    char * size = malloc(sizeof(char) * test);

    readFile(f, name, fileCode);
    readFile(f, name1, fileCode1);
    int count = countOccurence(size , word);

    printf("%d aaa", count);

    return 0;
}

void openFile(FILE * f,char *name, char *code){

    f = fopen(name, code);
    char * result = malloc(sizeof(char) * (strlen(name)*10));

    char *test = malloc(sizeof(char) * (strlen(name)*10));

    if(f != NULL){

        printf("Fichier ouvert\n");

        while (fgets(result, strlen(name)*10, f), !feof(f)){

            test = strchr(result, '<');
            //printf("%s", test);
            //printf("%ld", ftell(f));

        }
    }else{

        printf("Fichier non ouvert");

    }

    fclose(f);

}

void readFile(FILE * f,char *name, char *code){

    openFile(f, name, code);
    f = fopen(name, code);

    char * result = malloc(sizeof(char) * (strlen(name)));

    char * result1 = malloc(sizeof(char) * (strlen(name)*10));

    char *test = malloc(sizeof(char) * (strlen(name)));

    char * mot = "classroom";

    if(f != NULL){

        while (fgets(result, strlen(name)*5, f), !feof(f)){

            test = strstr(result, mot);
            if(test != NULL){

                printf("%s\n", test);
                strcpy(result, test); 

            }

        }

    }else{

        printf("Fichier non ouvert\n");

    }

    fclose(f);

}

int countOccurence(char *buffer, char *word){
    char *pos;
    char str[BUFFER_SIZE];
    int index, count;
    count = 0;
    while((pos = strstr(str, word)) != NULL){
        pos += strlen(word);
        count++;
    }
    return count;
}