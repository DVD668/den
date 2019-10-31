#include "libdvflags.h"



int requireflag(char** arguments, int argument_count, char* flag){

    for(int counter = 1; counter < argument_count; counter++){

        //if the flag is found
        if(!strcmp(arguments[counter],flag)){

            //returns 1
            return 1;
        }

    }

    //if the flag doesn't exist returns 0
    return 0;

}

char* requireflagarg(char** arguments, int argument_count, char* flag){


    for(int counter = 1; counter < argument_count; counter++){

        //if a mach is found
        if(!strcmp(arguments[counter],flag)){

            //if the argument is accessible
            if((counter < argument_count -1 ) && arguments[counter + 1][0] != '-' ){

                //the argument is returned
                return arguments[counter + 1];

            }else{  //otherwise

                //prints an error message
                printf("Error: Flag \"%s\" used, but no argument specyfied\n",arguments[counter]);

                //exits with error code
                exit(-1);

            }

        }

    }

    //if the flag doesn't exist returns 0
    return 0;

}
