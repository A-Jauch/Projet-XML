#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void openFile(FILE * f,char *name, char *code);
void readFile(FILE * f,char *name, char *code);

int main(){

    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";
    char *name1 = "classrooms.dtd";
    char *fileCode1 = "r+";

    readFile(f, name, fileCode);
    readFile(f, name1, fileCode1);

    return 0;
}

void openFile(FILE * f,char *name, char *code){

    f = fopen(name, code);
    char * result = malloc(sizeof(char) * (strlen(name)*10));

    char *test = malloc(sizeof(char) * (strlen(name)*10));

    char * mot = "<classroom>";

    if(f != NULL){

        printf("Fichier ouvert\n");

        while (fgets(result, strlen(name)*10, f), !feof(f)){

            test = strchr(result, '<');
            //printf("%s", test);

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

    char * mot = "<classrooms>";

    if(f != NULL){

        while (fgets(result, strlen(name)*5, f), !feof(f)){

            test = strstr(result, mot);
            printf("%s", test);
            //strcpy(result, test);
            
                        

        }

    }else{

        printf("Fichier non ouvert\n");

    }

    fclose(f);

}