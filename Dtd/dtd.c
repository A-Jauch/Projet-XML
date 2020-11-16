#define DIM 10000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
char* controlDTD(char* word, FILE* f){

    f = fopen("classroom.dtd", "r");
    char* verifWord = "classroom+";
    char* tab[DIM];
    char* result = "Error DTD";

    while(strcat(word,"+") != verifWord){

        fread(tab,sizeof(char*),DIM,f);
        if(strcat(word,"+") != verifWord){

            result = "DTD compliant";

        }

    }
	printf("%s",result);
    return result;

}
}
