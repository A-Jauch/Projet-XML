#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
