#ifndef LIBDVFLAGS_H_INCLUDED
#define LIBDVFLAGS_H_INCLUDED



#include <stdio.h>
#include <string.h>



//checks if a flag is triggered
int checkflag(char**,int,char*);

//checks if the argument of a flag exists
int checkval(char**,int,char*);

//gets the argument of a flag
char* getflagval(char**,int,char*);



#endif // LIBDVFLAGS_H_INCLUDED
