#include "validate.h"

    FILE *f;
    char *name = "exemple.xml";
    char *fileCode = "r+";
    char *name1 = "classrooms.dtd";
    char *fileCode1 = "r+";

void validateHeaderTag(){



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

    strcpy(stockTagName, removeFTag(f,stockTag,name));
    strcpy(stockDTD,readFileX(f, name1, fileCode1,stockTagName));
    printf("wordDTD:%s\n", stockDTD);

   // to get the first tag name from the name that is present in dtd
   strcpy(String, getFirstTag(f,stockDTD, name));

    // to get the first tag and be able to compare after
   strcpy(stockFXML,readFileX(f, name, fileCode,String));
    // same for the last tag
   strcpy(stockLXML,readFileX(f, name, fileCode,stockTag));
   printf("First XML Tag:%s", stockFXML);

   printf("Last Xml Tag:%s", stockLXML);
    // get the name with xml tag removed (<classrooms> -> classrooms and same for the last one
   strcpy(wordFXML, removeFTag(f,stockFXML,name));
   strcpy(wordLXML, removeFTag(f,stockLXML,name));
   printf("\nWord From first: %s", wordFXML);
   printf("\nWord from last: %s", wordLXML);

        int t = strcmp(wordFXML,wordLXML);

        if( stockLXML[1] != 47  || t != 0){
        printf("\nSyntax Error");

        } else {

        printf("\nSyntax:Ok");
        }

        if(strcmp(stockDTD,wordFXML) != 0 && strcmp(stockDTD,wordLXML) !=0){
                printf("\nErreur DTD");

        } else {

        printf("\nDTD:Ok\n");
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

char* validateTag(){

    char* stockTag = malloc(sizeof(char) * (strlen(name)));
    char* String = malloc(sizeof(char) * (strlen(name)));

    strcpy(stockTag,searchLastString(f,' ',name1));
    //printf("++:%s", stockTag);
    strcpy(String,removeFTag(f,stockTag,name1));

    //printf("+:%s", String);

    readFileX(f,name1,"r",String);
    char test[3] = " ";
    int size = strlen(String);
    char* result = malloc(sizeof(char) * (strlen(name)));

    for(int i = 0;  i<size ;i++){
        if(result[size-10] != test[0]){
        result[i] = String[i];
        }

    }

    char* stockTagName = malloc(sizeof(char) * (strlen(name)));
    char* firstTag = malloc(sizeof(char) * (strlen(name)));
    char* lastTag = malloc(sizeof(char) * (strlen(name)));

    for(int j = 0;  j<size-10 ;j++){

        stockTagName[j] = result[j];
        }


    strcpy(firstTag, "<");
    strcpy(lastTag, "<");
    strcat(lastTag,"/");
    strcat(firstTag, stockTagName);
    strcat(lastTag, stockTagName);
   // strcat(stockTagName, "+");

    strcat(firstTag, ">");
    strcat(lastTag, ">");

    readFileX(f,name1,"r",stockTagName);
    char* tagFXML = malloc(sizeof(char) * (strlen(name)));
    char* tagLXML = malloc(sizeof(char) * (strlen(name)));

    strcpy(tagFXML,readFileX(f,name,"r",firstTag));
    strcpy(tagLXML,readFileX(f,name,"r",lastTag));


    char* wordFXML = malloc(sizeof(char) * (strlen(name)));
    char* wordLXML = malloc(sizeof(char) * (strlen(name)));

    strcpy(wordFXML, removeTag(tagFXML));
    strcpy(wordLXML, removeTag(tagLXML));

     int t = strcmp(wordFXML,wordLXML);


        if( tagLXML[1] != 47  || t != 0){
        printf("\nErreur Syntaxe");
        }

        free(wordFXML);
        free(wordLXML);
        free(tagFXML);
        free(tagLXML);

        return stockTagName;

}

void validateDtdOperand(){

    char* StringOperand = malloc(sizeof(char) * (strlen(name)));
    char* TagName = malloc(sizeof(char) * (strlen(name)));
    f = fopen(name, "r");


    strcpy(StringOperand,validateTag());
    strcat(StringOperand, "+");
    readFileX(f,name1,"r",StringOperand);

    strcpy(TagName,"<");
    strcat(TagName,validateTag());
    strcat(TagName,">");

    if(strcmp(StringOperand,strcat(validateTag(),"+")) == 0){
    int i = countXmlTag(f,TagName,name);
    printf("Number of Tag:%d",i);
    }
}
