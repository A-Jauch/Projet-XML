#include "validate.h"

void validateHeaderTag(){

    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";
    char *name1 = "classrooms.dtd";
    char *fileCode1 = "r+";

    char* stockFXML = malloc(sizeof(char) * (strlen(name)));
    char* stockTag = malloc(sizeof(char) * (strlen(name)));
    char* stockTagName = malloc(sizeof(char) * (strlen(name)));
    char* stockLXML = malloc(sizeof(char) * (strlen(name)));
    char* stockDTD = malloc(sizeof(char) * (strlen(name)));
    char* wordFXML = malloc(sizeof(char) * (strlen(name)));
    char* wordLXML = malloc(sizeof(char) * (strlen(name)));
    char* String = malloc(sizeof(char) * (strlen(name)));



    strcpy(stockTag,searchLastString(f,'<',name));

    // search dtd first name in our case classrooms

    strcpy(stockTagName, removeFTag(f,stockTag,stockTag,name));
    strcpy(stockDTD,readFileX(f, name1, fileCode1,stockTagName));
    printf("wordDTD:%s", stockDTD);

   // to get the first tag name from the name that is present in dtd
   strcpy(String, getFirstTag(f,stockDTD, name));

    // to get the first tag and be able to compare after
   strcpy(stockFXML,readFileX(f, name, fileCode,String));
   printf("First XML Tag:%s", stockFXML);
    // same for the last tag
   strcpy(stockLXML,readFileX(f, name, fileCode,stockTag));
   printf("Last Xml Tag:%s", stockLXML);
    // get the name with xml tag removed (<classrooms> -> classrooms and same for the last one
   strcpy(wordFXML, removeFTag(f,stockFXML,stockFXML,name));
   strcpy(wordLXML, removeFTag(f,stockLXML,stockLXML,name));
   printf("\nWord From first: %s", wordFXML);
   printf("\nWord from last: %s", wordLXML);

        int t = strcmp(wordFXML,wordLXML);
                printf("\nT:%d", t);


        if( stockLXML[1] != 47  || t != 0){
        printf("\nErreur Syntaxe");

        } else {

        printf("\nOk");
        }

        if(strcmp(stockDTD,wordFXML) != 0 && strcmp(stockDTD,wordLXML) !=0){
                printf("\nErreur DTD");

        } else {

        printf("\nDTD:Ok");
        }


free(stockFXML);
free(stockLXML);
free(wordFXML);
free(wordLXML);
free(String);
free(stockDTD);
free(stockTag);
free(stockTagName);

}

void validateTag(){


    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";
    char *name1 = "classrooms.dtd";
    char *fileCode1 = "r+";
    char* stockTag = malloc(sizeof(char) * (strlen(name)));
    char* String = malloc(sizeof(char) * (strlen(name)));

    strcpy(stockTag,searchLastString(f,' ',name1));
    //printf("++:%s", stockTag);
    strcpy(String,removeFTag(f,stockTag,stockTag,name1));

    //printf("+:%s", String);

    readFileX(f,name1,"r",String);
    char test[3] = " ";
    int size = strlen(String);
    char* result = malloc(sizeof(char) * (strlen(name)));

    printf("size:%d",size);

    for(int i = 0;  i<strlen(String) ;i++){
        if(result[size-10] != test[0]){
        result[i] = String[i];
        }

    }

    char* stockTagName = malloc(sizeof(char) * (strlen(name)));
    char* Cont = malloc(sizeof(char) * (strlen(name)));
    for(int j = 0;  j<size-10 ;j++){

        stockTagName[j] = result[j];
        }

    strcpy(Cont, "<");
    strcat(Cont, stockTagName);
   //strcat(stockTagName, "+");

    strcat(Cont, ">");
    printf("\nR:%s",stockTagName);
    readFileX(f,name1,"r",stockTagName);
    readFileX(f,name,"r",Cont);

}
