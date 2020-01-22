#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef DVFILES_H_INCLUDED
#define DVFILES_H_INCLUDED

//loads the file on memory
char* readfile(char*);

//loads part of a file on memory
char* readfilepart(char*,long int,int);

//gets the size of the file
long int getfilesize(char*);

//writes char array to file
void writefile(char*,char*,int);

//appends char array to a file
void appendfile(char*,char*,int);

//checks if the file exists
void existfile(char*);

#endif // DVFILES_H_INCLUDED
