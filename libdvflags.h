#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LIBDVFLAGS_H_INCLUDED
#define LIBDVFLAGS_H_INCLUDED



//checks if the required flags exists
int requireflag(char**,int,char*);

//gets one flag's argumen
char* requireflagarg(char**,int,char*);

//prints the flag that is used between the two alternatives
char* chooseflag(char**,int,char*,char*);



#endif // LIBDVFLAGS_H_INCLUDED
