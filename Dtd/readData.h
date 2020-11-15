#ifndef READDATA_H_INCLUDED
#define READDATA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void openFile(FILE * f,char *name, char *code);
char* readFileX(FILE * f,char *name, char *code, char*word);
char* saveString(FILE * f,  char *word, char *name);
char* searchLastString(FILE * f,  int word, char *name);
char* searchString(FILE * f,  int word, char *name);
char* removeFTag(FILE * f, char*xmlString, char* word,char* name);
char* getFirstTag(FILE * f, char* TagName, char* name);


#endif // READDATA_H_INCLUDED
