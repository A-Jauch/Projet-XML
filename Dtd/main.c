#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openFile(FILE * f,char *name, char *code);

int main(){

    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";

    openFile(f, name, fileCode);

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
            printf("%s", test);
            //printf("%ld", ftell(f));

        }

    }else{

        printf("Fichier non ouvert");

    }

}
