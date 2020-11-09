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
    char* stockTag = malloc(sizeof(char) * (strlen(name)));
    char* stockTagName = malloc(sizeof(char) * (strlen(name)));
    char* stockXML1 = malloc(sizeof(char) * (strlen(name)));
    char* stockDTD = malloc(sizeof(char) * (strlen(name)));
    char* stockXML2 = malloc(sizeof(char) * (strlen(name)));
    char* stockXML3 = malloc(sizeof(char) * (strlen(name)));
    char* String = malloc(sizeof(char) * (strlen(name)));



    strcpy(stockTag,searchLastString(f,'<',name));

    // search dtd first name in our case classrooms

    strcpy(stockTagName, removeFTag(f,stockTag,stockTag,name));
    strcpy(stockDTD,readFileX(f, name1, fileCode1,stockTagName));
    printf("stocKD:%s", stockDTD);

   // to get the first tag name from the name that is present in dtd
   strcpy(String, getFirstTag(f,stockDTD, name));

    // to get the first tag and be able to compare after
   strcpy(stockXML,readFileX(f, name, fileCode,String));
   printf("stockX:%s", stockXML);
    // same for the last tag
   strcpy(stockXML1,readFileX(f, name, fileCode,stockTag));
   printf("stockX1:%s", stockXML1);
    // get the name with xml tag removed (<classrooms> -> classrooms and same for the last one
   strcpy(stockXML2, removeFTag(f,stockXML,stockXML,name));
   strcpy(stockXML3, removeFTag(f,stockXML1,stockXML1,name));
   printf("\nstocK22:%s", stockXML2);
   printf("\nstocK33:%s", stockXML3);



        int t = strcmp(stockXML2,stockXML3);
                printf("\nT:%d", t);


        if( stockXML1[1] != 47  || t != 0){
        printf("\nErreur Syntaxe");

        } else {

        printf("\nOk");
        }

        if(strcmp(stockDTD,stockXML2) != 0 && strcmp(stockDTD,stockXML3) !=0){
                printf("\nErreur DTD");

        } else {

        printf("\nDTD:Ok");
        }



free(stockXML);
free(stockXML1);
free(stockXML2);
free(stockXML3);
free(String);
free(stockDTD);
free(stockTag);
free(stockTagName);

    return 0;
}


