#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readData.h"


int main(){

    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";
    char *name1 = "classrooms.dtd";
    char *fileCode1 = "r+";
    char* stockXML = malloc(sizeof(char) * (strlen(name)));
    char* stockXML1 = malloc(sizeof(char) * (strlen(name)));
    char* stockDTD = malloc(sizeof(char) * (strlen(name)));


   strcpy(stockXML,readFileX(f, name, fileCode,"<classrooms>"));
   strcpy(stockXML1,readFileX(f, name, fileCode,"</classrooms>"));
   printf("stockX:%s", stockXML);
   printf("stockX1:%s", stockXML1);
   strcpy(stockDTD,readFileX(f, name1, fileCode1,"classrooms"));
   printf("stocKD:%s", stockDTD);
   saveString(f,stockXML,name);

        int x = strcmp(stockXML, stockXML1);
        if(x != 52){
        printf("Erreur Syntaxe");

        } else {

        printf("\nOk");
        }

    return 0;
}

