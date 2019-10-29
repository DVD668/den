#include <stdio.h>
#include <stdlib.h>


//loads the file on memory
char* load(char* fname,int* fsize){
    //opens the file
    FILE *fl;
    fl = fopen(fname,"rb");

    //gets the lenght of the file
    fseek(fl,0,SEEK_END);
    *fsize = ftell(fl);
    rewind(fl);

    //gets all the necessary memory
    char* content = malloc(*fsize);

    //reads the file and returns its content
    fread(content,*fsize,1,fl);
    return content;

    //closes the file
    fclose(fl);

}


//writes char array to file
void writefile(char* filename,char* content, int contentlen){
    //opens the file
    FILE *fl;
    fl = fopen(filename,"wb");

    //writes the content
    rewind(fl);
    fwrite(content,contentlen,1,fl);
    fclose(fl);

}
