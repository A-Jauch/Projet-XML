#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void openFile (FILE * f,char* name, char* code);

void openFile (FILE * f,char* name, char* code){

    f = fopen(name, code);

    if( f != NULL ){

        printf("Fichier ouvert\n");
        fclose(f);

    } else {
        printf("Fichier non ouvert");
        fclose(f);

    }


}



int main(int argc, char * argv[])
{
    FILE * fp;
    char * fileName = "exemple.xml";
    char * fileCode = "r";

    openFile(fp, fileName , fileCode );
    return 0;
}
