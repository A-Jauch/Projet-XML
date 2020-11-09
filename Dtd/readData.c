#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function permit to get the name of the First xml tag in the document

char* getFirstTag(FILE * f, char* TagName, char* name){

    f = fopen(name, "r");

    char * String = malloc(sizeof(char) * (strlen(name)));
    char * search = malloc(sizeof(char) * (strlen(name)));
    char *cursor = malloc(sizeof(char) * (strlen(name)));
    char * result = malloc(sizeof(char) * (strlen(name)));

    strcpy(String, "<");
    strcat(String, TagName);
    strcat(String, ">");

    while (fgets(result, strlen(name)*5, f), !feof(f)){

        if( strncmp(result,String,strlen(TagName)) == 0){

            printf("Search:%s",result);
            return result;
        }

    }

}

// This one get the last xml Tag of the document

char* searchLastString(FILE * f, int word, char *name){
      f = fopen(name, "r");

    char * s = malloc(sizeof(char) * (strlen(name)));
    char *cursor = malloc(sizeof(char) * (strlen(name)));
    char * result = malloc(sizeof(char) * (strlen(name)));

        while (fgets(result, strlen(name)*5, f), !feof(f)){

            cursor = strchr(result, word);
            //printf("C:%s", cursor);

            if(cursor != NULL){
            strcpy(s, cursor);
           // printf("\n S:%s", s);
            }
        }

    return s;
    free(s);
    free(cursor);
    free(result);
}

// This function  save the XML String with tag used in : readFileX
char* saveString(FILE * f, char *word, char *name){

    char * s = malloc(sizeof(char) * (strlen(name)));
    char *cursor = malloc(sizeof(char) * (strlen(name)));
    char * result = malloc(sizeof(char) * (strlen(name)));

        while (fgets(result, strlen(name)*5, f), !feof(f)){

            cursor = strstr(result, word);
            if(cursor != NULL){
            strcpy(s, cursor);
            }
        }

    return s;
    free(s);
    free(cursor);
    free(result);
}


// This one removed the <> and </> from an XML Tag

char* removeFTag(FILE * f, char*xmlString, char*word,char*name){
    f = fopen(name, "r");

char * result = malloc(sizeof(char) * (strlen(word)));
char *firstTag = malloc(sizeof(char) * (strlen(word)));

    strcpy(firstTag,saveString(f,word,name));
    rewind(f);
    char*p = "/";

    if(firstTag[1] == p[0]){
        for(int i = 2; i < strlen(word)-2 ; i++){
            result[i-2] = firstTag[i];
            }
            return result;

    } else {
        for(int i = 1; i < strlen(word)-2 ; i++){
            result[i-1] = firstTag[i];
            }
            return result;

    }

    free(result);
    free(firstTag);
}

// this one return tag name and verify if the tag exist in the file

char* readFileX(FILE * f,char *name, char *code, char*word){


    f = fopen(name, code);
    char * result = malloc(sizeof(char) * (strlen(name)));
    char * result1 = malloc(sizeof(char) * (strlen(name)));
    char *firstTag = malloc(sizeof(char) * (strlen(name)));

    if(f != NULL){

        strcpy(firstTag,saveString(f,word,name));
        rewind(f);

          for(int i = 0; i < strlen(word) ; i++){
            result[i] = firstTag[i];
            }
        printf("\nFind F: %s in %s",firstTag, name);

        //printf("\n%c",firstTag[10]);
       // printf("\nRS:%s in %s",result,name);
        printf("\ntt:%s\n", result);
      //  printf("\nttR:%s\n", result1);

        return result;

    }else{

        printf("Fichier non ouvert\n");

    }

//    fclose(f);

}
