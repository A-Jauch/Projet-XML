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
    char* stockXML2 = malloc(sizeof(char) * (strlen(name)));
    char* stockXML3 = malloc(sizeof(char) * (strlen(name)));


   strcpy(stockXML,readFileX(f, name, fileCode,"<classrooms>"));
   strcpy(stockXML1,readFileX(f, name, fileCode,"</classrooms>"));
   printf("stockX:%s", stockXML);
   printf("stockX1:%s", stockXML1);
   strcpy(stockDTD,readFileX(f, name1, fileCode1,"classrooms"));
   printf("stocKD:%s", stockDTD);
   strcpy(stockXML2, removeFTag(f,stockXML,stockXML,name));
   strcpy(stockXML3, removeFTag(f,stockXML1,stockXML1,name));
   printf("\nstocK22:%s", stockXML2);
   printf("\nstocK33:%s", stockXML3);

        int x = strcmp(stockXML, stockXML1);

        if(x != 52 ){
        printf("\nErreur Syntaxe");

        } else {

        printf("\nOk");
        }

        if(strcmp(stockDTD,stockXML2) != 0 && strcmp(stockDTD,stockXML3) !=0){
                printf("\nErreur DTD");


        }

free(stockXML);
free(stockXML1);
free(stockXML2);
free(stockXML3);
free(stockDTD);

    return 0;
}


