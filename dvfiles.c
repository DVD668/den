#include "dvfiles.h"

//loads the file on memory
char* readfile(char* fname){

    //checks if the file exists
    existfile(fname);

    //opens the file
    FILE *fl;
    fl = fopen(fname,"rb");

    //gets the lenght of the file
    fseek(fl,0,SEEK_END);
    int fsize = ftell(fl);
    rewind(fl);

    //gets all the necessary memory
    char* content = malloc(fsize);

    //reads the file and returns its content
    fread(content,fsize,1,fl);

    //closes the file
    fclose(fl);

    //returns the file content
    return content;

}

//loads part of a file on memory
char* readfilepart(char* fname, long int start, int rsize){

    //checks if the file exists
    existfile(fname);

    //opens the file
    FILE *fl;
    fl = fopen(fname,"rb");

    //allocates the needed memory
    char* content = malloc(rsize);

    //goes to the needed point in the file
    fseek(fl,start,SEEK_SET);

    //reads the required part of the file
    fread(content,rsize,1,fl);

    //returns the required part of the file
    return content;
}

//gets the size of the file
long int getfilesize(char* fname){

    //checks if the file exists
    existfile(fname);

    //opens the file
    FILE *fl;
    fl = fopen(fname,"rb");

    //gets the lenght of the file
    fseek(fl,0,SEEK_END);
    int fsize = ftell(fl);

    //closes the file
    fclose(fl);

    //returns the file size
    return fsize;
}

//writes char string to file
void writefile(char* filename,char* content, int contentlen){

    //opens the file
    FILE *fl;
    fl = fopen(filename,"wb");

    //writes the content
    fwrite(content,contentlen,1,fl);

    //closes the file
    fclose(fl);

}

//appends char array to a file
void appendfile(char* filename,char* content,int contentlen){

    //opens the file
    FILE *fl;
    fl = fopen(filename,"ab");

    //appends the content
    fwrite(content,contentlen,1,fl);

    //closes the file
    fclose(fl);

}

//checks if the file exists
void existfile(char* fname){

    if(access(fname,F_OK)==-1){//if the file doesn't exist

               //prints error code
        printf("Error: The file \"%s\" doesn't exist or is unaccessible\n",fname);

        //exits with error
        exit(1);

    }
}
