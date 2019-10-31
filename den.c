
//defines the help message macro
#define HELP_MESSAGE "Usage: den [options] file\nOptions:\n   -dwf, --decrypt-with-file <key_file>\t\tDecrypts the file by using another file as a key\n   -dwp, --decrypt-with-password <password>\tDecrypts the file by using an user-specified password\n   -ewf, --encrypt-with-file <key_file>\t\tEncrypts the file by using another file as a key\n   -ewp, --encrypt-with-password <password>\tEncrypts the file by using an user-specified password\n   -h, --help\t\t\t\t\tPrints this message on the screen and exits\n   -o, --output <output_file>\t\t\tSelects the name of the output file\n"

#include "libdvden.h"
#include "dvfiles.h"
#include "libdvflags.h"

//main function
int main(int arn, char* ar[]){



    //if the arguments are less than 4
    if(arn < 2){

        //prints error message
        printf("Error: No arguments specified\n");
        exit(-1);

    }



    //checks for the help flag
    if( requireflag(ar,arn,"--help") || requireflag(ar,arn,"-h") ){

        //prints the program's help message
        printf(HELP_MESSAGE);
        return 0;

    }



    //gets the input file name from the last argument
    char* input_file_name = ar[arn-1];

    //opens the file
    char* file_content = readfile(input_file_name);

    //declares a char pointer containing the user-specified flags
    char* used_flag;

    //declares a pointer to the key
    char* key;

    //declares the key's size
    int key_size;

    //gets the file size
    int file_size = getfilesize(input_file_name);



    if( requireflag(ar,arn,"--encrypt-with-password") || requireflag(ar,arn,"-ewp") ){ //encrypting with password

        //tells wich particular flag has been used
        used_flag = chooseflag(ar,arn,"--encrypt-with-password","-ewp");

        //gets the encryption key
        key = requireflagarg(ar,arn,used_flag);

        //gest the key's size
        key_size = strlen(key);

        //encrypts the buffer
        dvdencrypt(file_content,key,file_size,strlen(key));

    }else if( requireflag(ar,arn,"--encrypt-with-file") || requireflag(ar,arn,"-ewf") ){ //encrypting with file

        //tells wich particular flag has been used
        used_flag = chooseflag(ar,arn,"--encrypt-with-file","-ewf");

        //the keyfile's name is stored
        char* keyfile_name = requireflagarg(ar,arn,used_flag);

        //gets the encryption key from the specified file
        key = readfile(keyfile_name);

        //gest the key's size
        key_size = getfilesize(keyfile_name);

        //encrypts the buffer
        dvdencrypt(file_content,key,file_size,key_size);

    }else if( requireflag(ar,arn,"--decrypt-with-password") || requireflag(ar,arn,"-dwp") ){//decrypting with password

        //tells wich particular flag has been used
        used_flag = chooseflag(ar,arn,"--decrypt-with-password","-dwp");

        //gets the encryption key
        key = requireflagarg(ar,arn,used_flag);

        //gest the key's size
        key_size = strlen(key);

        //decrypts the buffer
        dvddecrypt(file_content,key,file_size,strlen(key));

    }else if( requireflag(ar,arn,"--decrypt-with-file") || requireflag(ar,arn,"-dwf") ){//encrypting with file

        //tells wich particular flag has been used
        used_flag = chooseflag(ar,arn,"--decrypt-with-file","-dwf");

        //the keyfile's name is stored
        char* keyfile_name = requireflagarg(ar,arn,used_flag);

        //gets the encryption key from the specified file
        key = readfile(keyfile_name);

        //gest the key's size
        key_size = getfilesize(keyfile_name);

        //decrypts the buffer
        dvddecrypt(file_content,key,file_size,key_size);

    }else{

        //returns error message
        printf("Error: No encryption arguments specified\n");
        exit(-1);
    }

    if( requireflag(ar,arn,"--output") || requireflag(ar,arn,"-o") ){   //if an output file is specified

        //tells wich particular flag has been used
        used_flag = chooseflag(ar,arn,"--output","-o");

        //writes on the output file
        writefile(requireflagarg(ar,arn,used_flag),file_content,file_size);

    }else{  //otherwise writes on the input file

        //writes the file
        writefile(input_file_name,file_content,file_size);

    }

    return 0;
}
