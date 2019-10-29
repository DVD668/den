#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdvden.h"
#include "dvfiles.h"
#include "libdvflags.h"

//main function
int main(int arn, char* ar[]){

    if(checkval(ar,arn,"--lampreda")){
        printf("found argument %s\n",getflagval(ar,arn,"--lampreda"));
    }else{
        printf("nothing\n");
    }

    return 0;
}
