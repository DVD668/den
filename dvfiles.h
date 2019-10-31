#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef DVFILES_H_INCLUDED
#define DVFILES_H_INCLUDED

//loads the file on memory
char* readfile(char*);

//gets the size of the file
int getfilesize(char*);

//writes char array to file
void writefile(char*,char*,int);

//checks if the file exists
void existfile(char*);

#endif // DVFILES_H_INCLUDED
