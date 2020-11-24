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

            return result;
        }

    }
    free(String);
    free(cursor);
    free(search);

}

// This one get the last xml Tag of the document

char* searchLastString(FILE * f, int word, char *name){
      f = fopen(name, "r");

    char * s = malloc(sizeof(char) * (strlen(name)));
    char *cursor = malloc(sizeof(char) * (strlen(name)));
    char * result = malloc(sizeof(char) * (strlen(name)));

        while (fgets(result, strlen(name)*5, f), !feof(f)){

            cursor = strchr(result, word);

            if(cursor != NULL){
            strcpy(s, cursor);
            }
        }

    return s;
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

            //printf("Find:%s", s);

            }
        }

    return s;

}

int countXmlTag(FILE * f, char *word, char *name){
    int i=0;
    char *cursor = malloc(sizeof(char) * (strlen(name)));
    char * result = malloc(sizeof(char) * (strlen(name)));
    char * s = malloc(sizeof(char) * (strlen(name)));

        while (fgets(result, strlen(name)*5, f), !feof(f)){

            cursor = strstr(result, word);
            if(cursor != NULL){
            i=i+1;
            strcpy(s, cursor);

            printf("Find:%s", s);
            }
        }

    return i;

}


// This one removed the <> and </> from an XML Tag

char* removeFTag(FILE * f,  char*word,char*name){
    f = fopen(name, "r");

    char * result = malloc(sizeof(char) * (strlen(word)));
    char *firstTag = malloc(sizeof(char) * (strlen(word)));

    strcpy(firstTag,saveString(f,word,name));
    rewind(f);
    int size = strlen(word);
    char*p = "/";

    if(firstTag[1] == p[0]){
        for(int i = 2; i < size-2 ; i++){
            result[i-2] = firstTag[i];
            }

            return result;

    } else {
        for(int i = 1; i < size-2 ; i++){
            result[i-1] = firstTag[i];
            }
            return result;

    }

    free(firstTag);
}


char* removeTag(char*word){

    char * result = malloc(sizeof(char) * (strlen(word)));

    int size = strlen(word);
    char*p = "/";

    if(word[1] == p[0]){
        for(int i = 2; i < size-1 ; i++){
            result[i-2] = word[i];
            }

            return result;

    } else {
        for(int i = 1; i < size-1 ; i++){
            result[i-1] = word[i];
            }
            return result;

    }

    free(word);
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
        printf("Find:%s in %s\n",firstTag, name);

        //printf("\nSearch:%s\n", result);

        return result;

    }else{

        printf("Fichier non ouvert\n");

    }

//    fclose(f);

}
