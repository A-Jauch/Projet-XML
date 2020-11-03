#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void openFile(FILE * f,char *name, char *code);
void readFile(FILE * f,char *name, char *code);
char* saveString(FILE * f,  char *word, char *name);


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

 //   fclose(f);

}

void readFile(FILE * f,char *name, char *code){

    openFile(f, name, code);
    f = fopen(name, code);

    char * result = malloc(sizeof(char) * (strlen(name)));

    char * result1 = malloc(sizeof(char) * (strlen(name)));

    char *firstTag = malloc(sizeof(char) * (strlen(name)));
    char *lastTag = malloc(sizeof(char) * (strlen(name)));


    char * mot = "<classrooms>";
    char * word = "</classrooms>";
   // char * word1 = "classrooms";


    if(f != NULL){


        strcpy(firstTag,saveString(f,mot,name));
        rewind(f);
        strcpy(lastTag ,saveString(f,word,name));

          for(int i = 0; i < strlen(mot)-2 ; i++){

        result[i] = firstTag[i+1];
        }

        printf("\nFind: %s in %s",firstTag, name);
        printf("\nFind:%s in %s",lastTag,name);
        printf("\n%c",firstTag[10]);
       // printf("\nRS:%s in %s",result,name);


        printf("\ntt:%s", result);
        int x = strcmp(firstTag, lastTag);
        printf("\nX%d",x);
        if(x != 52){

        printf("Erreur Syntaxe");

        }



    }else{

        printf("Fichier non ouvert\n");

    }

//    fclose(f);

}


char* saveString(FILE * f, char *word, char *name){

    char * s = malloc(sizeof(char) * (strlen(name)));
    char *cursor = malloc(sizeof(char) * (strlen(name)));
    char * result = malloc(sizeof(char) * (strlen(name)));


        while (fgets(result, strlen(name)*5, f), !feof(f)){

            //printf("\n R:%s", result);
           // printf("\n S:%s", s);
          //  printf("\n C:%s", cursor);
            cursor = strstr(result, word);
            if(cursor != NULL){
           // printf("C:%s", cursor);
            strcpy(s, cursor);
           // printf("\n S:%s", s);
            }
        }

    return s;
    free(s);
    free(cursor);
    free(result);


}
