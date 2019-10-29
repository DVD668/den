#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdvden.h"
#include "dvfiles.h"

//main function
int main(int arnum, char* args[]){

    //if there aren't enough arguments it returns an error message
    if(arnum<4){
        printf("not enough arguments!\nusage: \nden <path_to_file> -<\"e\"/\"d\"> <key>\nor\n<path_to_file> -<\"fe\"/\"fd\"> <path_to_keyfile>\n");
        return 0;
    }

    //gets file content and lenght
    int textlen = 0;
    char* text = load(args[1],&textlen);

    //encrypts or decrypts the file with in-line argument
    if (!strcmp(args[2],"-e")){
        dvdencrypt(text,args[3],textlen,strlen(args[3]));
    }else if(!strcmp(args[2],"-d")){
        dvddecrypt(text,args[3],textlen,strlen(args[3]));
    }else{

        //loads the keyfile
        int keyl = 0;
        char* keyfile = load(args[3],&keyl);


        //encrypts or decrypts the file by using the loaded keyfile
        if(!strcmp(args[2],"-fe")){
        //encrypts with keyfile
        dvdencrypt(text,keyfile,textlen,keyl);
        }else if(!strcmp(args[2],"-fd")){
        //decrypts with keyfile
        dvddecrypt(text,keyfile,textlen,keyl);
        }
    }
    //writes the file back
    writefile(args[1],text,textlen);

    return 0;
}
