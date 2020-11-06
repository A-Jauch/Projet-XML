#ifndef READDATA_H_INCLUDED
#define READDATA_H_INCLUDED



void openFile(FILE * f,char *name, char *code);
char* readFileX(FILE * f,char *name, char *code, char*word);
char* readFileD(FILE * f,char *name, char *code, char*word);
char* saveString(FILE * f,  char *word, char *name);
char* removeFTag(FILE * f, char*xmlString, char* word,char* name);

#endif // READDATA_H_INCLUDED
