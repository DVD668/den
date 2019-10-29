#include "libdvflags.h"



//checks if a flag is triggered
int checkflag(char** arguments, int arnum,char* flag){

    //checks the flag among all the others
    for(int counter = 1; counter < arnum; counter++){

        //if it finds it, returns true
        if(!strcmp(arguments[counter],flag)) return 1;

    }

    //otherwise returns false
    return 0;
}

//checks if a flag is triggered
int checkval(char** arguments, int arnum,char* flag){

    //checks the flag among all the others
    for(int counter = 1; counter < arnum; counter++){

        //if it finds it
        if( !strcmp(arguments[counter],flag) && counter != arnum - 1 ){

            //if the first character in a "-" it assumes that it's a flag and returns false, otherwise true
            return arguments[counter+1][0] == '-'? 0 : 1 ;

        }
    }

    //otherwise returns false
    return 0;
}

//gets the argument of a flag
char* getflagval(char** arguments, int arnum, char* flag){

    //checks the flag among all the others
    for(int counter = 1; counter < arnum; counter++){

        //if it finds it, returns the argument after it
        if(!strcmp(arguments[counter],flag)) return arguments[counter+1];

    }
}
