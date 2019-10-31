
//defines the help message macro
#define HELP_MESSAGE "This is a very long and boring help message"

#include "libdvden.h"
#include "dvfiles.h"
#include "libdvflags.h"

//main function
int main(int arn, char* ar[]){

    //checks for the help flag
    if( requireflag(ar,arn,"--help") || requireflag(ar,arn,"-h") ){

        printf(HELP_MESSAGE);
        return 0;

    }
    return 0;
}
